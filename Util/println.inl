#include <iostream>
#include <vector>

namespace util
{

template<typename T>
concept printable = requires (std::ostream& os, T v) { v.print(os); };

template<typename T>
std::ostream& print_ln(std::ostream& os, const T& v)
{
    if constexpr (printable<T>)
        v.print(os);
    else
        os << v;
    os << "\n";
    return os;
}

template<printable T>
using vector_of_printable = std::vector<T>;

} // namespace util
