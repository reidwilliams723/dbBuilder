import os
import json
import struct
from datetime import date
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

        self.currentTagAddress = 0

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
        elif (datatype == "Text"):
            value = tag["value"]
            for char in value:
                self.dataPtr.append(hex(ord(char)))
            # for i in range(len(self.dataPtr), 40):
            self.dataPtr.append(hex(0))

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
                        newTag.valueSize = len(tags[tag]["value"])

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
        sortedTags = sorted(self.tagList, key=lambda x: x.address, reverse=False)
        for tag in sortedTags:
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
    def __init__(self, directory, dbBuilder):
        self.dbBuilder = dbBuilder
        self.dbHeader = open(directory + "/ioteqDB.h", "w+")
        self.dbSource = open(directory + "/ioteqDB.c", "w+")

    def writeDBHeader(self, string):
        self.dbHeader.write(string)

    def writeDBSource(self, string):
        self.dbSource.write(string)

    def buildDBHeaderFile(self):
        self.writeDBHeader(f"""
                /**************************************************************************
                *
                * Tag Database Data
                *
                **************************************************************************
                *
                * This file was automatically generated and includes the data that makes
                * up a tag database. The database was generated using a JSON configuration file.
                *
                * (c) 2019, IOT-eq LLC, All Rights Reserved
                * Programmed By: 	Reid Williams
                * 					Inaki Zuloaga
                *
                * Date: {date.today().strftime("%B %d, %Y")}
                * Contact: izi@iot-eq.com
                *
                *
                *
                *
                *
                **************************************************************************
                */

                #ifndef IOTEQDB_H_
                #define IOTEQDB_H_
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>

                #define TOTAL_NUMBER_OF_TAGS          {self.dbBuilder.totalNumberOfTags()}

                typedef struct Tag {{
                    uint32_t valuePtr;
                    uint32_t valueSize;
                    uint32_t namePtr;
                    uint32_t nameSize;
                    uint32_t parentPtr;
                    uint32_t childPtr;
                    uint32_t numOfChildren;
                }} Tag_t;\n
        """)

        # Initialize Pointers (str, tree, data)
        self.writeDBHeader("extern const char str[];\n")
        self.writeDBHeader("extern const Tag_t tree[TOTAL_NUMBER_OF_TAGS];\n")
        self.writeDBHeader("extern char data[];\n")

        for tag in self.dbBuilder.tagList:
            if (tag.tagName != "tags"):
                self.writeDBHeader(f"""const Tag_t* {tag.tagName};\n""")

        self.writeDBHeader("""void initDB();\n""")
        self.writeDBHeader("""#endif""")
        self.dbHeader.close()

    def buildDBSourceFile(self):
        self.writeDBSource("""
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include "ioteqDB.h"
        \n""")

        # Initialize Pointers (str, tree, data)
        nameBytes = ', '.join(hex(x) for x in ioteqDBBuilder.constPtrChar)
        self.writeDBSource("const char str[] = {" + nameBytes + "};\n\n")
        
        treeBytes = ', '.join(hex(x) for x in ioteqDBBuilder.constPtrTree)
        self.writeDBSource("const Tag_t tree[TOTAL_NUMBER_OF_TAGS] = " + "{" + treeBytes + "};\n\n")

        dataBytes = ', '.join(x for x in ioteqDBBuilder.dataPtr)
        self.writeDBSource("char data[] = {" + dataBytes + "};\n\n")

        # Initialize DB Function
        self.writeDBSource("""void initDB(){\n""")
        for tag in self.dbBuilder.tagList:
            if (tag.tagName != "tags"):
                self.writeDBSource(f"""{tag.tagName} = getTag("{tag.tagName}");\n""")
        self.writeDBSource("""\n}""")

        self.dbSource.close()

    def build(self):
        self.buildDBHeaderFile()
        self.buildDBSourceFile()



# ioteqDBBuilder  = IOTeqDBBuilder(configFile = os.getcwd( )+ "/config.json")
ioteqDBBuilder  = IOTeqDBBuilder("/Users/reidwilliams/Repositories/c-folder/dbBuilder/config.1.json")

ioteqDBBuilder.build()

# ioteqFileBuilder = IOTeqFileBuilder(os.getcwd() + "/database.h", ioteqDBBuilder)
ioteqFileBuilder = IOTeqFileBuilder(os.getcwd(), ioteqDBBuilder)
ioteqFileBuilder.build()
ioteqDBBuilder.tree.show(data_property="address")
ioteqDBBuilder.tree.show()