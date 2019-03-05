# NemoLibC-Testing
This is the program to test NemoLib C++ which you can get from https://github.com/Kimw6/NemoLibC

# Linux installation.
* download main.cpp program to the linux folder
* compile
g++ -std=c++11 -c main.cpp -o main.o -I.
* Link (for example, your nemostaticlib.o is in the home/lib/NemoStaticLib folder)
g++ -o main main.o -Lhome/lib/NemoStaticLib -lnemostaticlib
* download the "exampleGraph.txt" file.
* Run
./main

# Windows installation.
**Prerequisites : Netbeans with c/c++ plugins
* download the files as a zip, and open it from Netbeans
* Right click the new project name, and choose “properties”
* From the categories, choose, “c++ Compiler”. 
On the right, “Include Directories”, choose the NemoLib folder. 
On the right, at the end of the line “Additional Options” add as “-std=c+11”
* From the categories, choose “Linker”, on the right, 
click  “Libraries”->“Add Library File” and choose the NemoStaticLib/dist/libnemostaticlib.a”
* Make sure the "exampleGraph.txt" file exists.
* Build and run

