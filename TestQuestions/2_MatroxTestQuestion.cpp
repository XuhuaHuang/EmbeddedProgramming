/*****************************************************************//**
 * \file   2_MatroxTestQuestion.cpp
 * \brief  Interesting questions during test provided by Matrox
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include <iostream>
using namespace std;

class SpecialString
{
public:

	SpecialString(const char* pStr)
	{
		int size = strlen(pStr) + 1;
		m_pData = new char[size];
		strcpy_s(m_pData, size, pStr);
	}

	~SpecialString()
	{
		delete[] m_pData;
	}

	void Reverse()
	{
		// Suppose this method is defined and that it reverses the order of the  
		// characters in the string by accessing m_pData, for example "abc" would be 
		// changed to "cba"
	}

	const char* GetDataPointer() const
	{
		return m_pData;
	}

private:
	char* m_pData;
};

void DisplayString(const SpecialString& x)
{
	// This code displays the string, not the pointer value !
	cout << x.GetDataPointer() << endl;
}

int main()
{
	SpecialString MyStr("abcdefghiklmnopqrstuvwxyz");
	DisplayString(MyStr);
	MyStr.Reverse();
	DisplayString(MyStr);
	
	/* MEMORY ALLIGNMENT */
	float a = 0.001;
	float b = 0.003;
	float c, * pa, * pb;
	float* p;

	pa = &a;
	*pa = 2 * a;
	pb = &b;
	c = 4 * (*pb - *pa);
	p = pb + 1;

	cout << a << " " << b << " " << c << endl
		 << (int)&a << " " << (int)&b << " " << (int)&c << endl
		 << (int)pa << " " << *pa << " " << (int)&(*pa) << endl
		 << (int)pb << " " << *pb << endl;
	// 	 << (int)p << " " << (int)*p << endl; // undefined behaviour
	
	return 0;
}
