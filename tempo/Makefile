CC = g++
CFLAG = -Wall -g

all : my.o my_interface.o
	$(CC) $(CFLAG) my.o my_interface.o -lm

my_interface : my_interface.cpp my_interface.h
	$(CC) $(CFLAG) -c my_interface.cpp -o my_interface

my : my.cpp my_interface.o
	$(CC) $(CFLAG) -c my.cpp -o my

clean : 
	$(RM) my.o
	$(RM) my_interface.o

