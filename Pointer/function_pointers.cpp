/*****************************************************************//**
 * \file   function_pointers.cpp
 * \brief  contains notes and examples on function pointers
 * 
 * Call functions at lower expenses; change the function pointer object
 * to a new function, instead of inserting a new stack frame
 * 
 * \author Xuhua Huang
 * \date   June 2021
 *********************************************************************/

#include <iostream>
#include <string>
#include <vector>

void greetUser(std::string userName)
{
    std::cout << "Hello, " << userName << "\n";
}


void ForEach(const std::vector<int>& contents, void (*fn)(int))
{
    /**
     * receive a vector and perform dedicated action to it
     * by calling parsed function fn(int)
     * 
     * \param contents: a constant reference to a vector of type int
     * \param fn: a function pointer of return type void and parameter list int
     * 		  In modern C++, this function pointer is usually replaced by lambda
     */
    for (int content : contents)
        fn(content);
}

void printValue(const int value)
{
    /**
     * function to print an integer
     * 
     * \param value: constant copy of an int
     */
    std::cout << "[fn][void printValue(int)]Content: " << value << std::endl;
}

int main(void)
{
    typedef void (*voidStringFn)(std::string);
    /**
     * define a type
     * all function pointers with a return type of void, parameter type of std::string
     * are defined type "voidStringFn"
     * \return void
     */

     /**
      * instantiate an instance of function pointer type "voidStringFn"
      * function pointer name: greetUserFnPtr
      * type: voidStringFn - returns void, takes a std::string
      * function pointer content: address of function signatured "greetUser"
      */
    voidStringFn greetUserFnPtr = &greetUser;

    /**
     * invoke function through function pointer
     * parse arguments as if invoking it normally
     */
    greetUserFnPtr("Lanfeng Jin");

    std::vector<int> values = { 1, 2, 3, 4, 5 };
    ForEach(values, &printValue);
    
    /* using Lambda to act as a function pointer */
    ForEach(values, [](int value) { // start lambda
        // capture all integers in scope by copying
        // no trailing return
        std::cout << "[lambda][&](int value)Value: " << value << std::endl;
        } // end lambda
    );

    return EXIT_SUCCESS;
}
