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
    inline bool empty() const { return elems.empty(); }

    auto operator <=> (const Stack& rhs)->std::strong_ordering;

    /**
     * implicit requriement:
     * operator << must be overloaded for generic type T.
     */
    void print() const {
        for (const T& elem : elems) {
            std::cout << elem << " ";
        }
    }

    // iterator classes
    class iterator {
    public:
        iterator(typename std::vector<T>::iterator it) : it_(it) {}
        T& operator * () { return *it_; }
        iterator& operator ++ () { ++it_; return *this; }
        bool operator != (const iterator& other) { return it_ != other.it_; }
    private:
        typename std::vector<T>::iterator it_;
    };

    class const_iterator {
    public:
        const_iterator(typename std::vector<T>::const_iterator it) : it_(it) {}
        const T& operator * () const { return *it_; }
        const_iterator& operator ++ () { ++it_; return *this; }
        bool operator != (const const_iterator& other) const { return it_ != other.it_; }
    private:
        typename std::vector<T>::const_iterator it_;
    };

    iterator begin() { return iterator(elems.begin()); }
    iterator end() { return iterator(elems.end()); }
    const_iterator begin() const { return const_iterator(elems.begin()); }
    const_iterator end() const { return const_iterator(elems.end()); }
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
