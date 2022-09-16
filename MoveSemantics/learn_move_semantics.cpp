/*****************************************************************//**
 * \file   learn_move_semantics.cpp
 * \brief  Brief introduction in move semantics in C++ with
 * move constructor (rvalue reference)
 * Compiler g++ optimizes the behaviour of the program
 * by bypassing all the copying and moving
 *
 * To compile on Windows:
 * $ g++ -o move.exe .\learn_move_semantics.cpp -std=c++11
 * $ .\move.exe
 *
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream> // std::cout
#include <stdlib.h> // system()

/**
 * Class HasPtrMem Definition.
 * Stands for "Has Pointer Member"
 */
class HasPtrMem
{
public:
    /* Default Constructor */
    HasPtrMem() : ptr(new int(0)) {
        std::cout << __func__ << " at line: " << __LINE__ << "\n"
            << "Default Construct: " << ++n_cstr << "\n";
    }

    /* Copy Constructor */
    HasPtrMem(const HasPtrMem& rhs) : ptr(new int(*rhs.ptr)) {
        std::cout << __func__ << " at line: " << __LINE__ << "\n"
            << "Copy Constructor: " << ++n_cptr << "\n";
    }

    /* Move Constructor */
    HasPtrMem(HasPtrMem&& rhs) : ptr(rhs.ptr) {
        rhs.ptr = nullptr; // void the right-hand-side object internal pointer
        std::cout << __func__ << " at line: " << __LINE__ << "\n"
            << "Move Constructor: " << ++n_mvtr << "\n";
    }

    /* Destructor */
    ~HasPtrMem() {
        delete ptr;
        std::cout << __func__ << " at line: " << __LINE__ << "\n"
            << "Destructor: " << ++n_dstr << "\n";
    }

    /* Definition of static integer members. */
    static int n_cstr; // number of times default constructor called
    static int n_cptr; // number of times copy constructor called
    static int n_mvtr; // number of times move constructor called
    static int n_dstr; // number of times destructor called
// private:
    /* Member attribute - integer pointer. */
    int* ptr;
};

/* Define static variables for class hasPtrMem */
int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;
int HasPtrMem::n_dstr = 0;

HasPtrMem getTemp() {
    HasPtrMem temp;
    std::cout << "Resource from " << __func__ << ": "
        << _HEX << temp.ptr << "\n";

    return temp;
}

int main(void)
{
    HasPtrMem h = getTemp();
    std::cout << "Resource from " << __func__ << ": "
        << _HEX << h.ptr << "\n";

    system("pause");
    return 0;
}
