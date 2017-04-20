OPT = -g
CC = gcc
ifdef THREAD
PTHREAD = -D_REENTRANT -pthread
DEF_THREAD = -DTHREAD
endif

grid: grid.o UnitTests.o
	gcc -o grid grid.o UnitTests.o

grid.o: grid.c
	gcc -o grid.o -c grid.c -W -Wall -ansi -pedantic

UnitTests.o: UnitTests.c grid.h
	gcc -o UnitTests.o -c UnitTests.c -W -Wall -ansi -pedantic