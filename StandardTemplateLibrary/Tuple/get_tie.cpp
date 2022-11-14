#include <iostream>
#include <string>
#include <tuple>
#include <stdexcept>

// tuple<double, char, string> is the return type
// getStudentByID is the name of the function with argument 'ID'
std::tuple<double, char, std::string> getStudentByID(int ID)
{
    switch (ID)
    {
    case 1:
        return std::make_tuple(3.8, 'A', "Lisa Simpon");
        break;
    case 2:
        return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
        break;
    case 3:
        return std::make_tuple(3.0, 'B', "Palph Wiggum");
        break;
    default:
        throw std::invalid_argument("ID");
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

    std::cout << "ID: 1" << "\n"
         << "GPA: " << std::get<0>(student1) << "\n"
         << "Grade: " << std::get<1>(student1) << "\n"
         << "Name: " << std::get<2>(student1) << "\n";

    // with tie() function
    double gpa2; char grade2; std::string name2;
    std::tie(gpa2, grade2, name2) = getStudentByID(2);
    // case2: return make_tuple(2.9, 'C', "Milhouse Van Houten");
    // gpa2 = 2.9	grade2 = C	name2 = Milhouse Van Houten
    // tie() function groups existed variable together to accept
    // the returned tuple from the function

    std::cout << "ID: 2" << "\n"
         << "GPA: " << gpa2 << "\n"
         << "Grade: " << grade2 << "\n"
         << "Name: " << name2 << "\n";
    
    std::cout << "Making new tuples for fun" << "\n";
    int a, b;
    std::tie(a, b) = std::tuple<int, int> { 1,-1 };
    std::cout << a << " , " << b << "\n";

    auto intT = std::make_tuple(2, -2);
    std::cout << std::get<0>(intT) << " , " << std::get<1>(intT) << "\n";
    // get the element indexed 0  in tuple 'intT'

    return 0;
}
