all:gamepromotion.o main.o
	g++ gamepromotion.o main.o -o gamepromotion.exe
gamepromotion.o:GamePromotion.cpp GamePromotion.h
	g++ -c GamePromotion.cpp
main.o:GamePromotion_main.cpp GamePromotion.h
	g++ -c GamePromotion_main.cpp -o main.o -std=c++11
clean:
	rm -rf *.o
	rm *.exe
