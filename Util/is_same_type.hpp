/*****************************************************************//**
 * \file   is_same_type.hpp
 * \brief  std::is_same<T, U>::value and std::is_same_v<T, U> impl.
 * 
 * $ g++ is_same_type.hpp -std=c++2a
 * 
 * \author Xuhua Huang (xuhua.huang.io@gmail.com)
 * \date   September 2022
 *********************************************************************/


#if __has_include(<typeinfo>)
#include <typeinfo>
#endif

template<typename T, typename U>
constexpr inline bool is_same_type(const T& t, const U& u) {
    return typeid(t).hash_code() == typeid(u).hash_code();
}
