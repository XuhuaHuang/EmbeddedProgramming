/*****************************************************************//**
 * \file   customer.hpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   December 15, 2022
 *********************************************************************/

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <string>
#include <utility>

class Customer {
public:
    Customer() = default;
    Customer(const std::string& fn, const std::string& ln, const long v)
        : first(fn)
        , last(ln)
        , val(v) {
    }

    Customer(const Customer& rhs) = default;
    Customer(Customer&& rhs) = default;

    inline const std::string& firstname() const { return first; }
    inline std::string& firstname() { return first; }

    inline const std::string& lastname() const { return last; }
    inline std::string& lastname() { return last; }

    inline long value() const { return val; }
    inline long& value() { return val; }

    std::string first;
    std::string last;
    long val;
};

#endif
