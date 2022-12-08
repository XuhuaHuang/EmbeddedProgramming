### `ObjectiveC`

---

#### To Change `%PATH%` Environment Variable on Windows  
* Press `Windows + S`, type PATH, and hit Enter
* Click `Environment Variables..`
* Navigate to `System Variables`, click `Path` to highlight.  
* click `Edit...`

#### MinGW Compiler `%PATH%` Variable
Default `mingw` path variable: `C:\Program Files\mingw-w64\mingw64\bin`  
Default `GNUstep` path variable: `C:\GNUstep\bin`  
Removed from Path variable temporarily since using GNUstep.
* If both `GNUstep` and `mingw64` are added to the environment variable table, the terminal will use whichever is listed first in the table.  
* Since `mingw` is a subset of `GNUstep`, path for `GNUstep` is listed before `mingw64`.

#### Verify `GNUstep` Installation and `gcc` Compiler
```Bash
$ gcc -v
Using built-in specs.
COLLECT_GCC=C:\GNUstep\bin\gcc.exe
COLLECT_LTO_WRAPPER=c:/gnustep/bin/../libexec/gcc/mingw32/4.6.1/lto-wrapper.exe
Target: mingw32
Configured with: ../gcc-4.6.1/configure --enable-languages=c,c++,fortran,objc,obj-c++ --disable-sjlj-exceptions --with-dwarf2 --enable-shared --enable-libgomp --disable-win32-registry --enable-libstdcxx-debug --enable-version-specific-runtime-libs --build=mingw32 --prefix=/mingw
Thread model: win32
gcc version 4.6.1 (GCC)
```

#### Command to Compile Objective-C Code  
Example: compile `helloworld.m`(source file) to `hello.exe`(executable)
```Bash
$ gcc -I "C:\GNUstep\GNUstep\System\Library\Headers" -L "C:\GNUstep\GNUstep\System\Library\Libraries" -o hello helloWorld.m -lobjc -lgnustep-base -fconstant-string-class=NSConstantString  
$ ./hello
```

#### GNUstep Folder Location
`<Foundation/Foundation.h>` : `C:\GNUstep\GNUstep\System\Library\Headers\Foundation`  
Libraries: `C:\GNUstep\GNUstep\System\Library\Libraries`

#### Online Objective-C Compiler
[Obj-C link]: (https://www.tutorialspoint.com/compile_objective-c_online.php)
[Online Objective-C Compiler][Obj-C link]

---

#### Notes
