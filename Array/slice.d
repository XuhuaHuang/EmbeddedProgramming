// dmd .\slice.d
// .\slice.exe

import std.stdio : writeln;

void main()
{
    int[] test = [ 3, 9, 11, 7, 2, 76, 90, 6 ];
    test.writeln;
    writeln("First element: ", test[0]);
    writeln("Last element: ", test[$ - 1]);
    writeln("Exclude the first two elements: ",
        test[2 .. $]);

    writeln("Slices are views on the memory:");
    auto test2 = test;
    auto subView = test[3 .. $];
    test[] += 1; // increment each element by 1
    test.writeln;
    test2.writeln;
    subView.writeln;

    // Create an empty slice
    assert(test[2 .. 2].length == 0);
}
