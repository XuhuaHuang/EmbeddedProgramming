// A C++ program uses transform() in STL to
// increment 1 to all elements of arr[]

// std::transform(Iterator inputBegin, Iterator inputEnd, Iterator OutputBegin, function_Name)

#include <iostream>
#include <algorithm>

int increment(int x) { return (x + 1); }

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Apply increment to all elements of 
    // arr[] and store the modified elements 
    // back in arr[] 
    std::transform(arr, arr + n, arr, increment);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    return 0;
}
