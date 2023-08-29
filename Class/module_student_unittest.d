import std.stdio;
import student;

void main() {
    auto s = Student("Andy", 1879700);
    writeln(s);

    s.name = "Xuhua Huang";

    // s.id = 0;

    writeln(s);
}
