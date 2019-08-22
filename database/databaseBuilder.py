import os
import json
import struct
from datetime import date
from treelib import Node, Tree
from itertools import groupby 

class IOTeqDBBuilder():
    def __init__(self, configFile):
        with open(configFile, 'r') as f:
            jsonOutput = json.load(f)
            self.databaseTags = jsonOutput["database"]["tags"]

        self.IOTEQ_TAG_BYTE_SIZE = 44
        self.tree = Tree()
        self.constPtrChar = []
        self.constPtrTree = []
        self.tagList = []
        self.dataPtr = []
        self.persistentPtr = []

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

            if ("numtype" in tag["config"]):
                if (tag["config"]["numtype"] == "float"):
                    ba = bytearray(struct.pack("<f", value))
            else:
                ba = bytearray(struct.pack("<L", value)) 

            for b in ba:
                self.dataPtr.append(hex(b))

        elif (datatype == "Text"):
            value = tag["value"]
            for char in value:
                self.dataPtr.append(hex(ord(char)))
            # for i in range(len(self.dataPtr), 40):
            self.dataPtr.append(hex(0))

    def addValueToPersistentPtr(self, tag):
        datatype = tag["datatype"]
        if (datatype == "Number"):
            value = tag["value"]

            if ("numtype" in tag["config"]):
                if (tag["config"]["numtype"] == "float"):
                    ba = bytearray(struct.pack("<f", value))
            else:
                ba = bytearray(struct.pack("<L", value)) 

            for b in ba:
                self.persistentPtr.append(hex(b))

        elif (datatype == "Text"):
            value = tag["value"]
            for char in value:
                self.persistentPtr.append(hex(ord(char)))
            # for i in range(len(self.dataPtr), 40):
            self.persistentPtr.append(hex(0))

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
                    
                    if ("persistent" in tags[tag]["config"]):
                        if (tags[tag]["config"]["persistent"] == True):
                            newTag.persistentValuePtr = len(self.persistentPtr)
                            self.addValueToPersistentPtr(tags[tag])
                            newTag.isPersistent = 1
                   
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
                        if (parentTag.tagName != "tags"):
                            self.tagList[tagIndex].parentTag = parentTag
                    
                    # If node has children
                    if (self.tree.get_node(node).is_leaf() != True):
                        childrenNodes = self.tree.children(node)
                        childrenNodes.sort(key=lambda x: x.data.address)
                        self.tagList[tagIndex].childPtr = childrenNodes[0].data.address
                        self.tagList[tagIndex].numOfChildren = len(childrenNodes)

                        if (tag.tagName != "tags"):
                            for i in range(0, len(childrenNodes)):
                                tagIndex = self.tagList.index(childrenNodes[i].data)
                                if (i == 0):
                                    self.tagList[tagIndex].nextSibling = childrenNodes[i+1].data.address
                                elif (i == len(childrenNodes)-1):
                                    self.tagList[tagIndex].prevSibling = childrenNodes[i-1].data.address
                                else:
                                    self.tagList[tagIndex].nextSibling = childrenNodes[i+1].data.address
                                    self.tagList[tagIndex].prevSibling = childrenNodes[i-1].data.address

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
        self.parentTag = None
        self.prevSibling = 0
        self.nextSibling = 0
        self.isPersistent = 0
        self.persistentValuePtr = 0
    
    def getStruct(self):
        return [self.valuePtr, self.valueSize, self.persistentValuePtr, self.namePtr,
                self.nameSize, self.parentPtr, self.childPtr, self.prevSibling, self.nextSibling, self.numOfChildren, self.isPersistent]

    def getFullName(self, currentName=None):
        if (currentName == None):
            currentName = self.tagName
            if (self.parentTag != None):
                currentName = self.parentTag.tagName + "." + currentName
                return self.parentTag.getFullName(currentName)
            else:
                return currentName
        else:
            if (self.parentTag != None):
                currentName = self.parentTag.tagName + "." + currentName
                return self.parentTag.getFullName(currentName)

            else:
                return currentName

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
                #define CHECK_SUM                     0x00A5005A
                typedef struct Tag {{
                    uint32_t valuePtr;
                    uint32_t valueSize;
                    uint32_t persistentPtr;
                    uint32_t namePtr;
                    uint32_t nameSize;
                    uint32_t parentPtr;
                    uint32_t childPtr;
                    uint32_t prevSibling;
                    uint32_t nextSibling;
                    uint32_t numOfChildren;
                    uint32_t isPersistent;
                }} Tag_t;\n
        """)

        # Initialize Pointers (str, tree, data)
        self.writeDBHeader("extern const char str[];\n")
        self.writeDBHeader("extern const Tag_t tree[TOTAL_NUMBER_OF_TAGS];\n")
        self.writeDBHeader("extern uint8_t data[];\n\n")
        self.writeDBHeader("volatile uint32_t* persistentData;\n\n")
        self.writeDBHeader("void initDB();\n\n")

        for tag in self.dbBuilder.tagList:
            tagName=tag.tagName
            if "[" not in tagName and tagName != "tags":
                self.writeDBHeader(f"const Tag_t* {tagName};\n")

        for tagName, group in groupby(list(filter(lambda elem: "[" in elem.tagName, self.dbBuilder.tagList)), lambda elem: elem.tagName.split('[')[0]):
            self.writeDBHeader(f"const Tag_t {tagName}[{len(list(group))}];\n") 
        
        self.writeDBHeader("""#endif""")
        self.dbHeader.close()

    def buildDBSourceFile(self):
        self.writeDBSource("""
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include "ioteqDB.h"
                #include "ioteqDBFunctions.h"
        \n""")

        # Initialize Pointers (str, tree, data)
        nameBytes = ', '.join(hex(x) for x in ioteqDBBuilder.constPtrChar)
        self.writeDBSource("const char str[] = {" + nameBytes + "};\n\n")
        
        treeBytes = ', '.join(hex(x) for x in ioteqDBBuilder.constPtrTree)
        self.writeDBSource("const Tag_t tree[TOTAL_NUMBER_OF_TAGS] = " + "{" + treeBytes + "};\n\n")

        dataBytes = ', '.join(x for x in ioteqDBBuilder.dataPtr)
        self.writeDBSource("uint8_t data[] = {" + dataBytes + "};\n\n")

        self.writeDBSource("""
        /**
            *
            * initDB
            *
            * @param address	Persistent Memory Address
            *
            * Initializes all database tags and sets the persistent data address to use
            * in memory.
            *
            **/
            void initDB(volatile uint32_t* address){""")
        for tag in self.dbBuilder.tagList:
            tagName=tag.tagName
            if "[" not in tagName and tagName != "tags":
                self.writeDBSource(f"{tagName} = getTag(\"{tag.getFullName()}\");\n")

        for tagName, group in groupby(list(filter(lambda elem: "[" in elem.tagName, self.dbBuilder.tagList)), lambda elem: elem.tagName.split('[')[0]):
            self.writeDBSource(f"""for(int i = 0; i < sizeof({tagName})/sizeof(Tag_t); i++){{
                    			char {tagName}Tag[{len(tagName) + 4}];
                                char strIndex[4] = "";
                                sprintf(strIndex, "%d", i);
                                strcpy({tagName}Tag, "{tagName}[");
                                strcat({tagName}Tag, strIndex);
                                strcat({tagName}Tag,"]");
                                memcpy({tagName}+i, getTag({tagName}Tag), sizeof(Tag_t));
            }}""")
        

        self.writeDBSource("""persistentData = address;
        /* If memory CHECK_SUM does not match, set persistent tags to default values */
        if(*persistentData != CHECK_SUM){\n""")
        for tag in list(filter(lambda elem: elem.isPersistent == 1, self.dbBuilder.tagList)):
            self.writeDBSource(f"uint8_t* {tag.tagName}Default = getValue({tag.tagName});\n")
        self.writeDBSource("/* Set CHECK_SUM to memory address */\n*persistentData = CHECK_SUM;\n")

        for tag in list(filter(lambda elem: elem.isPersistent == 1, self.dbBuilder.tagList)):
            self.writeDBSource(f"setValue({tag.tagName}, {tag.tagName}Default);\n")
        self.writeDBSource("}\n")
        self.writeDBSource("}")

    def build(self):
        self.buildDBHeaderFile()
        self.buildDBSourceFile()



ioteqDBBuilder  = IOTeqDBBuilder(configFile = os.getcwd( )+ "/config.json")
ioteqDBBuilder.build()

ioteqFileBuilder = IOTeqFileBuilder(os.getcwd(), ioteqDBBuilder)
ioteqFileBuilder.build()

ioteqDBBuilder.tree.show(data_property='valuePtr',idhidden=False)
