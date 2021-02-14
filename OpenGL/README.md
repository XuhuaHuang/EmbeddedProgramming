# OpenGL
This folder contains source file when self-learning OpenGL.  
This **markdown** file should help setting up project with OpenGL code.

## Important
Code under this folder relies on GLFW library which could be found in the following link.  
https://www.glfw.org/download.html  
Download 32-bit or 64-bit Windows binaries.

## Brief Instruction
### Dependencies
1) Navigate to the downloaded .zip file.  
2) Find two folders: "include" and "lib-vc2019" (if not newer).  
3) Place these two folders unfer your project directory.

### Link Libraries
1) Project -> Properties -> Select "All Configurations" -> Select "Win32" as Platform  
2) C/C++ -> Additional Include Directories -> type in "$(SolutionDir)" and add file path to the "include" folder.  
3) Linker -> Input -> Additional Dependencies -> type in "glfw3.lib;opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib".  
4) Click "Apply", then click "OK".

## Message
LET'S GET INTENSE  
Xuhua HUANG  
Student, Electronics and Information Technology program  
Heritage College, Gatineau, Quebec, Canada
