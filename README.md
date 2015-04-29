# List-Folders
Lists all folders (and optionally files) on a system. DO NOT RUN THIS FOR TOO LONG, IT WILL RUN OUT OF MEMORY AND MAY CAUSE COMPUTER ISSUES.

-I did not focus much on GlobalDirClassHeader.h and GlobalDirClassImplement.cpp, so they may seem incomplete.
-Sorry about the lack of commenting, I worked to make it reable without as best I could, but I'll work to add comments.
-getSubDirsInDir() in main.cpp is a recursive function. Each iteration creates an object that holds a vector of objects that has all of the directories and subdirectories for a path. The main object is then stored in the globalDir object.
-Seriously don't let this thing run too long, my computer is still recovering from how much data it stored (close to 2 gigabytes). It stores a recursive list of all of the directories on a system, which ends up being a lot of memory.
