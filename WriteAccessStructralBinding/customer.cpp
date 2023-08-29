/*****************************************************************//**
 * \file   customer.cpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 15, 2022
 *********************************************************************/

#include <customer.hpp>

/* ---------------------------------------------- */
/* provide tuple-like API for structural bindings */
/* ---------------------------------------------- */

// std::tuple_size<Customer>::value
// Customer is not a tempalte type
// therefore this is a partial template specialization
template<>
struct std::tuple_size<Customer> {
    static constexpr int value = 3; // 3 attributes
};

// std::tuple_element<0, Customer>::type
template<std::size_t idx>
struct std::tuple_element<idx, Customer> {
    using type = std::string;
};

// decltype(std::tuple_element<2, Customer>)
template<>
struct std::tuple_element<2, Customer> {
    using type = long;
};

/* ----------------------- */
/* define getter overloads */
/* ----------------------- */

template<std::size_t I>
decltype(auto) get(Customer& c) {
    static_assert(I < 3); // design by contract
    if constexpr (I == 0) {
        return c.firstname();
    }
    else if constexpr (I == 1) {
        return c.lastname();
    }
    else {
        return c.value();
    }
}

template<std::size_t I>
decltype(auto) get(const Customer& c) {
    static_assert(I < 3); // design by contract
    if constexpr (I == 0) {
        return c.firstname();
    }
    else if constexpr (I == 1) {
        return c.lastname();
    }
    else {
        return c.value();
    }
}

template<std::size_t I>
decltype(auto) get(Customer&& c) {
    static_assert(I < 3); // design by contract
    if constexpr (I == 0) {
        return c.firstname();
    }
    else if constexpr (I == 1) {
        return c.lastname();
    }
    else {
        return c.value();
    }
}
