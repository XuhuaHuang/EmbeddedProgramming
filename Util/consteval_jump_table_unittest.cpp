
#include "consteval_jump_table.hpp"

int main(void)
{
    using util::data_structure::dispatch;

    static_assert(1 == dispatch(1));
    static_assert(7 == dispatch(7));
    static_assert(23 == dispatch(23));

    return 0;
}
