
#define CPP2_IMPORT_STD Yes

#include "cpp2util.h"


auto main() -> int;

auto hello(cpp2::impl::in<std::string_view> msg) -> void;
auto main() -> int {
  std::vector words{"Alice", "Bob"};
  hello(CPP2_ASSERT_IN_BOUNDS_LITERAL(words, 0));
  hello(CPP2_ASSERT_IN_BOUNDS_LITERAL(cpp2::move(words), 1));
}

auto hello(cpp2::impl::in<std::string_view> msg) -> void {
  std::cout << "Hello, " + cpp2::to_string(msg) + "!\n";
}
