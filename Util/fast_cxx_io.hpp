#ifndef FAST_CXX_IO_HPP
#define FAST_CXX_IO_HPP

static const int _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#endif // !FAST_CXX_IO_HPP