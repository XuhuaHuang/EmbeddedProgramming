#include "array_size.hpp"

static_assert(1uz == [] {
    bool a[]{{}};
    return array_size(a);
}());
static_assert(3uz == [] {
    int a[]{{}, {}, {}};
    return array_size(a);
}());
static_assert(42uz == [] {
    int a[42]{};
    return array_size(a);
}());

static_assert(0uz == array_size(std::array<bool, 0>{}));
static_assert(3uz == array_size(std::array<int, 3>{}));
static_assert(42uz == array_size(std::array<char, 42>{}));

static_assert(1uz == array_size(std::vector{1}));
static_assert(3uz == array_size(std::vector{1, 2, 3}));
