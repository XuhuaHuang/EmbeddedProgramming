# OpenGL
This folder contains source file when self-learning OpenGL.  
This **markdown** file should help setting up project with OpenGL code.

## Important
Code under this folder relies on GLFW library which could be found in the following link.  
[GLFW Download](https://www.glfw.org/download.html)  
[GLEW Download](http://glew.sourceforge.net/)  
Download 32-bit or 64-bit Windows binaries of both and link them with your own fashion, OR follow instruction written below.

## Brief Instruction
### Dependencies
1) Download "Dependencies.7z" and put it under your work project directory (same as the `.sln` file).  
2) Right click, then click `Extract here`.<br>
3) Follow steps in following "Link Libraries" section.

### Link Libraries
1) Project -> Properties -> Select `All Configurations` as Configuration -> Select `Win32` as Platform  
2) C/C++ -> Additional Include Directories -> type in the following:  
   `$(SolutionDir)Dependencies\GLFW\include;$(SolutionDir)Dependencies\GLEW\include`.<br>
3) Linker -> Additional Library Directions -> type in the following:  
   `$(SolutionDir)Dependencies\GLFW\lib-vc2019;$(SolutionDir)Dependencies\GLEW\lib\Release\Win32`.<br>
4) Linker -> Input -> Additional Dependencies -> type in the following:  
   `glew32s.lib;glfw3.lib;opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib`.<br>
5) Click "Apply", then click "OK".

## Message
LET'S GET INTENSE  
Xuhua HUANG
