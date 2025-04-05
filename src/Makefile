CC = gcc
CFLAGS = -c -Wall -Werror -Wextra -std=c11

all: test

test:
	$(CC) $(CFLAGS) -o test core/*.c tests/test.c
	./test

rebuild: clean all 

clean:

