CC=g++
CFLAGS=-g -Wall -Wextra -Wpedantic -Wno-pragma-once-outside-header
OPTFLAG=-O2
CXXSTD=-std=c++2b
BOOSTDIR=C:\\boost\\boost_1_82_0
BOOSTUTDIR=C:\\boost\\ut\\include

COMPILECMD=$(CC) $(CFLAGS) $(OPTFLAG) $(CXXSTD) -I $(BOOSTDIR) -I $(BOOSTUTDIR)

# any of header and unit test
any_of_header:any_of.hpp
	$(COMPILECMD) any_of.hpp
any_of_unittest:any_of_unittest.cpp
	$(COMPILECMD) any_of_unittest.cpp -o any_of_unittest
