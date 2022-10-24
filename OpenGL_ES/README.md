## Brief Instruction
### Dependencies
All required dependencies files are located in the `Dependencies` folder.

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