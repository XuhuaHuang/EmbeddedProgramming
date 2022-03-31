#include <iostream>

struct Arg
{
	int i = 1;
	Arg(int _i) : i {_i} {}
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
	Arg g1{ 5 };							 /* instanciation with innitializer_list */
	std::cout << g1.getArg() << std::endl;				/* expecting int& getArg() & */
	std::cout << std::move(g1).getArg() << std::endl;	/* expecting int getArg() && */
	return 0;
}
