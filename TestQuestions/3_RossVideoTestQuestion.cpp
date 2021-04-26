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

using namespace std;

void copyCharArray(char*, const char*);

class Employee
{
private:
	string name;
	string idNumber;
	string department;
	string position;
	int yearsWorked;
	bool message = false;

public:
	Employee(string n, string idNum, string depart, string pos, int yrsWrkd)
		: name(n),
		idNumber(idNum),
		department(depart),
		position(pos),
		yearsWorked(yrsWrkd) {}

	Employee(string n, string idNum)
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

	void setName(string n) { name = n; }
	void setIdnumber(string idNum) { idNumber = idNum; }
	void setDepartment(string depart) { department = depart; }
	void setPos(string pos) { position = pos; }

	void setYEARS(int yrsWrkd) {
		if (yrsWrkd < 0)
			cout << "Attempt to set yearsWorked for " << name << " was invalid. It was set to 0" << endl;
		else
			yearsWorked = yrsWrkd;
	}

	string const getName() { return name; }
	string const getID() { return idNumber; }
	string const getDPT() { return department; }
	string const getPOS() { return position; }
	int const getYEARS() { return yearsWorked; }

	string getName() const { return name; }
	string getID() const { return idNumber; }
	string getDPT() const { return department; }
	string getPOS() const { return position; }
	int getYEARS() const { return yearsWorked; }
};

string findPosition(list<Employee>, const string&);
void printEmployeeInFormat(const Employee&);

int main(void)
{
	/* Determine the value of a */
	int a;
	a = 0xFFFF;
	cout << "0xFFFF: " << a << endl;
	a += 345;
	cout << "a += 345: " << a << endl;

	/* Determine the resultant values of variables */
	long b;
	float c;

	b = 256 >> 2;
	cout << "256 >> 2, 0x10000000 >> 2: " << b << endl;
	c = (b > 0x45) ? 4.5 : 6.7;
	cout << "c = (b > 0x45) ? 4.5 : 6.7 " << c << endl;
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

	cout << "\nHard coded print in main(void)" << endl
		 << setw(16) << left << "Name"
		 << setw(16) << "ID Number"
		 << setw(16) << "Department"
		 << setw(16) << "Position"
		 << setw(16) << "Years Worked" << endl;

	cout << setw(16) << left << "----"
		 << setw(16) << "---------"
		 << setw(16) << "----------"
		 << setw(16) << "--------"
		 << setw(16) << "------------" << endl;

	for (int i = 0; i < NUM; i++)
	{
		cout << fixed << setw(16) << left << emp[i].getName()
			<< setw(16) << emp[i].getID()
			<< setw(16) << emp[i].getDPT()
			<< setw(16) << emp[i].getPOS()
			<< setw(5) << right << emp[i].getYEARS() << endl;
	}

	cout << "END OF TESATING CREATED EMPLYEE CLASS\n\n";

	std::list<Employee> employees(emp, emp + sizeof(emp) / sizeof(emp[0]));
	
	cout << "Chris Raines is of position: " 
		 << findPosition(employees, "Chris Raines") << endl;

	/* void printEmployeeInFormat(const Employee& emp) */
	cout << "\nCalling function to print employee in format" << endl
		 << "void printEmployeeInFormat(const Employee&)" << endl
		 << "ex. string getName() const {/* code block */}" << endl;
	printEmployeeInFormat(emp[0]);

	return 0;
}

void copyCharArray(char* destinationArr, const char* sourceArr)
{
	int a;
	for (a = 0; a <= (sizeof(sourceArr) / sizeof(sourceArr[0])); a++)
		*destinationArr++ = *sourceArr++;
}

string findPosition(list<Employee> emps, const string& name)
{
	for (list<Employee>::iterator i = emps.begin();
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
	cout << setw(16) << left << "Name";
	cout << setw(16) << "ID Number";
	cout << setw(16) << "Department";
	cout << setw(16) << "Position";
	cout << setw(16) << "Years Worked" << endl;

	cout << setw(16) << left << "----";
	cout << setw(16) << "---------";
	cout << setw(16) << "----------";
	cout << setw(16) << "--------";
	cout << setw(16) << "------------" << endl;

	cout << fixed << setw(16) << left << emp.getName()
		 << setw(16) << emp.getID()
		 << setw(16) << emp.getDPT()
		 << setw(16) << emp.getPOS()
		 << setw(5) << right << emp.getYEARS() << endl;
}