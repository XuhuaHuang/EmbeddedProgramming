/*****************************************************************//**
 * \file   destructorNotes.cpp
 * \brief  
 * A destructor is invoked automatically when the object goes out of scope 
 * or is explicitly destroyed by a call to delete.
 * A destructor has the same name as the class, preceded by a tilde (~).
 * For example, the destructor for class String is declared: ~String().
 * 
 * You only need to define a custom destructor when the class stores handles
 * to system resources that need to be released, or pointers that own the
 * memory they point to.
 * 
 * Do not accept arguments.
 * Do not return a value (or void).
 * Cannot be declared as const, volatile, or static.
 * 
 * \author Xuhua Huang
 * \date   November 2020
 *********************************************************************/
#include <string>

class String {
public:
    String(char* ch);   // Declare constructor
    ~String();          //  and destructor.
private:
    char* _text;
    size_t  sizeOfText;
};

// Define the constructor.
String::String(char* ch) {
    sizeOfText = strlen(ch) + 1;

    // Dynamically allocate the correct amount of memory.
    _text = new char[sizeOfText];

    // If the allocation succeeds, copy the initialization string.
    if (_text)
        strcpy_s(_text, sizeOfText, ch);
}

// Define the destructor.
String::~String() {
    // Deallocate the memory that was previously reserved
    //  for this string.
    delete[] _text;
}

int main(void)
{
    String str("Hello, world!");
    return 0;
}
