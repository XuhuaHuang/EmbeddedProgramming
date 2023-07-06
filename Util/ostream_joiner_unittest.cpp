#include "ostream_joiner.hpp"

#include <array>
#include <boost/ut.hpp>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    using namespace boost::ut;
    using std::literals::string_literals::operator""s;
    using util::data_structure::ostream_joiner;

    "ostream joiner"_test = [] {
        should("produce an empty") = [stream = std::stringstream{}, v = std::vector<int>{}] {
            std::copy(std::cbegin(v), std::cend(v), ostream_joiner{mut(stream), ""});
            expect(stream.str() == ""s);
        };

        should("join vector elements") = [stream = std::stringstream{}, v = std::vector{'a', 'b', 'c'}] {
            std::copy(std::cbegin(v), std::cend(v), ostream_joiner{mut(stream), ""});
            expect(stream.str() == "abc"s);
        };

        should("join vector elements with comma") = [stream = std::stringstream{}, v = std::vector{1, 2, 3}] {
            std::copy(std::cbegin(v), std::cend(v), ostream_joiner{mut(stream), ", "});
            expect(stream.str() == "1, 2, 3"s);
        };

        should("join array elements with pipe") = [stream = std::stringstream{}, v = std::array{"ab", "cd"}] {
            std::copy(std::cbegin(v), std::cend(v), ostream_joiner{mut(stream), " | "});
            expect(stream.str() == "ab | cd"s);
        };
    };
}
