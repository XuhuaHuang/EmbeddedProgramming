#include <iostream>

struct Arg
{
	int i = 1;
	int getArg()&& {
		std::cout << "In member function int getArg() &&" << std::endl;
		return i;
	}

	int& getArg()& {
		std::cout << "In member function int& getArg() &" << std::endl;
		return i;
	}
};

int main(void)
{
	Arg g1{ 5 };
	// expecting int& getArg() &
	std::cout << g1.getArg() << std::endl;
	// expecting int getArg() &&
	std::cout << std::move(g1).getArg() << std::endl;
	return 0;
}