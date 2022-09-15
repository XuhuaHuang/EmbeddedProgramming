/**
 * @file is_same_type.hpp
 * @author Xuhua Huang (xuhuahuang0412@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-14
 * 
 * $ g++ is_same_type.hpp -std=c++2a
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#if __has_include(<typeinfo>)
#include <typeinfo>
#endif

template<typename T, typename U>
constexpr inline bool is_same_type(const T& t, const U& u) {
    return typeid(t).hash_code() == typeid(u).hash_code();
}
