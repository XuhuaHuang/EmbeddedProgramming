CC=gcc
CFLAGS=-g -Wall
OPTFLAG=-O2

.twelvedays: all clean
all: twelvedays
twelvedays: TwelveDays.cpp
	$(CC) $(CFLAGS) $(OPTFLAG) -c TwelveDays.cpp -o twelvedays.exe

clean:
	rm -f *.exe *.o
