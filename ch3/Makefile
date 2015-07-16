#This makefile is for a program called craps

CC = g++
CFLAG = -Wall -g

all : random.o craps.o
	$(CC) $(CFLAG) random.o craps.o -o play

random.o : random.cpp random.h
	$(CC) $(CFLAG) -c random.cpp

# craps.cpp contains the main program
craps.o : craps.cpp random.h
	$(CC) $(CFLAG) -c craps.cpp

clean : 
	$(RM) *.o
