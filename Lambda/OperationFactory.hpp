/*****************************************************************//**
 * \file   OperationFactory.hpp
 * \brief  Operation factory function definition
 * Factory and command design pattern
 * 
 * To compile:
 * $ g++ .\OperationFactory.hpp
 * 
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/

#ifndef OPERATIONFACTORY_HPP
#define OPERATIONFACTORY_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _FUNCTIONAL_
#include <functional>
#endif

enum class Op { ADD, MUL };

std::function<int(int, int)> OperationFactory(Op op) {
    switch(op) {
        case Op::ADD:
        return [](int a, int b) { return a + b; };
        case Op::MUL:
        return std::multiplies<int>();
    }
}

#endif
