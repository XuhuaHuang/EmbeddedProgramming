all: mytime.o mytimemain.o
  g++ mytime.o mytimemain.o -o exec
mytime.o:mytime.cpp mytime.h
  g++ -c mytime.cpp
mytimemain.o:mytimemain.cpp mytime.h
  g++ -c mytimemain.cpp
clean:
  rm -rf *o
  rm exec
