/*****************************************************************//**
 * \file   lab_Schedule.cpp
 * \brief  problem 1 with default arguments with example class Schedule
 *
 * \author Xuhua
 * \date   November 2020
 *********************************************************************/

#include <iostream>
#include <string>

class Schedule
{
public:

    // set and get functions
    void setCourseName(std::string userCourseName) { courseName = userCourseName; }
    std::string getCourseName() { return courseName; }

    void setStudentID(int userStudentID) { studentID = userStudentID; }
    int getStudentID() { return studentID; }

    // other function prototype
    void setInfo(std::string userCourseName = "Unknown", int userStudentID = 0);
    void printSchedule() {
        std::cout << "\nCourse " << courseName
            << " is assigned to student " << studentID << "." << "\n";
    }

private:
    std::string courseName;
    int studentID;
};

void Schedule::setInfo(std::string userCourseName, int userStudentID)
{
    setCourseName(userCourseName);
    setStudentID(userStudentID);
}

int main(void)
{
    // test case 1
    // pass setInfo() both courseName and studentID
    Schedule fall2020;
    fall2020.setInfo("Embedded Programming", 1879700);
    fall2020.printSchedule();

    // test case 2
    // do not pass any arguments
    Schedule emptySchedule;
    emptySchedule.setInfo();
    emptySchedule.printSchedule(); // 'Unknown' and 0

    // test case 3
    // pass only the courseName
    Schedule courseNameOnly;
    courseNameOnly.setInfo("Final project I");
    courseNameOnly.printSchedule(); // studentID is default to 0

    return 0;
}
