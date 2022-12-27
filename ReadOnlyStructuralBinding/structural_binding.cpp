/*****************************************************************//**
 * \file   structural_binding.cpp
 * \brief  Structural binding feature in C++17.
 * 
 * To run the project with CMake:
 * $ cd .\ReadOnlyStructuralBinding
 * $ cmake .\CMakeLists.txt
 * 
 * To run the file with g++
 * $ g++ -c .\structural_binding.cpp -o .\structural_binding.exe -std=c++17
 * $ .\structural_binding.exe
 * 
 * \author Xuhua Huang
 * \date   November 2022
 *********************************************************************/

#include <iostream>
#include <string>
#include <type_traits>

class Customer {
public:
    Customer() = default;
    Customer(std::string first, std::string last, const long val)
        : first_name(std::move(first)), last_name(std::move(last)), val(val) {}

    std::string get_first_name() const { return this->first_name; }
    std::string get_last_name() const { return this->last_name; }
    long get_val() const { return this->val; }

private:
    std::string first_name;
    std::string last_name;
    long val; // placeholder for any non-string/numeric typed value
    // for demonstration purpose
};

/**
 * supply tuple-alike API.
 */
// create tuple_size specialization
// use case:
// std::tuple_size<Customer>::value
template<>
struct std::tuple_size<Customer> {
    static constexpr int value = 3;
};

// create tuple_element specialization for val
// use case:
// decltype(std::tuple_element<2, Customer>)
template<>
struct std::tuple_element<2, Customer> {
    using type = long;
};

// consider the following template instantiation:
// decltype(std::tuple_element<0, Customer>)
// decltype(std::tuple_element<1, Customer>)
// std::tuple_element<0, Customer>::type will be evaluated to std::string
template<std::size_t idx>
struct std::tuple_element<idx, Customer> {
    using type = std::string;
};

template<std::size_t>
auto get(const Customer& c);

template<>
auto get<0>(const Customer& c) { return c.get_first_name(); }

template<>
auto get<1>(const Customer& c) { return c.get_last_name(); }

template<>
auto get<2>(const Customer& c) { return c.get_val(); }

/**
 * provide encapsulation to get<>.
 * with compile-time if characteristic (overloads)
 * \return 
 */
template<std::size_t id>
auto get(const Customer& c) {
    static_assert(id < 3); // design by contract
    if constexpr (id == 0) {
        return c.get_first_name();
    }
    else if constexpr (id == 1) {
        return c.get_last_name();
    }
    else {
        return c.get_val();
    }
}

int main(void) {
    Customer c{ "Xuhua", "Huang", 42 };
    auto [first_name, last_name, val] = c;
    std::cout << "first_name: " << first_name << " last_name: " << last_name << " val: " << val << "\n";

    // Modify the values of the object
    std::string s = std::move(last_name);
    // variable last_name is no longer valid at this point
    // therefore it will be empty
    first_name = "Andy";
    val += 10;
    // C26800: Used of a moved from object
    // std::cout << "first_name: " << first_name << " last_name: " << last_name << " val: " << val << "\n";
    std::cout << "first_name: " << first_name << " last_name: " << s << " val: " << val << "\n";

    return 0;
}
