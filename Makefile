CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wpedantic -std=c18

.PHONY: all clean

all: s10e02 s10e03 s10e04

s10e02: s10e02.c

s10e03: s10e03.c

s10e04: s10e04.c

clean:
	rm s10e02 s10e03 s10e04
