#include "Headers.h"

globalDirectory::globalDirectory(){}
globalDirectory::~globalDirectory(){}

bool globalDirectory::setFolderList(std::vector<folderDisplay> const &pFolderList)
{
    globalFolderList = pFolderList;
    if(globalFolderList == pFolderList)
        return true;
    return false;
}

bool globalDirectory::setFileList(std::vector<fileDisplay> const &pFileList)
{
    globalFileList = pFileList;
    if(globalFileList == pFileList)
        return true;
    return false;
}

std::vector<folderDisplay> const &globalDirectory::getFolderList()
{
    return globalFolderList;
}

std::vector<fileDisplay> const &globalDirectory::getFileList()
{
    return globalFileList;
}

folderDisplay const &globalDirectory::searchForFolder(std::vector<folderDisplay> const &searchFor)
{
    for(unsigned int searchIndex = 0; searchIndex < searchFor.size(); searchIndex++)
    {
        for(unsigned int globalDirIndex = 0; globalDirIndex < globalFolderList.size(); globalDirIndex++)
        {
            if(globalFolderList[globalDirIndex] == searchFor[searchIndex])
            {
                searchIndex++;
                if(searchIndex == searchFor.size())
                {
                    return globalFolderList[searchIndex];
                }
            }
        }
    }
    return searchFor[0];
}

bool globalDirectory::addFolder(folderDisplay const &pFolder)
{
    globalFolderList.push_back(pFolder);
    return true;
}

bool globalDirectory::addFile(fileDisplay const &pFile)
{
    globalFileList.push_back(pFile);
    return true;
}

bool globalDirectory::addMultiFolder(std::vector<folderDisplay> const &pMultiFolder)
{
    for(unsigned int iter = 0; iter < pMultiFolder.size(); iter++)
    {
        globalFolderList.push_back(pMultiFolder[iter]);
    }
    return true;
}

bool globalDirectory::addMultiFile(std::vector<fileDisplay> const &pMultiFile)
{
    for(unsigned int iter = 0; iter < pMultiFile.size(); iter++)
    {
        globalFileList.push_back(pMultiFile[iter]);
    }
    return true;
}
