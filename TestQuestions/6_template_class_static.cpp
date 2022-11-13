/*****************************************************************//**
 * \file   template_class_static.cpp
 * \brief  Conditions on static variable assignment in template class
 * 
 * \author Xuhua Huang
 * \date   October 2021
 *********************************************************************/

#include <iostream>

template <class T>
class Some {
public:
    static int stat;
};

template<class T>
int Some<T>::stat = 10;

int main()
{
    Some<int>::stat = 5;
    std::cout << Some<int>::stat << " "     // 5
        << Some<float>::stat << " "         // 10
        << Some < long>::stat << std::endl; // 10

    return 0;
}