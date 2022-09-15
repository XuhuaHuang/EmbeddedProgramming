// Modified program using class - C++ only
#include <iostream>

using namespace std;

class GreaterSmaller 
{
public:
    int greater, smaller;
};

// function takes two integers value and returns an object of class "GreaterSmaller"
GreaterSmaller findGreaterSmaller(int a, int b)
{
    GreaterSmaller result;
    if (a > b)
    {
        result.greater = a;
        result.smaller = b;
    }
    else
    {
        result.greater = b;
        result.smaller = a;
    }

    return result;
}

// Driver code 
int main()
{
    int num1, num2;

    cout << "Enter the first number of two to compare: ";
    cin >> num1;
    cout << "Enter the second number of two to compare: ";
    cin >> num2;

    // calling function
    // arguments: int, int
    // return type: GreaterSmaller
    GreaterSmaller result = findGreaterSmaller(num1, num2);
    
    // 'greater' and 'smaller' are public variable inside of class 'GreaterSmaller'
    cout << "\nThe greater number is: " << result.greater << endl
         << "The smaller number is: " << result.smaller << endl;

    return 0;
}
