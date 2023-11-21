#include <iostream>
#include <variant>

template<typename... Ts>
struct overload : Ts...
{
    using Ts::operator()...;
}

template<typename... Ts>
overload(Ts...) -> overload<Ts...>;

int main()
{
    // clang-format off
    auto f = overload{
        [](int i) {
            std::cout << "Invoke with int" << "\n";
        },
        [](float f) {
            std::cout << "Invoke with float" << "\n";
        }
    };
    // clang-format on

    std::variant<int, float> v = 2;
    std::visit(f, v);

    v = 2.0f;
    std::visit(f, v);

    return 0;
}
