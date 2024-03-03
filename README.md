Application (App) to find file on Local Host:

functionality: App finds file by "name".
Search is started started from root "/" on Linux\Ubuntu.

Thread who will find needed file has to print Full Path(s) to the file and has to notify all the rest threads to stop searching.

Logic "to search file" has to be placed into static library.

Application just uses this library to find files in a fast way.

configuration: Static Library compilation is done separately from Application.

Compiler: G++.
Use Makefile for compilation/linking instructions.

 
