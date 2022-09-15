#include <iostream>
#include <cmath>

int main(void)
{
    using namespace std;

    cout << "\nConditional Operation" << endl;
    int x = 1, y = 3;
    int result = (y - x) > 0 ? y - x : x - y;
    cout << result << endl;

    /*
    if (y - x > 0)
        result = y - x;
    else
        result = x - y;
    */

    // nested conditional operation
    cout << "\nNested conditional operation" << endl;
    int signX = determineSign(x);
    cout << signX << endl;

    return 0;
}

int determineSign(int num)
{
    return (num > 0 ? 1 : (n < 0 ? -1 : 1)); // return +1 if positive, -1 if negative, 0 if zero
}
