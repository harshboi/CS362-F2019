CFLAGS= -Wall -fpic -coverage -lm -std=c99

all: testme.c
	gcc -o prog testme.c $(CFLAGS)
prog: all
	./prog
