/*****************************************************************//**
 * \file   custom_deleter_fclose.cpp
 * \brief  Foe some reason, the code base you are working with is stuck
 * with an C-style file open-close operation, which needs explicit
 * calling, otherwise resouces will be leaked.
 * Consider combination of a custom deleter with smart pointers.
 * 
 * `enable_shared_from_this` and `this->shared_from_this();`
 * 
 * $ cd .\CustomDeleter\
 * $ cmake ..\CMakeLists.txt
 * 
 * \author Xuhua Huang
 * \date   December 01, 2022
 *********************************************************************/

#include <iostream>
#include <stdio.h>
#include <memory>

struct fclose_deleter {
    // type of Deleter must have an operator()(T*)
    void operator()(FILE* fp) const {
        fclose(fp);
    }
};

auto main(void) -> int {
    using unique_file = std::unique_ptr<FILE, fclose_deleter>;
    // creating an inner svope for demonstration purpose
    char* buffer {}; size_t N = 0;
    {
        unique_file fp(fopen("./CMakeLists.txt", "r"));
        fread(buffer, 1, N, fp.get());

        /* with std::shared_ptr */
        // std::shared_ptr<FILE> shared_fp(
        //     fopen("CMakeLists.txt", "r"),
        //     fclose_deleter{}
        // );

    } // when the unique_ptr<T> goes out of the scope
    // fclose will be called automatically

    system("pause");
    return EXIT_SUCCESS;
}
