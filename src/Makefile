CC = gcc
CCFLAGS = -c -Wall -Werror -Wextra -std=c11 -Wno-unused-parameter # НЕ ЗАБЫТЬ УБРАТЬ!
CFLAGS=$(shell pkg-config --cflags check)
LIBS = $(shell pkg-config --libs check)
SOURCE = $(wildcard core/s21_*.c)

all: s21_matrix.a

s21_matrix.a: $(SOURCE)
	$(CC) $(CCFLAGS) $(SOURCE) 
	ar rc s21_matrix.a s21_*.o 
	ranlib s21_matrix.a

test_c:
	$(CC) $(CFLAGS) core/*.c addon/*.c tests/test.c -o test
	./test

test: clean tests/city.o s21_matrix.check
	$(CC) -o test tests/city.o s21_matrix.a $(LIBS)
	./test

s21_matrix.check: $(SOURCE)
	$(CC) $(CCFLAGS) $(CFLAGS) $(SOURCE) 
	ar rc s21_matrix.a s21_*.o 
	ranlib s21_matrix.a

tests/city.o: tests/city.c
	$(CC) $(CFLAGS) -c tests/city.c -o tests/city.o

tests/city.c:
	checkmk clean_mode=1 tests/city.check > tests/city.c

rebuild: clean all 

clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/
	-rm -rf s21_test
	-rm -rf tests/*.o tests/city.c
	-rm -rf gcov*

.PHONY: s21_matrix.a test test_c