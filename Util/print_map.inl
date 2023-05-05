#include <format>
#include <string_view>

void print_map(const auto& map, const std::string_view key_desc = "key", const std::string_view value_desc = "value")
{
    for (const auto& [k, v] : map)
    {
        // std::puts(std::format("{}: '{}', {}: '{}'", key_desc, k, value_desc, v).c_str());
        // std::string s = std::format("I'd rather be {1} than {0}.", "right", "happy");
        // s == "I'd rather be happy than right."
        std::print("{}: '{}', {}: '{}'", key_desc, k, value_desc, v);
    }
}
