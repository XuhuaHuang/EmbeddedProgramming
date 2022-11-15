/*****************************************************************//**
 * \file   Stack.hpp
 * \brief  Basic templated Stack class implementation using std::vector
 *
 * \author Xuhua Huang
 * \date   November 15, 2022
 *********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#ifndef _IOSTREAM_
#include <iostream>
#endif

#include <cassert>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> elems;
public:
    Stack() = default;
    Stack(const Stack& rhs) = default;
    Stack(Stack&& rhs) : elems(std::move(rhs.elems)) {}

    void push(const T& elem);
    T pop();
    T top() const;
    bool empty() const {
        return elems.empty();
    }

    auto operator<=>(const Stack& rhs) -> int;

    /**
     * implicit requriement:
     * operator << must be overloaded for generic type T.
     */
    void print() const {
        for (const T& elem : elems) {
            std::cout << elem << " ";
        }
    }
};

template<typename T>
void Stack<T>::push(const T& elem) {
    // insert element at the end
    elems.push_back(elem);
    return;
}

template<typename T>
T Stack<T>::pop() {
    assert(!elems.empty());
    T elem = elems.back();  // copy the last element
    elems.pop_back();       // remove the last element
    return elem;            // return the saved copy
}

template<typename T>
T Stack<T>::top() const {
    // return last element
    return elems.back();
}

#endif
