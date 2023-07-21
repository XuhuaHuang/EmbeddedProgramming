#include "design_by_introspection_sys.hpp"

#include <boost/ut.hpp>

int main()
{
    using namespace boost::ut;
    using util::sys;

    "should not trade since there is no condition set"_test = [] {
        sys sys{};
        struct
        {
            int price = 42;
        } trade;
        expect(not sys.process(trade));
    };

    "should not trade since condition doesn't match"_test = [] {
        sys sys{};
        sys.process([](auto price) { return price > 100; });
        struct
        {
            int price = 42;
        } trade;
        expect(not sys.process(trade));
    };

    "should trade since condition matches"_test = [] {
        sys sys{};
        sys.process([](auto price) { return price > 100; });
        struct
        {
            int price = 142;
        } trade;
        expect(sys.process(trade));
    };

    "should only trade on the second condition"_test = [] {
        sys sys{};
        struct
        {
            int price = 42;
        } trade;

        sys.process([](auto price) { return price == 100; });
        expect(not sys.process(trade));

        sys.process([](auto price) { return price == 42; });
        expect(sys.process(trade));
    };

    return 0;
}
