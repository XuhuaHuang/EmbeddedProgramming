# `HelloQtConsole`

This projects uses `Qt 6.4.1` on Windows with `g++` compiler.<br>

## A few things
1. The default installation location of `Qt` is `C:\Qt\Qt6.4.1`.<br>
2. However, the actual installation location may vary; gor example, mine was placed `C:\Qt6\Qt6`
3. Following the default installation option, make sure to add `C:\Qt6\6.4.1\mingw_64\bin` to the system `path` variable.<br>
4. The `Qt6Config.cmake` file required by `CMakelists.txt` `find_package()` is located in `C:\Qt6\6.4.1\mingw_64\lib\cmake\Qt6`

## Build and Execute

**Build with `qt-cmake` or `CMake`**
```Bash
# change to the directory where this file could be found
# make sure the qt-cmake.bat could be found
$ qt-cmake --version
$ qt-cmake . -G "Ninja"
$ ninja
$ ./HelloQtConsole.exe
```

In the command block ablove, `-G` specifies the generator we want to use for the Make recipe we want to use for the project.<br>
The official tutorial uses `Ninja`, for our own flavour, we can specify the parameter to something different, for example, `MinGW Makefiles`.
```Bash
$ mkdir build && cd build
$ qt-cmake ..\CMakeLists.txt -G "MinGW Makefiles"
$ mingw32-make
$ ./HelloQtConsole.exe
```

**Build with `qmake`**
```Bash
$ qmake -project "QT += core widgets"
```
Now go ahead and launch`Qt Creator` with generated `HelloQtConsole.pro` file, <br>
or use `Qt VS Tools` extension in `Microsoft Visual Studio` to generate `HelloQtTest.vcxproj` Visual Studio Project file.

## References
> https://doc.qt.io/qt-6/cmake-get-started.html
