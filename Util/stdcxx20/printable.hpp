/*****************************************************************//**
 * \file   printable.hpp
 * \brief  C++20 feature concepts to implement a template
 * to determine whether an object can be printed to std::cout.
 *
 * \author Xuhua Huang
 * \date   December 11, 2022
 *********************************************************************/

#ifndef PRINTABLE_HPP
#define PRINTABLE_HPP

#ifndef _CONCEPTS_
#include <concepts>
#endif

#ifndef _TYPE_TRAITS_
#include <type_traits>
#endif

namespace util::type_safety {

    /* determine whether an object can be printed to std::cout */
    /* basic implementation */
    template<typename T>
    concept printable = requires(T t) {
        // { std::cout << t } -> std::same_as<std::ostream&>;
        { std::cout << t } -> std::convertible_to<std::ostream&>;
    }

    template<typename T>
    concept trivial_printable = std::integral<T> or std::floating_point<T> or std::is_pointer<T>::value;

    /* detailed implementation */
    template<typename _Elem, typename _EnableIf = void>
    struct is_printable : std::false_type {};

    template<typename _Elem>
    struct is_printable<_Elem,
        typename std::enable_if_t<
            std::is_same_v<std::remove_reference_t<decltype(std::cout << std::declval<_Elem>())>, std::ostream>
        >
    > : std::true_type {};

    template<typename _Elem>
    inline constexpr bool is_printable_v = is_printable<_Elem>::value;

    int printfmt(char const* const format, trivial_printable auto& const ... arguments) {
        return std::fprintf(stdout, format, arguments...);
    }

    namespace test_fn {

        void test_printfmt(int argc, char* argv[]) {
            printfmt("Strings and chars:\t%s %c\n", "hello", 'x');
            printfmt("Rounding:\t\t%f %.0f %.32f\n", 1.5, 1.5, 1.3);
            printfmt("Padding:\t\t%05.2f %.2f %5.2f\n", 1.5, 1.5, 1.5);
            printfmt("Scientific:\t\t%E %e\n", 1.5, 1.5);
            printfmt("Hexadecimal:\t\t%a %A 0x%X\n", 1.5, 1.5, &argv);

            return;
        }

        template<typename _Elem>
        std::ostream& operator <<(std::ostream& os, const std::vector<_Elem>& v) {
            for (const auto& el : v) {
                os << el;
            }
            return os;
        }

        void test_is_printable_v(int argc, const char* argv[]) {
            std::cout << std::boolalpha;
            std::cout << is_printable_v<int> << "\n";
            std::cout << is_printable_v<unsigned char> << "\n";
            std::cout << is_printable_v<double> << "\n";
            std::cout << is_printable_v<std::vector<int>> << "\n";

            return;
        }

    }

} // util::type_safety

#endif // PRINTABLE_HPP
