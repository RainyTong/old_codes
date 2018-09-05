CC=gcc
CFLAGS=-Wall
INC = -I ./get_file -I ./get_hashcode -I ./compare
all : lab3_main
lab3_main : lab3_main.o ./get_file/get_file.o  ./get_hashcode/get_hashcode.o ./compare/compare.o
	g++ -o lab3_main lab3_main.o ./get_file/get_file.o  ./get_hashcode/get_hashcode.o ./compare/compare.o

get_file.o : get_file.c
	g++ -c get_file.c
get_hashcode.o : get_hashcode.c
	g++ -c get_hashcode.c
lab3_main.o :lab3_main.c
	g++ -c lab3_main.c
compare.o :compare.c
	g++ -c compare.c
.PHONY : clean
clean :
	find . -name "*.o"  | xargs rm -f
	find . -name "*.exe" | xargs rm -f
