all:gamepromotion.o main.o
	g++ gamepromotion.o main.o -o gamepromotion.exe
gamepromotion.o:GamePromotion.cpp GamePromotion.hpp
	g++ -c GamePromotion.cpp
main.o:main.cpp GamePromotion.hpp
	g++ -c main.cpp -o main.o -std=c++11
clean:
	rm -rf *.o
	rm *.exe
