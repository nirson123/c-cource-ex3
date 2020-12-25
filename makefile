CC = gcc
flags = -Wall -g

.PHONY = all clean

all : isort txtfind

isort : isort.c
	$(CC) $(flags) $< -o $@

txtfind : txtfind.c
	$(CC) $(flags) $< -o $@

clean :
	rm isort txtfind