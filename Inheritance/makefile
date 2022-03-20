.banking: all clean
all: banking
banking: accounts.o main.o
	g++ accounts.o main.o -o banking
accounts.o: BankingAccounts.cpp BankingAccounts.hpp
	g++ -c BankingAccounts.cpp -o accounts.o
main.o: main.cpp
	g++ -c main.cpp -std=c++98 -o main.o
clean:
	rm -rf *.o
	rm banking
