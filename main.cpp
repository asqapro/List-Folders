#include "Headers.h"

using namespace std;

globalDirectory globalDir;

vector<folderDisplay> getSubDirsInDir(folderDisplay const &currFolder)
{
    //cout << "Enter. Name: " << currFolder.getName() << endl << endl;
    cout << "Location: " << currFolder.getLoc() << endl << endl;
    vector<folderDisplay> errRetVal;

    WIN32_FIND_DATA findFileData;
    HANDLE findHandle;
    WIN32_FIND_DATA dummyFileData;

    int fileCount = 0;

    bool moreFiles = true;

    vector<folderDisplay> localFolderList;

    while(moreFiles)
    {
        findHandle = FindFirstFile((currFolder.getLoc()+"\\*").c_str(), &findFileData); //get a handle in the directory
        if(findHandle == INVALID_HANDLE_VALUE)
        {
            cout << "Find first failed with error code: " << GetLastError() << endl;
        }
        bool completedSearch = false;
        //int filesChecked = 0; //keeps track of how many files have been checked
        for(int iter = 0; iter < fileCount; iter++) //skip through already found files
        {
            if(FindNextFile(findHandle, &findFileData) == 0) //if there are no more files to check
            {
                break; //don't set the bool that allows the function to continue
            }
            if(iter == fileCount-1) //otherwise if all the files are accounted for
            {
                completedSearch = true; //set the bool
            }
            //filesChecked++;
        }
        if(!completedSearch && fileCount > 0)
        {
            errRetVal.push_back(currFolder);
            //cout << "Error when scanning files." << endl;
            //cout << "Folder that encountered error: " << currFolder.getName() << endl;
            //cout << "Location: " << currFolder.getLoc() << endl;
            //cout << "Files checked: " << filesChecked << endl;
            //cout << "Excpected files: " << fileCount << endl;
            //cout << "Last error: " << GetLastError() << endl;
            moreFiles = false;
            continue;
        }

        if((string)findFileData.cFileName == "." || (string)findFileData.cFileName == "..") //.  and .. are hidden directories, ignore them
        {
            fileCount++;
            continue;
        }

        DWORD fileAttrib = findFileData.dwFileAttributes; //get the current file attributes
        if(fileAttrib & FILE_ATTRIBUTE_HIDDEN) //if the file is hidden, we don't want to read it
        {
            fileCount++; //so just get the next one in the next loop
            continue;
        }

        if(FindNextFile(findHandle, &dummyFileData) == 0 && currFolder.getLoc() == "C:\\") //if there are no more files in C: drive
        {
            errRetVal.push_back(currFolder);
            moreFiles = false; //break out of the loop
            //cout << "last: " << dummyFileData.cFileName << endl;
            continue;
        }

        if(fileAttrib & FILE_ATTRIBUTE_DIRECTORY) //if a file is a folder
        {
            fileCount++;
            folderDisplay temp("null", "null", true); //
            temp.setName((string)findFileData.cFileName);
            temp.setLoc(currFolder.getLoc()+"\\" + temp.getName());
            if(FindFirstFile((temp.getLoc() + "\\*").c_str(), &dummyFileData) != INVALID_HANDLE_VALUE) //if there is at least 1 directory
            {
                vector<folderDisplay> subDirs = getSubDirsInDir(temp);
                if(subDirs.at(0) != currFolder)
                {
                    temp.setSubDirs(subDirs); //get all the directories
                }
                else
                {
                    localFolderList.push_back(currFolder);
                    return localFolderList;
                }
            }
            localFolderList.push_back(temp); //add this directory to the list of local directories
        }
        else //if a file is not a folder
        {
            fileCount++; //skip it
            continue;
        }

        if(FindNextFile(findHandle, &dummyFileData) == 0) //if there are no more files in the current directory
        {
            return localFolderList; //return the list of local directories
        }
    }
    return errRetVal;
}

int main()
{
    folderDisplay mainFolder("c:", "c:", true);
    globalDir.setFolderList(getSubDirsInDir(mainFolder));
    cout << "Done" << endl;
    Sleep(1000000);
    return 0;
}
