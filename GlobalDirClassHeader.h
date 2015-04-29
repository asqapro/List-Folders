#ifndef GLOBALDIRCLASSHEADER_H_INCLUDED
#define GLOBALDIRCLASSHEADER_H_INCLUDED

#include "Headers.h"

class globalDirectory
{
    private:
        std::vector<folderDisplay> globalFolderList;
        std::vector<fileDisplay> globalFileList;
    public:
        globalDirectory();
        ~globalDirectory();

        bool setFolderList(std::vector<folderDisplay> const &pFolderList);
        bool setFileList(std::vector<fileDisplay> const &pFileList);

        std::vector<folderDisplay> const &getFolderList();
        std::vector<fileDisplay> const &getFileList();

        folderDisplay const &searchForFolder(std::vector<folderDisplay> const &searchFor);
        fileDisplay const &searchForFile(std::vector<fileDisplay> const &searchFor);

        bool addFolder(folderDisplay const &pFolder);
        bool addFile(fileDisplay const &pFile);

        bool addMultiFolder(std::vector<folderDisplay> const &pMultiFolder);
        bool addMultiFile(std::vector<fileDisplay> const &pMultiFile);
};

extern globalDirectory globalDir;

#endif // GLOBALDIRCLASSHEADER_H_INCLUDED

//storing functions here

/*fileDisplay const &globalDirectory::searchForFile(std::vector<fileDisplay> const &searchFor)
{

}*/

//storing functions here
