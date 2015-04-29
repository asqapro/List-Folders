#include "Headers.h"

//=============================================//
//             BEGIN FOLDER CLASS             //
//===========================================//

bool folderDisplay::operator==(const folderDisplay& comp) const
{
    if(location == comp.location && name == comp.name && subDirs == comp.subDirs)
        return true;
    return false;
}

bool folderDisplay::operator!=(const folderDisplay& comp) const
{
    if(location != comp.location || name != comp.name || subDirs == comp.subDirs)
        return true;
    return false;
}

folderDisplay::folderDisplay(std::string const &pName, std::string const &pLoc, bool exception)
{
    if(exception)
    {
        name = pName;
        location = pLoc;
    }
    else
    {
        if(pName.find_first_of("/?<>\\:*|\"") != std::string::npos)
        {
            std::cout << "Folder names cannot contain any of the characters: " << "/ ? < > \\ : * | \" " << std::endl;
            std::cout << "Name set to \"New Folder\"" << std::endl;
            name = "New Folder";
        }
        else
            name = pName;
        location = pLoc;
        if(location[location.length()-1] != '/')
            location += "/" + pName;
        else
            location += pName;
    }
}

folderDisplay::~folderDisplay(){}

bool folderDisplay::setName(std::string const &pName)
{
    if(pName.find_first_of("/?<>\\:*|\"") != std::string::npos)
    {
        std::cout << "Folder names cannot contain any of the characters: " << "/ ? < > \\ : * | \" " << std::endl;
        return false;
    }
    name = pName;
    if(name == pName)
        return true;
    return false;
}

bool folderDisplay::setLoc(std::string const &pLoc)
{
    location = pLoc;
    if(location == pLoc)
        return true;
    return false;
}

bool folderDisplay::setSubDirs(std::vector<folderDisplay> const &pSubDirs)
{
    subDirs = pSubDirs;
    if(subDirs == pSubDirs)
        return true;
    return false;
}

bool folderDisplay::setParentDirs(std::vector<folderDisplay> const &pParentDirs)
{
    parentDirs = pParentDirs;
    if(parentDirs == pParentDirs)
        return true;
    return false;
}

bool folderDisplay::addSubDir(folderDisplay const &newDir)
{
    if((std::string)(newDir.location.substr(0, newDir.location.find(newDir.name)-1)) != location)
    {
        std::cout << "Create a shortcut to do that." << std::endl;
        return false;
    }
    subDirs.push_back(newDir);
    if(subDirs.at(subDirs.size()-1) == newDir)
        return true;
    return false;
}

bool folderDisplay::moveDir(std::vector<folderDisplay> const &pNewDir)
{
    parentDirs = pNewDir;
    for(unsigned int iter = 0; iter < subDirs.size(); iter++)
    {
        std::vector<folderDisplay> temp = parentDirs;
        temp.push_back(*this);
        if(!subDirs[iter].moveDir(temp))
        {
            std::cout << "Sub dir move failed." << std::endl;
            return false;
        }
    }
    if(parentDirs == pNewDir)
        return true;
    return false;
}

std::string const &folderDisplay::getName() const
{
    return name;
}

std::string const &folderDisplay::getLoc() const
{
    return location;
}

std::vector<folderDisplay> const &folderDisplay::getSubDirs()
{
    return subDirs;
}
//=============================================//
//               END FOLDER CLASS             //
//===========================================//


//=============================================//
//             BEGIN FILE CLASS               //
//===========================================//
bool fileDisplay::operator==(const fileDisplay& comp) const
{
    if(name == comp.name && type == comp.type && location == comp.location)
        return true;
    return false;
}

bool fileDisplay::operator!=(const fileDisplay& comp) const
{
    if(name != comp.name || type != comp.type || location != comp.location)
        return true;
    return false;
}

fileDisplay::fileDisplay(std::string const &pName, std::string const &pType, std::string const &pLoc, fileDisplay* pShortcutLoc)
{
    name = pName;
    type = pType;
    location = pLoc;
    shortcutLocation = pShortcutLoc;
    name += "." + type;
}

fileDisplay::~fileDisplay(){}

bool fileDisplay::setName(std::string const &pName)
{
    if(pName.find_first_of("/?<>\\:*|\"") != std::string::npos)
    {
        std::cout << "File names cannot contain any of the characters: " << "/ ? < > \\ : * | \" " << std::endl;
        return false;
    }
    name = pName;
    if(name == pName)
        return true;
    return false;
}

bool fileDisplay::setType(std::string const &pType)
{
    type = pType;
    std::cout << "If you change a file name extension, the file might become unusable." << std::endl;
    name = name.substr(0, name.find(".")+1) + type;
    if(type == pType)
        return true;
    return false;
}

bool fileDisplay::setLoc(std::string const &pLoc)
{
    location = pLoc;
    if(location == pLoc)
        return true;
    return false;
}

//=============================================//
//               END FILE CLASS               //
//===========================================//
