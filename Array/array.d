// dmd .\array.d
// .\array.exe

import std.stdio;
import std.algorithm;
import std.range;

void main()
{
    // Let's get going!
    writeln("Hello World!");

    // An example for experienced programmers:
    // Take three arrays, and without allocating
    // any new memory, sort across all the
    // arrays inplace
    int[] arr1 = [4, 9, 7];
    int[] arr2 = [5, 2, 1, 10];
    int[] arr3 = [6, 8, 3];
    sort(chain(arr1, arr2, arr3));
    // write formated line
    writefln("%s\n%s\n%s\n", arr1, arr2, arr3);
}
