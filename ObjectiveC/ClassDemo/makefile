all:Person.o main.o
	gcc Person.o main.o -o exec
Person.o:Person.m Person.h
	gcc -I "C:\GNUstep\GNUstep\System\Library\Headers" -L "C:\GNUstep\GNUstep\System\Library\Libraries" -o Person.o Person.m -lobjc -lgnustep-base -fconstant-string-class=NSConstantString
main.o:main.m Person.h
	gcc -I "C:\GNUstep\GNUstep\System\Library\Headers" -L "C:\GNUstep\GNUstep\System\Library\Libraries" -o main.o main.m -lobjc -lgnustep-base -fconstant-string-class=NSConstantString
