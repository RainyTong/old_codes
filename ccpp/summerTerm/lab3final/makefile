CC=g++
CFLAGS=-Wall
INC = -I ./get_file -I ./get_hashcode -I ./compare
TARGET = lab3_main
SRCS = lab3_main.cpp\
		./get_file/get_file.cpp\
		./get_hashcode/get_hashcode.cpp\
		./compare/compare.cpp\
		./lab3_main.h

OBJS = $(SRCS:.c=.o)
#OBJS += lab3_main.h
$(TARGET) : $(OBJS)
	#echo TARGET:$@
	#echo OBJECTS:$^

	#$(CC) $(CFLAGS) $(INC) -o $@ $^
	$(CC) $(CFLAGS)  -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS)  -o $@ -c $^

.PHONY : clean
clean :
	find . -name "*.o"  | xargs rm -f
	find . -name "*.exe" | xargs rm -f
