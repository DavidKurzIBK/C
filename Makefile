CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -std=c18

.PHONY: all clean

all: s08e03 s08e04.c s08e05 s08e06

s08e03: s08e03.c

LDLIBS=-lm

s08e04: s08e04.c

s08e05: s08e05.c

s08e06: s08e06.c

clean:
	rm s08e03 s08e04 s08e05 s08e06
