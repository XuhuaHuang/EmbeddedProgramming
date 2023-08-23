// https://dlang.org/phobos/std_typecons#Tuple
// dmd use_tuple.d
// use_tuple

import std.stdio;
import std.typecons;

Tuple!(int, int) GetOriginCoordinate()
{
    Tuple!(int, int) origin;
    origin[0] = 0;
    origin[1] = 0;
    return origin;
}

void main()
{
    // std::tuple<int, int>
    Tuple!(int, int) point;

    // assign coordinates
    point[0] = 5;
    point[1] = 6;
    writeln(point[0]);
    writeln(point[1]);

    point = GetOriginCoordinate();
    // read coordinates
    auto x = point[0];
    auto y = point[1];
    writeln(x);
    writeln(y);

    Tuple!(float, "x", float, "y") named_point;
    named_point.x = 7.0f;
    named_point.y = 8.0f;
    assert(named_point.x == 7.0f);
    assert(named_point.y == 8.0f);

    // Note: equivalent to the following:
    struct NamedPoint
    {
        float x;
        float y;
    }

    NamedPoint point_struct;
    point_struct.x = 9.0f;
    point_struct.y = 10.0f;

    point_struct = cast(NamedPoint) named_point;
    writeln(point_struct.x);
    writeln(point_struct.y);
    assert(point_struct.x == 7.0f);
    assert(point_struct.y == 8.0f);

    return;
}
