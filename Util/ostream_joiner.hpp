#ifndef OSTREAM_JOINER_HPP
#define OSTREAM_JOINER_HPP

#include <iosfwd>
#include <string_view>

namespace util
{
namespace data_structure
{

struct ostream_joiner
{
    ostream_joiner(std::ostream& s, std::string_view separator)
        : s{s}
        , separator{separator}
    {
    }

    auto& operator++() { return *this; }
    auto& operator*() { return *this; }

    auto& operator=(auto&& anything)
    {
        if (emit_separator)
        {
            s << separator;
        }
        else
        {
            emit_separator = true;
        }
        s << std::forward<decltype(anything)>(anything);
        return *this;
    }

private:
    std::ostream&          s;
    const std::string_view separator;
    bool                   emit_separator{false};
};

} // namespace data_structure
} // namespace util

#endif // !OSTREAM_JOINER_HPP
