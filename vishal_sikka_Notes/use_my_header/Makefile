CC = g++
FLAGS = -g -Wall
SOURCES = my_header.cpp use_my_header.cpp use_my_header.h
OBJECTS = use_my_header.o my_header.o
EXECUTABLE = runnable

all : $(OBJECTS)
	$(CC) $(FLAGS) -o $(EXECUTABLE) $@

my_header.o : my_header.cpp my_header.h
	$(CC) $(FLAGS) -c  my_header.cpp

use_my_header.o : use_my_header.cpp my_header.o
	$(CC) $(FLAGS) -c  $<

clean :
	$(RM) *.o
	$(RM) $(EXECUTABLE)
