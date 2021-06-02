/*****************************************************************//**
 * \file   learn_singletons.cpp
 * \brief  contains notes and example on singletons design pattern
 *  single instance of a class/struct that is only intended to have one
 *  for example, a random number generator class
 *
 * \author Xuhua Huang
 * \date   June 2021
 *********************************************************************/

#include <iostream>

using namespace std;

class Singleton
{
public:
	// to prevent having additional copy of the instance
	// mark copy constructor as delete, required C++ 17
	Singleton(const Singleton& instance) = delete;

	static Singleton& getInstance() {
		return s_Instance;
	}

	void printInstance() {
		cout << "Singleton::printInstance()" << endl;
	}

private:
	// private constructor to restrict instantiation of class
	Singleton() {}

	float m_Member_data = 0.0f;

	static Singleton s_Instance;
};

/* Definition of static member */
Singleton Singleton::s_Instance;

/* Example: random number generator class */
class Random
{
public:
	Random(const Random& instance) = delete;

	static Random& getInstance() {
		static Random s_Instance; // in static memory, application lifetime
		return s_Instance;
	}

	float getRandom() {
		return m_Random_float;
	}

private:
	Random() {}

	// replace the value of this member with a random number generator
	float m_Random_float = 1.00f; 
	
	// static Random s_Instance; // moved to line 49
};

/* [Original] definition of static member */
// Random Random::s_Instance; // moved to line 49

int main(void)
{
	/**
	 * use public function inside singleton class to get instance
	 * and call function to print out instance
	 *
	 * mis-use case:
	 * Singleton my_instance = Singleton::getInstance(); // additional copy
	 * my_instance.printInstance();
	 */
	Singleton::getInstance().printInstance();

	/**
	 * Teat cases for class Random.
	 */
	float myRandomFloat = Random::getInstance().getRandom();
	printf("%.2f\n", myRandomFloat); // 1.00

	// another use case
	auto& random = Random::getInstance();
	printf("%.2f\n", random.getRandom()); // 1.00

	return 0;
}