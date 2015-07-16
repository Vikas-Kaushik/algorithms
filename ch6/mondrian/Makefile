CC = g++
DEBUG = -g           # or -g3 -gdwarf2 -o0 for maximum value using gdb
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
DIR_PATH = -I/home/dennis/StanfordCPPLib/cs106lib-0.3.1/CS106/

PROG = draw          # changed for each project
LIB = ./cs106lib.a  # relative path to library file
OBJS = $(PROG).o     # add any other *.o files needed, e.g. maze.o

all : $(PROG)        # plus any other stuff you need, e.g. etags

$(PROG) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LIB)  -o $(PROG) $(DIR_PATH)

#Start server by following - 
# /home/dennis/StanfordCPPLib/cs106lib-0.3.1/gserv/gserv
#Compile file as below - 
# g++ -Wall draw.cpp cs106lib.a -o draw -I/home/dennis/StanfordCPPLib/cs106lib-0.3.1/CS106/
