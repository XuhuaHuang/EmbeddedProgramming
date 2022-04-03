.timeDate: all clean
all: timeDate
timeDate: main.o classDecl.o fn.o
	g++ -o timeDate main.o fn.o classDecl.o
main.o: lab_Time_Date_main.cpp
	g++ -c lab_Time_Date_main.cpp -o main.o -std=c++11
classDecl.o: lab_Time_Date.hpp
	g++ -c lab_Time_Date.hpp -o classDecl.o -std=c++11
fn.o:
	g++ -c lab_Time_Date.cpp -o fn.o -std=c++11
clean:
	rm -f *.o timeDate