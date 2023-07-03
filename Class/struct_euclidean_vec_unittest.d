import std.stdio;

struct euclidean_vec {
    float x;
    float y;
    float z;

    void Print() {
        writeln(x, ", ", y, ", ", z);
    }
}

void main() {
    writeln(float.init); // nan - not a number

    // Create struct without constructors
    euclidean_vec v;
    v.Print();

    v = euclidean_vec(1.0f, 2.0f);
    v.Print();

    euclidean_vec v2 = {x: 1.0f, y: 4.0f, z: 9.0f};
    v2.Print();
}
