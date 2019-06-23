import os
import json
import struct
from treelib import Node, Tree

class IOTeqDBBuilder():
    def __init__(self, configFile):
        with open(configFile, 'r') as f:
            jsonOutput = json.load(f)
            self.databaseTags = jsonOutput["database"]["tags"]

        self.IOTEQ_TAG_BYTE_SIZE = 28
        self.tree = Tree()
        self.constPtrChar = []
        self.constPtrTree = []
        self.tagList = []
        self.dataPtr = []

        self.currentTagAddress = 0x00

    def totalNumberOfTags(self):
        return len(self.tagList)

    def addTag(self, tag):
        self.tagList.append(tag)

    def addNameToCharPtr(self, name):
        charList = list(name)
        for char in charList:
            self.constPtrChar.append(ord(char))
        self.constPtrChar.append(0) # escape char for string

    def setRoot(self, rootName):
        rootTag = IOTeqTag(rootName, 0x00, len(rootName))
        self.tree.create_node(rootName, rootName, None, rootTag)
        self.tagList.append(rootTag)
        self.addNameToCharPtr(rootName)

    def addValueToDataPtr(self, tag):
        datatype = tag["datatype"]
        if (datatype == "Number"):
            value = tag["value"]
            ba = bytearray(struct.pack("<f", value)) 
            for b in ba:
                self.dataPtr.append(hex(b))
        # elif (datatype == "Text"):

    def createTree(self, tags, parent=None):
        for tag in tags:
            for i in range(tags[tag]["arraydim"]):

                # Naming function for tags with dimensions larger than 1
                if (tags[tag]["arraydim"] > 1):
                    tagName = tag + "[" + str(i) + "]"
                else:
                    tagName = tag  
                    
                # Add tag name in hex format to a list
                charIndex = len(self.constPtrChar)
                self.addNameToCharPtr(tagName)

                # Create tag an add to tagList
                newTag = IOTeqTag(tagName, charIndex, len(tagName)+1) # plus 1 for \0

                # Set the tags valueSize based on datatype
                # Numbers are 4 bytes (float) and Text are 40 characters long total
                if (tags[tag]["datatype"] != "Folder"):
                    if (tags[tag]["datatype"] == "Number"):
                        newTag.valueSize = 4
                    elif (tags[tag]["datatype"] == "Text"):
                        newTag.valueSize = 40

                    # Adding default value to dataPtr list
                    newTag.valuePtr = len(self.dataPtr)
                    self.addValueToDataPtr(tags[tag])
                    

                # Adding tag to tree and tag list
                self.tree.create_node(tagName, tagName, parent, newTag)
                self.tagList.append(newTag)

                # Recursion for tags that have children
                if (tags[tag]["datatype"] == "Folder"):
                    self.createTree(tags[tag]["children"], tagName)

    def setTagAddresses(self):
        for level in range(self.tree.depth()+1):
            for node in dict(filter(lambda elem: self.tree.level(elem[0]) == level, self.tree.nodes.items())):
                tag = self.tree.get_node(node).data
                tag.address = self.currentTagAddress
                self.currentTagAddress += self.IOTEQ_TAG_BYTE_SIZE

    def setTagParentChildrenPtrs(self):
        for node in self.tree.nodes:
            # tagIndex = None
            for tag in self.tagList:
                if (tag.tagName == node):
                    tagIndex = self.tagList.index(tag)
                    # Get IOTeq Tag
                    treeNode = self.tree.get_node(node)
                    self.tagList[tagIndex] = treeNode.data

                    # If node has a parent, i.e. not root
                    if (treeNode.is_root() != True):
                        # Get IOTeq Parent Tag
                        parentTag = self.tree.parent(node).data
                        # Set Parent Ptr of current tag
                        self.tagList[tagIndex].parentPtr = parentTag.address
                    
                    # If node has children
                    if (self.tree.get_node(node).is_leaf() != True):
                        childrenNodes = self.tree.children(node)
                        childrenNodes.sort(key=lambda x: x.data.address)
                        self.tagList[tagIndex].childPtr = childrenNodes[0].data.address
                        self.tagList[tagIndex].numOfChildren = len(childrenNodes)

    def createConstPtrTree(self):
        for tag in self.tagList:
            self.constPtrTree.extend(tag.getStruct())


    def build(self):
        self.setRoot("tags")
        self.createTree(ioteqDBBuilder.databaseTags, "tags")
        self.setTagAddresses()
        self.setTagParentChildrenPtrs()
        self.createConstPtrTree()

class IOTeqTag(object):
    def __init__(self, tagName, namePtr, nameSize, address=None):
        self.valuePtr = 0
        self.valueSize = 0
        self.namePtr = namePtr
        self.nameSize = nameSize
        self.parentPtr = 0
        self.childPtr = 0
        self.numOfChildren = 0
        self.tagName = tagName
        self.address = address
    
    def getStruct(self):
        return [self.valuePtr, self.valueSize, self.namePtr,
                self.nameSize, self.parentPtr, self.childPtr, self.numOfChildren]

class IOTeqFileBuilder():
    def __init__(self, fileName, dbBuilder):
        self.dbBuilder = dbBuilder
        self.file = fileName
        self.fd = open(self.file, "w+")

    def write(self, string):
        self.fd.write(string)

    
    def addIncludes(self):
        self.write("""
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                """)
    def addDefines(self):
        self.write(f"""
                    #define TOTAL_NUMBER_OF_TAGS          {self.dbBuilder.totalNumberOfTags()}
                    """)
    def addStruct(self):
        self.write(
        """typedef struct Tag {
            uint32_t valuePtr;
            uint32_t valueSize;
            uint32_t namePtr;
            uint32_t nameSize;
            uint32_t parentPtr;
            uint32_t childPtr;
            uint32_t numOfChildren;
        } Tag_t;""")

    def addPtrs(self):
        nameBytes = ', '.join(hex(x) for x in ioteqDBBuilder.constPtrChar)
        self.write("const char str[] = {" + nameBytes + "};\n\n")
        
        treeBytes = ', '.join(hex(x) for x in ioteqDBBuilder.constPtrTree)
        self.write("const Tag_t tree[TOTAL_NUMBER_OF_TAGS] = " + "{" + treeBytes + "};\n\n")

        dataBytes = ', '.join(x for x in ioteqDBBuilder.dataPtr)
        self.write("uint8_t data[] = {" + dataBytes + "};\n\n")
    
    def build(self):
        self.addIncludes()
        self.addDefines()
        self.addStruct()
        self.addPtrs()
        self.fd.close()



ioteqDBBuilder  = IOTeqDBBuilder(configFile = os.getcwd( )+ "/config.json")
ioteqDBBuilder.build()

ioteqFileBuilder = IOTeqFileBuilder(os.getcwd() + "/database.h", ioteqDBBuilder)
ioteqFileBuilder.build()

