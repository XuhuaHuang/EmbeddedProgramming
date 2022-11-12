#include <iostream>
#include <string>
#include <tuple>
#include <stdexcept>

using namespace std;

// tuple<double, char, string> is the return type
// getStudentByID is the name of the function with argument 'ID'
tuple<double, char, string> getStudentByID(int ID)
{
    switch (ID)
    {
    case 1:
        return make_tuple(3.8, 'A', "Lisa Simpon");
        break;
    case 2:
        return make_tuple(2.9, 'C', "Milhouse Van Houten");
        break;
    case 3:
        return make_tuple(3.0, 'B', "Palph Wiggum");
        break;
    default:
        throw invalid_argument("ID");
    }
}

int main(void)
{
    // with 'auto'
    auto student1 = getStudentByID(1);
    // auto keyword
    // get<index>(tuple_name)
    // student1 is the returned tuple of function getStudentByID(1)
    // tuple<double, char, string> (tuple_name)
    // index<0>	 <1>   <2>

    cout << "ID: 1" << endl
         << "GPA: " << get<0>(student1) << endl
         << "Grade: " << get<1>(student1) << endl
         << "Name: " << get<2>(student1) << endl;

    // with tie() function
    double gpa2; char grade2; string name2;
    tie(gpa2, grade2, name2) = getStudentByID(2);
    // case2: return make_tuple(2.9, 'C', "Milhouse Van Houten");
    // gpa2 = 2.9	grade2 = C	name2 = Milhouse Van Houten
    // tie() function groups existed variable together to accept
    // the returned tuple from the function

    cout << "ID: 2" << endl
         << "GPA: " << gpa2 << endl
         << "Grade: " << grade2 << endl
         << "Name: " << name2 << endl;
    
    cout << "Making new tuples for fun" << endl;
    int a, b;
    tie(a, b) = tuple<int, int> { 1,-1 };
    cout << a << " , " << b << endl;

    auto intT = make_tuple(2, -2);
    cout << get<0>(intT) << " , " <<get<1>(intT) << endl;
    // get the element indexed 0  in tuple 'intT'

    return 0;
}
