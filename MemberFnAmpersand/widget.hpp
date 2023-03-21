#include <vector>

struct widget
{
    using data_type = std::vector<double>;

    // reference qualifier overloads
    data_type& data() & { return values; }             // for lvalue widgets, return lvalue
    data_type  data() && { return std::move(values); } // for rvalue widgets, return rvalue

private:
    data_type values;
};
