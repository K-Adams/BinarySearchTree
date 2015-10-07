CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: bst

bst: bst.o
	$(CC) $(LFLAGS) -o bst bst.o

bst.o: master.h
	$(CC) $(CFLAGS) -c bst.cpp

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf *.dSYM
	rm -rf stack
	rm -rf queue

