### EmbededProgramming
This is a repository created dedicated to embedded programming in Linux environment.  
Each topic is placed in individual folder. Folder named `Dealer` contains source code for mid-term card-game project.  
Please use code responsively.

#### **Special Thanks**
**Prof. Charmaine Jirgens**  
My mentor to the programming world  
Professor in Electronics and Information Technology program  
Heritage College, Gatineau, Quebec, Canada  

#### Languages
**C/C++, Java, Objective-C**  

<img src="./C_Logo.png" alt="An image for C Language" width="100"/><img src="./CPlusPlus_Logo.png" alt="An image for C++" width="100"/>  <img src="./Mingw_Logo.png" alt="An image for Java" width="110"/>  

**Example to Compile a File Named `Tuple_get_tie.cpp`**  

```Bash
$ g++ --version
$ cd ./StandardTemplateLibrary/Tuple
$ g++ -o get_tie.exe Tuple_get_tie.cpp -std=c++11
```

**To Update MinGW on Windows**  
Run a `PowerShell` session with administrator privilege and run:

```Bash
$ # Get the latest version of mingw
$ mingw-get update
$ mingw-get upgrade
$ # Verify the version of installed gcc and g++
$ gcc --version
$ g++ --version
```

---

#### Files prefixed with `demo_` under root


#### Directory `.\Fun` and `.\Fun\Java`
Contains all code when self learning other concepts in both C++ and Java.

#### Directory `.\Notes`
Contains code/notes and a `README.md` file, learning `std::maps`, `std::move` etc.  

#### Directory `.\Util`
Functionality provided by separate module. A namespace `util` is created to better manage the functions.   
```C++
namespace util {
    namespace type {}
    namespace parse {}
    namespace list {}
    namespace vector {}
}
```
Contains template (generic) function in a C-style header file, providing the following functionality:  
* `is_instance_of.h`: to quickly identify whether an object if of a specified type; like `isinstance()` in Python.  
* `is_same_type_of.hpp`: to quickly identify whether two objects are the same type using `typeid().hash_code()` and `typeid().name()`.  
* `log.h`: function-style definition `LOG(...)` using macro in C.
* `parse.h`: to easily split a comma-separated `std::string`.
* `print_list.h`: template function to print a `std::list<>` to the console; accepts a generic type of `std::list`.
* `print_vec.h`: template function to print a `std::vector<>` to the console; accepts a generic type of `std::vector`.

#### Directory `.\HackerRank`
Contains solutions to some of the basic problem solving coding questions. Provided file name most likely describes the content.  
The `README.md` has more handy notes when encountering those problems.  
[Click to see my hackerRank profile](https://www.hackerrank.com/XuhuaHuang?hr_r=1)

#### Directory `.\ObjectiveC`
Popular concepts in Objective-C.  
Compiled in Windows using `GNUstep Core` and provided GNUstep developer tools.
