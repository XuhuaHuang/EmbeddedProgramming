/*****************************************************************//**
 * \file   3_RossVideoTestQuestion.cpp
 * \brief  Contains example questions asked in Ross Video Inc. Test
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

void copyCharArray(char*, const char*);

class Employee
{
private:
    std::string name;
    std::string idNumber;
    std::string department;
    std::string position;
    int yearsWorked;
    bool message = false;

public:
    Employee(std::string n, std::string idNum, std::string depart, std::string pos, int yrsWrkd)
        : name(n),
        idNumber(idNum),
        department(depart),
        position(pos),
        yearsWorked(yrsWrkd) {}

    Employee(std::string n, std::string idNum)
        : name(n),
        idNumber(idNum),
        department(""),
        position(""),
        yearsWorked(0) {}

    Employee()
        : name(""),
        idNumber(""),
        department(""),
        position(""),
        yearsWorked(0) {}

    void setName(std::string n) { name = n; }
    void setIdnumber(std::string idNum) { idNumber = idNum; }
    void setDepartment(std::string depart) { department = depart; }
    void setPos(std::string pos) { position = pos; }

    void setYEARS(int yrsWrkd) {
        if (yrsWrkd < 0)
            std::cout << "Attempt to set yearsWorked for " << name << " was invalid. It was set to 0" << "\n";
        else
            yearsWorked = yrsWrkd;
    }

    std::string const getName() { return name; }
    std::string const getID() { return idNumber; }
    std::string const getDPT() { return department; }
    std::string const getPOS() { return position; }
    int const getYEARS() { return yearsWorked; }

    std::string getName() const { return name; }
    std::string getID() const { return idNumber; }
    std::string getDPT() const { return department; }
    std::string getPOS() const { return position; }
    int getYEARS() const { return yearsWorked; }
};

std::string findPosition(std::list<Employee>, const std::string&);
void printEmployeeInFormat(const Employee&);

int main(void)
{
    /* Determine the value of a */
    int a;
    a = 0xFFFF;
    std::cout << "0xFFFF: " << a << "\n";
    a += 345;
    std::cout << "a += 345: " << a << "\n";

    /* Determine the resultant values of variables */
    long b;
    float c;

    b = 256 >> 2;
    std::cout << "256 >> 2, 0x10000000 >> 2: " << b << "\n";
    c = (b > 0x45) ? 4.5 : 6.7;
    std::cout << "c = (b > 0x45) ? 4.5 : 6.7 " << c << "\n";
    /*
    if (b > 0x45)
        c = 4.5;
    else
        c = 6.7;
    */

    char hello[6] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    char world[6] = { 'w', 'o', 'r', 'l', 'd', '\0' };
    copyCharArray(hello, world);

    for (int i = 0; i < 6; i++)
        printf("Content at hello[%d]: %c\n", i, hello[i]);

    /**
     * class Employee{};
     *
     * \return
     */
    const int NUM = 4;
    Employee emp[NUM] = {
        Employee("Jenny Jacobs", "JJ8990", "Accounting", "President", 15),
        Employee("Myron Smith", "MS7571", "IT", "Programmer", 5),
        Employee("Chris Raines", "CR6873", "Manufacturing", "Engineer", 30)
    };

    emp[1].setYEARS(-1); // invalid attempt; set to 0

    std::cout << "\nHard coded print in main(void)" << "\n"
        << std::setw(16) << std::left << "Name"
        << std::setw(16) << "ID Number"
        << std::setw(16) << "Department"
        << std::setw(16) << "Position"
        << std::setw(16) << "Years Worked" << "\n";

    std::cout << std::setw(16) << std::left << "----"
        << std::setw(16) << "---------"
        << std::setw(16) << "----------"
        << std::setw(16) << "--------"
        << std::setw(16) << "------------" << "\n";

    for (int i = 0; i < NUM; i++)
    {
        std::cout << std::fixed << std::setw(16) << std::left << emp[i].getName()
            << std::setw(16) << emp[i].getID()
            << std::setw(16) << emp[i].getDPT()
            << std::setw(16) << emp[i].getPOS()
            << std::setw(5) << std::right << emp[i].getYEARS() << "\n";
    }

    std::cout << "END OF TESATING CREATED EMPLYEE CLASS\n\n";

    std::list<Employee> employees(emp, emp + sizeof(emp) / sizeof(emp[0]));

    std::cout << "Chris Raines is of position: "
        << findPosition(employees, "Chris Raines") << "\n";

    /* void printEmployeeInFormat(const Employee& emp) */
    std::cout << "\nCalling function to print employee in format" << "\n"
        << "void printEmployeeInFormat(const Employee&)" << "\n"
        << "ex. std::string getName() const {/* code block */}" << "\n";
    printEmployeeInFormat(emp[0]);

    return 0;
}

void copyCharArray(char* destinationArr, const char* sourceArr)
{
    int a;
    for (a = 0; a <= (sizeof(sourceArr) / sizeof(sourceArr[0])); a++)
        *destinationArr++ = *sourceArr++;
}

std::string findPosition(std::list<Employee> emps, const std::string& name)
{
    for (std::list<Employee>::iterator i = emps.begin();
        i != emps.end();
        i++)
    {
        if (i->getName() == name)
        {
            return i->getPOS();
        }
    }
    return "";
}

void printEmployeeInFormat(const Employee& emp)
{
    std::cout << std::setw(16) << left << "Name";
    std::cout << std::setw(16) << "ID Number";
    std::cout << std::setw(16) << "Department";
    std::cout << std::setw(16) << "Position";
    std::cout << std::setw(16) << "Years Worked" << "\n";

    std::cout << std::setw(16) << left << "----";
    std::cout << std::setw(16) << "---------";
    std::cout << std::setw(16) << "----------";
    std::cout << std::setw(16) << "--------";
    std::cout << std::setw(16) << "------------" << "\n";

    std::cout << std::fixed << std::setw(16) << left << emp.getName()
        << std::setw(16) << emp.getID()
        << std::setw(16) << emp.getDPT()
        << std::setw(16) << emp.getPOS()
        << std::setw(5) << right << emp.getYEARS() << "\n";
}