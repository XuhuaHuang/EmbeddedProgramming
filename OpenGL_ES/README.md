# OpenGL Embedded Systems
Introduction to `Open Graphics Library` (OpenGL) for Embedded Systems.

## Dependencies
All required dependencies files should be located in the `Dependencies` folder. <br>
The include folder for both `GLEW` and `GLFW` are ignored and not included, simply they are very large files. <br>
However, you should unzip the downloaded folders and past them in `Dependencies`. <br>
Consult the exclusive list of what the `include` folders should contain: <br>
The following relative path are with respect to the directory in which this `README` is found. <br>

* For `GLEW`:
    * `Dependencies/GLEW/include/GL/eglew.h`
    * `Dependencies/GLEW/include/GL/glew.h`
    * `Dependencies/GLEW/include/GL/glxew.h`
    * `Dependencies/GLEW/include/GL/wglew.h`
* For `GLFW`:
    * `Dependencies/GLFW/include/GLFW/glfw3.h`
    * `Dependencies/GLFW/include/GLFW/glfw3native.h`

### Link Libraries
Right click on a start-up item in `Visual Studio`, change the following properties:
* `C/C++` -> `General` -> `Additional Include Directories` <br>
    * `$(SolutionDir)Dependencies\GLFW\include;`
    * `$(SolutionDir)Dependencies\GLEW\include;`
* `Linker` -> `General` -> `Additional Library Directories` <br>
    * `$(SolutionDir)Dependencies\GLFW\lib-vc2022;`
    * `$(SolutionDir)Dependencies\GLEW\lib\Release\x64;`
* `Linker` -> `Input` -> `Additional Dependencies` <br>
    * `glew32s.lib;glfw3.lib;opengl32.lib;User32.lib;Gdi32.lib;Shell32.lib;`.
* Click `Apply` to save the changes, then click `OK` to close the properties window.

## Troubleshooting
* After creating a `Visual Studio Solution/Project`, it is known that \
  **the `C/C++` properties menu is unavailble before first build of the project.** <br>
  To resolve this issue, add a dummy `main` function, build and run the project.

## References
> https://github.com/Shot511/OpenGLSampleCmake<br>
> https://github.com/andersonfreitas/opengl-tutorial-org/blob/master/misc04_building_your_own_app/CMakeLists.txt<br>
