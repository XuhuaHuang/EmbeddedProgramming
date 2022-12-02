/*****************************************************************//**
 * \file   MatroxTestQuestion.cpp
 * \brief  Interesting questions during test provided by Matrox
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>

class SpecialString
{
public:

    SpecialString(const char* pStr)
    {
        int size = strlen(pStr) + 1;
        m_pData = new char[size];
        strcpy(m_pData, pStr);
    }

    ~SpecialString()
    {
        delete[] m_pData;
    }

    void Reverse()
    {
        // Suppose this method is defined and that it reverses the order of the  
        // characters in the string by accessing m_pData, for example "abc" would be 
        // changed to "cba"
    }

    const char* GetDataPointer() const
    {
        return m_pData;
    }

private:
    char* m_pData;
};

void DisplayString(const SpecialString& x)
{
    // This code displays the string, not the pointer value !
    std::cout << x.GetDataPointer() << "\n";
}

int main()
{
    SpecialString MyStr("abcdefghiklmnopqrstuvwxyz");
    DisplayString(MyStr);
    MyStr.Reverse();
    DisplayString(MyStr);

    /* MEMORY ALLIGNMENT */
    float a = 0.001;
    float b = 0.003;
    float c, * pa, * pb;
    float* p;

    pa = &a;
    *pa = 2 * a;
    pb = &b;
    c = 4 * (*pb - *pa);
    p = pb + 1;

    std::cout << a << " " << b << " " << c << "\n"
        << (int)&a << " " << (int)&b << " " << (int)&c << "\n"
        << (int)pa << " " << *pa << " " << (int)&(*pa) << "\n"
        << (int)pb << " " << *pb << "\n";
    //  << (int)p << " " << (int)*p << "\n"; // undefined behaviour

    return 0;
}
