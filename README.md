MyBackupper
===========
MyBackupper is the backup software of Windows.

Development environment
-----------------------
* Operating System  
Microsoft Windows 10

* Programing Language  
C

* Compiler  
gcc(MinGW) 6.3.0

Files and Directories
---------------------
* settings/  
A directory of settings.

* settings/.gitkeep  
(Git's file).

* .gitignore  
(Git's file).

* backup.c  
A source file of backup function.

* CommandProcess.c  
A source file of CommandProcess function.

* functions.h  
A header file of function declarations.

* macros.h  
A header file of macro declarations.

* main.c  
A source file of main function.

* setting.c  
A source file of PrintList function and AdditionSetting function and ClearSetting function.

* typedef.h  
A header file of typedef.

* MyBackupper.exe  
A executable file for Windows.

* README.md  
(This file).

Commands
--------
* pl  
Print a list of settings.  
Usage: `MyBackupper pl <setting-name>`

* as  
Addition a setting.  
Usage: `MyBackupper as <setting-name> <from-file-path> <to-file-path>`

* cs  
Clear settings.  
Usage: `MyBackupper cs <setting-name>`

* bu  
Run backup.  
Usage: `MyBackupper bu <setting-name>`

How to use (Windows)
--------------------
1. Open your CommandPrompt.
2. Move your MyBackupper's directory on your CommandPrompt.
3. Control your MyBackupper.  

How to use (Linux, MacOS)
-------------------------
1. Modify the macro "PATH_BREAK_CHARACTER" from '\\' to '/'.
2. Compile this project.
3. Open your CommandLineShell.
4. Move your MyBackupper's directory on your CommandLineShell.
5. Control your MyBackupper.  

Format
------
`MyBackupper <command> <arguments>`

Versions
--------
* 1.0 (November 19th, 2017)  
First version.

* 2.0 (November 23rd, 2017)  
Support directory backup.