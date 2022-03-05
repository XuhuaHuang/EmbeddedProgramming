/**
 * @file demo_template.cpp
 * @author Xuhua Huang (xuhuahuang0412@gmail.com)
 * @brief Notes on template. Used as a quick reference guide.
 * @version 0.1
 * @date 2022-02-04
 * 
 * "Lift algorithms and data structures from concrete examples
 * to their most general and abastract form." - Bjarne Stroustrup
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<stdlib.h>
#include<type_traits>

#ifndef BUILD_COMPARE(TYPE)
#define BUILD_COMPARE(TYPE)                             \
    int cmp_ ## TYPE(const void* va, const void* vb)    \
    {                                                   \
        TYPE const* pa = static_cast<TYPE const*>(va);  \
        TYPE const* pb = static_cast<TYPE const*>(vb);  \
                                                        \
        if (*pa < *pb)          return -1;              \
        else if (*pa == *pb)    return 0;               \
        else                    return 1;               \
    }
#endif

BUILD_TYPE(float)
BUILD_TYPE(double)

/* ------------------ */
/* Function Templates */
/* ------------------ */
template<typename T>
T const& min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

/* --------------- */
/* Class Templates */
/* --------------- */
template<typename T, size_t N>
struct array {
    /*...*/
};

/* ------------------------------ */
/* Variable Templates since C++14 */
/* ------------------------------ */
template<typename T>
inline constexpr T pi = T(3.14159265359L);
// compile-time constant
// require a type that is convertible from long double
// double my_pi = pi<double>;

template<typename T>
T circular_area(T r) {
    return pi<T> * r * r;
}

// wrapper around is_arithmetic from <type_trait> library
template<typename T>
inline constexpr is_arithmetic_v = std::is_arithmetic<T>::value;

/* ---------------------------- */
/* Lambda Templates since C++20 */
/* ---------------------------- */
auto multiply = []<class T>(T a, T b) -> T {
    return a * b;
};

/* ----------------------- */
/* Define a Stack template */
/* ----------------------- */
template<typename T>
class Stack {
private:
    std::vector<T> m_data;
    
    // inline static member since C++17
    // in-place definition using inline
    inline static int m_count = 0;

public:
    // template type deduction dependent -> typename keyword is required
    using const_iterator = typename std::vector<T>::const_iterator;

    const_iterator begin() const;
    const_iterator end() const;
    bool is_empty() const;

    T const& top() const;

    void pop();
    void push(const T& t);
    Stack push_all_from(const Stack& stack);
};

template<class T>
auto Stack<T>::begin() const -> const_iterator {
    return m_data.crbegin();
    // std::vector::crbegin() to return the end of the vector
    // i.e. top of the stack
}

/* -------------------------------------------- */
/* Explicit Partial Specialization for Pointers */
/* -------------------------------------------- */
template<typename T>
class Stack<T*> {
private:
    std::vector<T> m_data;
    inline static int m_count = 0;

public:
    using const_iterator = typename std::vector<T>::const_iterator;

    const_iterator begin() const;
    const_iterator end() const;
    bool is_empty() const;

    /* Specialized function */
    T* top() const;
    T* pop();

    void push(const T& t);
    Stack push_all_from(const Stack& stack);
};

template<typename T>
T* Stack<T*>::pop() {
    T* tmp = m_data.back();
    m_data.pop_back();
    return tmp;
}

int main(void) {
    Stack<std::string*> pstrstack;
    pstrstack.push(new std::string("Hello, world"));
    std::cout << *pstrstack.pop() << "\n";
    delete pstrstack.pop();

    system("pause");
    return 0;
}