// dmd struct_euclidean_vec_unittest.d
// .\struct_euclidean_vec_unittest

import std.stdio;
import std.typecons;

Tuple!(float, "x", float, "y", float, "z") GetOriginCoordinate() {
    Tuple!(float, "x", float, "y", float, "z") result;
    result.x = 0.0f;
    result.y = 0.0f;
    result.z = 0.0f;
    return result;
}

struct euclidean_vec {
    float x;
    float y;
    float z;

    // Define a constructor
    this(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    // Initialize all fields to the same initial value
    this(float val) {
        x = y = z = val;
    }

    // Copy Constructor
    this(ref return scope const euclidean_vec rhs) {
        this.x = rhs.x;
        this.y = rhs.y;
        this.z = rhs.z;
    }

    // Destructor
    ~this() {
        // Do nothing for now
        // Print debuging message if needed
        // All fields' destructor will be called as well
    }

    void Print() {
        writeln(x, ", ", y, ", ", z);
    }
}

void main() {
    writeln(float.init); // nan - not a number

    // Create struct without constructors
    euclidean_vec v;
    v.Print();

    // v = euclidean_vec(1.0f, 2.0f);
    v = euclidean_vec(1.0f, 2.0f, 3.0f);
    v.Print();

    // Following line will not work with explicit defined constructor
    // euclidean_vec v2 = {x: 1.0f, y: 4.0f, z: 9.0f};
    euclidean_vec v2 = euclidean_vec(1.0f, 4.0f, 9.0f);
    v2.Print();

    euclidean_vec v3 = euclidean_vec(10.0f);
    v3.Print();
}
