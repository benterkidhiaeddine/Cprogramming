CC = gcc
OPTIONS = -Wall -pedantic -ansi

.PHONY: all clean
all: nl
clean:
	rm -f *.out
%:%.c
	$(CC) $(OPTIONS) $< -o $@.out
