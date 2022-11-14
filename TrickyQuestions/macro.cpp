#include <iostream>

#define M(x, y, z) x*y+z

int main(void)
{
    int a = 1, b = 2, c = 3;
    int sum = M(a+b, b+c, a+c);

    // M(a, b, a) = M(1, 2, 1) = 3
    // M(b, c, c) = M(2, 3, 3) = 9
    std::cout << "sum = " << sum << "\n";

    return 0;
}
