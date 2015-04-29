#ifndef DISPLAYCLASSHEADER_H_INCLUDED
#define DISPLAYCLASSHEADER_H_INCLUDED

#include "Headers.h"

class folderDisplay
{
    private:
        std::string name;
        std::string location;
        std::vector<folderDisplay> subDirs;
        std::vector<folderDisplay> parentDirs;
    public:
        bool operator==(const folderDisplay& comp) const;
        bool operator!=(const folderDisplay& comp) const;

        folderDisplay();
        folderDisplay(std::string const &pName, std::string const &pLoc, bool exception=false);
        ~folderDisplay();

        bool setName(std::string const &pName);
        bool setLoc(std::string const &pLoc);
        bool setSubDirs(std::vector<folderDisplay> const &pSubDirs);
        bool setParentDirs(std::vector<folderDisplay> const &pParentDirs);
        bool addSubDir(folderDisplay const &newDir);
        bool moveDir(std::vector<folderDisplay> const &pNewDir);

        std::string const &getName() const;
        std::string const &getLoc() const;
        std::vector<folderDisplay> const &getSubDirs();
        std::vector<folderDisplay> const &getParentDirs();
};

class fileDisplay
{
    private:
        std::string name;
        std::string type;
        std::string location;
        fileDisplay* shortcutLocation;
    public:
        bool operator==(const fileDisplay& comp) const;
        bool operator!=(const fileDisplay& comp) const;

        fileDisplay(std::string const &pName, std::string const &pType, std::string const &pLoc, fileDisplay* pShortcutLoc=NULL);
        ~fileDisplay();

        bool setName(std::string const &pName);
        bool setType(std::string const & pType);
        bool setLoc(std::string const &pLoc);



};

#endif // DISPLAYCLASSHEADER_H_INCLUDED
