/**
 * @file lambda_with_stdlib.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2022-07-18
 *
 * $ g++ -o lambda_stdlib.exe lambda_with_stdlib.cpp -std=c++2a
 * $ .\lambda_stdlib.exe
 *
 * $ cl .\lambda_with_stdlib.cpp /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
 * .\lambda_with_stdlib.exe
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../Helper/container_ordering.hpp"

struct Person
{
public:
    constexpr Person() noexcept(std::is_nothrow_constructible_v<std::string>) = default;

    constexpr explicit Person(const std::string&  first_name,
                              const std::string&  last_name,
                              const std::uint32_t age) noexcept(std::is_nothrow_copy_constructible_v<std::string>)
        : first_name_(first_name)
        , last_name_(last_name)
        , age_(age)
    {
    }

    // clang-format off
    template<typename Self>
    constexpr [[nodiscard]] auto&& firstname(this Self&& self) noexcept { return self.first_name_; }

    template<typename Self>
    constexpr [[nodiscard]] auto&& lastname(this Self&& self) noexcept { return self.last_name_; }

    template<typename Self>
    constexpr [[nodiscard]] auto&& age(this Self&& self) noexcept { return self.age_; }

    constexpr Person(const Person& rhs)                     = default;
    constexpr Person& operator=(const Person& rhs) noexcept = default;
    constexpr Person(Person&& rhs) noexcept                 = default;
    constexpr Person& operator=(Person&& rhs) noexcept      = default;
    constexpr virtual ~Person() noexcept                    = default;
    // clang-format on

    friend constexpr inline auto operator<=>(const Person& lhs, const Person& rhs) = default;

    inline bool operator==(const Person& rhs) const
    {
        return (firstname() == rhs.firstname()) && (lastname() == rhs.lastname()) && (age() == rhs.age());
    }

private:
    std::string   first_name_;
    std::string   last_name_;
    std::uint32_t age_;
};

inline std::ostream& operator<<(std::ostream& os, const Person& person) noexcept
{
    os << person.firstname() << " " << person.lastname() << " of age " << person.age();
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const std::vector<Person>& people) noexcept
{
    for (const auto& person : people)
        os << person << "\n";
    return os;
}

auto compare_people = [](const Person& lhs, const Person& rhs) {
    return ((lhs.age() < rhs.age()) && (lhs.firstname() < rhs.firstname()) && (lhs.lastname() < rhs.lastname()));
};

namespace std
{

template<>
struct tuple_size<Person>
{
    static constexpr size_t value = 3;
};

template<size_t I>
struct tuple_element<I, Person>
{
    using type = string;
};

template<>
struct tuple_element<2, Person>
{
    using type = uint32_t;
};

template<size_t I>
    requires (I < tuple_size<Person>::value)
decltype(auto) get(Person& person)
{
    if constexpr (I == 0)
        return person.firstname();
    else if constexpr (I == 1)
        return person.lastname();
    else
        return person.age();
}

template<size_t I>
    requires (I < tuple_size<Person>::value)
decltype(auto) get(const Person& person)
{
    if constexpr (I == 0)
        return person.firstname();
    else if constexpr (I == 1)
        return person.lastname();
    else
        return person.age();
}

template<size_t I>
    requires (I < tuple_size<Person>::value)
decltype(auto) get(Person&& person)
{
    if constexpr (I == 0)
        return person.firstname();
    else if constexpr (I == 1)
        return person.lastname();
    else
        return person.age();
}

} // namespace std

int main(void)
{
    static_assert(std::tuple_size<Person>::value == 3);
    static_assert(std::is_same<std::tuple_element<0U, Person>::type, std::string>::value);
    static_assert(std::is_same<std::tuple_element<1U, Person>::type, std::string>::value);
    static_assert(std::is_same<std::tuple_element<2U, Person>::type, std::uint32_t>::value);

    std::vector<Person> people{};

    Person me                = Person();
    me.firstname()           = "Xuhua";
    me.lastname()            = "Huang";
    me.age()                 = 22U;
    constexpr Person partner = Person("Lanfeng", "Jin", 36U);

    assert(std::get<0>(partner) == "Lanfeng");
    assert(std::get<1>(partner) == "Jin");
    assert(std::get<2>(partner) == 36U);

    const auto [fn, ln, age] = partner;
    assert(fn == "Lanfeng");
    assert(ln == "Jin");
    assert(age == 36U);

    people.push_back(partner);
    people.push_back(me);

    // print before sorting
    std::cout << people << "\n";
    // sort
    std::sort(people.begin(), people.end(), [](const Person& p1, const Person& p2) {
        return p1.lastname() < p2.lastname() || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
    });
    // verify sort operation
    std::cout << people << "\n";

    auto result = me <=> partner;
    std::cout << typeid(result).name() << "\n";
    using helper::container_ordering::operator<<;
    std::cout << result << "\n";

    // test mutable structured binding
    auto&& [myfn, myln, myage] = me;
    std::cout << typeid(myfn).name() << "\n" << typeid(myln).name() << "\n" << typeid(myage).name() << "\n";
    myfn = "Andy";
    std::cout << me << "\n";

    auto equal_to_rslt = std::equal_to{}(me, partner);
    std::cout << typeid(equal_to_rslt).name() << "\n";
    std::cout << std::boolalpha << equal_to_rslt << "\n";
    std::cout << std::boolalpha << std::not_equal_to{}(me, partner) << "\n";

    return 0;
}
