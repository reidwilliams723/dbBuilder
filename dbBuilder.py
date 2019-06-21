import os
import json
from ioteqDB import *


class Tree:
    def __init__(self):
        self.folders = []

class Folder:
    def __init__(self, child=None, sibling=None, parent=None):
        # self.address = dataAddressPointer =  # Memory address of folder 
        self.child = child # Memory address of child folder
        self.sibling = sibling # Memory address of sibling folder
        self.parent = parent # Memory address of parent folder

    def addChild(self,folder):
        self.child = folder

    def addSibling(self, folder):
         self.silbing = folder

    def addParent(self, folder):
        self.parent = folder

    def memoryArray(self):
        array = [self.child, self.sibling, self.parent]
        return array
        
class Tag:
    def __init__(self, value):
        self.value = value


cFile = open("/Users/reidwilliams/Repositories/c-folder/dbBuilder/database.c", "w+")
totalTagNumber = 0
dataAddressPointer = 0x00

tagFolder = Folder(dataAddressPointer)

def headerFiles():
     cFile.writelines("#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <stdio.h>\n#include <string.h>\n\n")

def buildFile():
    createStructs()

def createStructs():
    cFile.writelines("\ntypedef struct Folder {\nTag_t* tag;\nFolder_t* parent;\nFolder_t* children;\nuint8_t arrayDim;\n} Folder_t;\n")
    cFile.writelines("\ntypedef struct Tag {\nchar* name;\nuint8_t* value;\nuint8_t valueSize;\n} Tag_t;\n")

def addTag(tagName, value, tagType, arrayDim):
    valueSize = 0
    global dataAddressPointer
    if ("32" in tagType):
        valueSize = 4*arrayDim
    elif ("16" in tagType):
        valueSize = 2*arrayDim
    elif ("8" in tagType):
        valueSize = 1*arrayDim
    elif ("float" in tagType):
        valueSize = 4*arrayDim
    elif ("double" in tagType):
        valueSize = 8*arrayDim
    elif ("Text" in tagType):
        valueSize = len(value)*arrayDim

    cFile.write(f"#define {tagName:>8}Index        {hex(dataAddressPointer):>12}\n")
    dataAddressPointer = dataAddressPointer + valueSize

    print(tagName)


def parseTags(tags, parent=""):
    for tag in tags:
        if (tags[tag]["datatype"] == "Folder"):
            for i in range(tags[tag]["arraydim"]):
                if (parent != ""):
                    if (tags[tag]["arraydim"] > 1):
                        tagName = parent + "." + tag + "[" + str(i) + "]"
                    else:
                        tagName = parent + "." + tag
                else:
                    if (tags[tag]["arraydim"] > 1):
                        tagName = tag  + "[" + str(i) + "]"
                    else:
                        tagName = tag

                parseTags(tags[tag]["children"], tagName)
        else:
            if (tags[tag]["arraydim"] > 1):
                for i in range(tags[tag]["arraydim"]):
                    if (parent != ""):
                        tagName = parent + "." + tag + "[" + str(i) + "]"
                    else:
                        tagName = tag + "[" + str(i) + "]"
                    tagType = tags[tag]["datatype"]
                    tagValue = tags[tag]["value"]
                    addTag(tagName, tagValue, tagType)
            else:
                if (parent != ""):
                    tagName = parent + "." + tag
                else:
                    tagName = tag
                tagType = tags[tag]["datatype"]
                tagValue = tags[tag]["value"]
                addTag(tagName, tagValue, tagType)

def parseTags2():
    # Get tags from config file

    for tag in tags:
        currentFolder = Folder(dataAddressPointer + 16)
        if (type(tags[tag]) == IOTeqDbPersistentValueNumber):
            print("Here")
        if (tags[tag]["datatype"] != "Folder"):

            addTag(tag, tags[tag]["value"], tags[tag]["datatype"], tags[tag]["arraydim"])
        elif (tags[tag]["datatype"] == "Folder"):
            parseFolder(tags[tag])
        # if (tags[tag]["datatype"] == "Folder"):
        #     if (tags[tag]["arraydim"] > 1):
        #         addTag()

def parseFolder(folder):

    folderSize = 0
    for child in folder["children"]:
        tagType = folder["children"][child]["datatype"]
        arrayDim = folder["children"][child]["arraydim"]

        if ("32" in tagType):
            valueSize = 4*arrayDim
        elif ("16" in tagType):
            valueSize = 2*arrayDim
        elif ("8" in tagType):
            valueSize = 1*arrayDim
        elif ("float" in tagType):
            valueSize = 4*arrayDim
        elif ("double" in tagType):
            valueSize = 8*arrayDim
        elif ("Text" in tagType):
            valueSize = len( folder["children"][child]["arraydim"]["value"])*arrayDim
        
        folderSize += valueSize
    print(folderSize)




configFile = "/Users/reidwilliams/Repositories/c-folder/dbBuilder/config.json"
with open(configFile, 'r') as f:
    jsonOutput = json.load(f)
    database = jsonOutput["database"]

# mainFolder = Folder(4, 0, 0, 0)
# strokesFolder = Folder(0, 0, mainFolder.value, 4)

currentLeave = 0
mainFolder = Folder(dataAddressPointer)

for tag in database["tags"]:
    print(database["tags"][tag])

tagDatabase = IOTeqDatabase()
tagDatabase.loadConfig(database)




test = []
# test.extend(mainFolder.memoryArray())
# test.extend(strokesFolder.memoryArray())

treeBytes = ', '.join(hex(x) for x in test)

cFile.write("const void* tree = {" + treeBytes + "}")



# print(hex(id(dataAddressPointer)))

# print(type(id(dataAddressPointer)))

# print(hex(test))


