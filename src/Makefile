CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 # -Wno-unused-parameter -Wno-unused-variable # НЕ ЗАБЫТЬ УБРАТЬ!
SANIFLAGS = -g -O0 -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable
VALFLAGS = --tool=memcheck --leak-check=yes --track-origins=yes
LIBS = $(shell pkg-config --libs check)
# LIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
SRCFILES = $(wildcard core/s21_*.c) $(wildcard addon/s21_*.c)
OBJFILES = $(notdir $(SRCFILES:.c=.o))
TESTFILES = $(wildcard tests/*.c)

all: s21_matrix.a

s21_matrix.a: $(OBJFILES)
	ar rc $@ $(OBJFILES)
	ranlib $@

%.o: core/%.c
	$(CC) -c $(CFLAGS) $<

%.o: addon/%.c
	$(CC) -c $(CFLAGS) $<

# target for vscode task - do not use manually
debug:
	$(CC) -g $(CFLAGS) $(SRCFILES) -o debug

sani:
	$(CC) $(SANIFLAGS) $(SRCFILES) $(TESTFILES) $(LIBS) -o $@ && ./$@

val:
	$(CC) -g $(CFLAGS) $(SRCFILES) $(TESTFILES) $(LIBS) -o $@
	valgrind $(VALFLAGS) ./$@

minitest:
	$(CC) $(CFLAGS) $(SRCFILES) -o $@
	./$@

test: clean tests/city.o s21_matrix.a
	$(CC) tests/city.o s21_matrix.a $(LIBS) -o $@
	./$@

tests: test

tests/city.o: tests/city.c
	$(CC) $(CFLAGS) -c tests/city.c -o $@

tests/city.c:
	checkmk clean_mode=1 tests/city.check > tests/city.c

gcov_report: tests/city.c $(SRCFILES)
	mkdir -p gcov_report
	$(CC) $(CFLAGS) --coverage $(SRCFILES) tests/city.c -o gcov_report/s21_test $(LIBS)
	cd gcov_report
	./gcov_report/s21_test
	gcov -l -p -c *.gcno
	-rm -rf s21_test-asd*
	gcovr -e "tests/*" --html --html-details -o gcov_report/gcov_report.html
	open gcov_report/gcov_report.html 

clangn:
	clang-format-18 -n $(SRCFILES) *.h

clangi:
	clang-format-18 -i $(SRCFILES) *.h

rebuild: clean all 

clean:
	-rm -rf *.o && rm -rf */*.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/
	-rm -rf s21_test
	-rm -rf tests/*.o tests/city.c
	-rm -rf gcov*
	-rm -rf a.out
	-rm -rf val
	-rm -rf debug
	-rm -rf gdb
	-rm -rf minitest
	-rm -rf sani

clear: clean

.PHONY: s21_matrix.a test debug val sani minitest