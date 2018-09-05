CC=gcc
CFLAGS=-Wall

all : get_hashcode
get_hashcode :   ./get_hashcode.o
	g++ -o ./get_hashcode.o

get_hashcode.o : get_hashcode.cpp
	g++ -c get_hashcode.cpp

.PHONY : clean
clean :
	find . -name "*.o"  | xargs rm -f
	find . -name "*.exe" | xargs rm -f
