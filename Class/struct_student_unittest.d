// dmd struct_student_unittest.d
// .\struct_student_unittest

// struct are allocated on stack by default
// struct does not allow inheritance

import std.stdio;

struct Student {
  align:
    int id;     // placed at offset 0
    int age;    // placed at offset 4

    // Member function
    void Print() {
        writeln("id: ", id, " age: ", age);
    }
}

// Check struct alignment at compile-time
static assert(Student.alignof == 4);
static assert(Student.age.offsetof == 4);
static assert(Student.sizeof == 8);

// Example of using a struct to return an aggregate of 2 integers
Student CreateStudent(int age, int id) {
    Student s;
    s.age = age;
    s.id = id;

    return s;
}

// Reset instance of Student by taking a mutable reference to such instance
void ResetStudent(ref Student s) {
    s.id = 0000;
    s.age = 0000;
}

void main() {
    Student andy;

    andy.id = 1879700;
    andy.age = 22;

    // writeln(andy.id, " ", andy.age);
    andy.Print();

    ResetStudent(andy);
    andy.Print();

    // Array of 10 students
    Student[10] students;
    foreach(student; students) {
        writeln(student.id, " ", student.age);
    }

    // Introspection
    foreach(i, ref fields; andy.tupleof) {
        writeln(__traits(identifier, andy.tupleof[i]));
    }
}
