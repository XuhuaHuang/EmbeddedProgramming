#include <tuple>

[[nodiscard]] constexpr auto first_and_last(auto first, auto last)
{
    return std::tuple{first, last};
}

[[nodiscard]] constexpr auto first_and_last(auto... args)
    requires (sizeof...(args) >= 2)
{
    auto [first, ... ts] = std::tuple{args...};
    auto tail            = std::tuple{ts...};
    return std::tuple{first, std::get<sizeof...(ts) - 1>(tail)};
}

int main()
{
    using namespace boost::ut;

    "first and last"_test = [] {
        expect(std::tuple{1, 2} == first_and_last(1, 2));
        expect(std::tuple{1, 3} == first_and_last(1, 2, 3));
        expect(std::tuple{0, 2} == first_and_last(0, 10, 2));
    };
}
