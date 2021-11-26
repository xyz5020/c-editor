CC=clang

default: all

all: kilo.c
	$(CC) kilo.c -o editor -Wall -Wextra -pedantic -std=c99

run: all
	./editor

clean:
	rm editor