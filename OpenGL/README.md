# OpenGL
This folder contains source file when self-learning OpenGL.  
This **markdown** file should help setting up project with OpenGL code.

## Important
Code under this folder relies on GLFW library which could be found in the following link.  
https://www.glfw.org/download.html  
http://glew.sourceforge.net/  
Download 32-bit or 64-bit Windows binaries of both and link them with your own fashion, OR follow instruction written below.

## Brief Instruction
### Dependencies
1) Download "Dependencies.7z" and put it under your work project directory (same as the .sln file).  
2) Extract here.  
3) Follow steps in following "Link Libraries" section.

### Link Libraries
1) Project -> Properties -> Select "All Configurations" as Configuration -> Select "Win32" as Platform  
2) C/C++ -> Additional Include Directories -> type in  
   "$(SolutionDir)Dependencies\GLFW\include; $(SolutionDir)Dependencies\GLEW\include".  
3) Linker -> Additional Library Directions -> type in  
   "$(SolutionDir)Dependencies\GLFW\lib-vc2019;$(SolutionDir)Dependencies\GLEW\lib\Release\Win32".  
4) Linker -> Input -> Additional Dependencies -> type in  
   "glew32s.lib;glfw3.lib;opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib".  
5) Click "Apply", then click "OK".

## Message
LET'S GET INTENSE  
Xuhua HUANG
