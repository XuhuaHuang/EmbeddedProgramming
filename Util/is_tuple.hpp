/**
 * @file is_tuple.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-03-29
 *
 * @copyright ueg (c) 2023
 *
 */

namespace util
{
namespace type
{

template<typename T>
struct is_tuple : std::false_type
{
};

template<typename... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type
{
};

template<typename T>
constexpr bool is_tuple_v = is_tuple<T>::value;

} // namespace type
} // namespace util
