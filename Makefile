CC=gcc
CFLAGS=-Wall -g

clean-all:
	rm -f ex1
	rm -f ex3

clean-1:
	rm -f ex1

clean-3:
	rm -f ex3

all:
	gcc -Wall -g ex1.c -o ex1
	gcc -Wall -g ex3.c -o ex3