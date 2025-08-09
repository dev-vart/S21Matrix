CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 # -Wno-unused-parameter -Wno-unused-variable # НЕ ЗАБЫТЬ УБРАТЬ!
SANIFLAGS = -g -O0 -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable
VALFLAGS = --tool=memcheck --leak-check=yes --track-origins=yes
LIBS = $(shell pkg-config --libs check)
# LIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
SRCFILES = $(wildcard core/s21_*.c) $(wildcard addon/s21_*.c)
OBJFILES = $(notdir $(SRCFILES:.c=.o))
TESTFILES = $(wildcard tests/city.c)

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

##### TESTS #####

test: clean test_create1 test_create2 tests/city.o s21_matrix.a
	$(CC) tests/city.o s21_matrix.a $(LIBS) -o tests/$@
	./tests/$@

tests: test

test_create1: tests/city_create1.o
	$(CC) $(CFLAGS) -c -D USE_FAKE_MALLOC core/s21_create_matrix.c -o s21_create_matrix1.o
	$(CC) $< s21_create_matrix1.o $(LIBS) -o tests/$@
	./tests/$@
	@bash -c 'read -n 1 -s -p "Нажмите любую клавишу для продолжения..."'
	@echo

test_create2: tests/city_create2.o
	$(CC) $(CFLAGS) -c -D USE_FAKE_CALLOC core/s21_create_matrix.c -o s21_create_matrix2.o
	$(CC) $< s21_create_matrix2.o $(LIBS) -o tests/$@
	./tests/$@
	@bash -c 'read -n 1 -s -p "Нажмите любую клавишу для продолжения..."'
	@echo

tests/city.o: tests/city.c
	$(CC) $(CFLAGS) -c $< -o $@

tests/city.c:
	checkmk clean_mode=1 tests/city.check > $@

tests/city_create1.o: tests/city_create1.c
	$(CC) $(CFLAGS) -c $< -o $@

tests/city_create1.c:
	checkmk clean_mode=1 tests/city_create1.check > $@

tests/city_create2.o: tests/city_create2.c
	$(CC) $(CFLAGS) -c $< -o $@

tests/city_create2.c:
	checkmk clean_mode=1 tests/city_create2.check > $@

#################

gcov_report: tests/city_create1.c tests/city_create2.c tests/city.c $(SRCFILES)
	mkdir -p gcov_report
	$(CC) $(CFLAGS) --coverage -D USE_FAKE_MALLOC core/s21_create_matrix.c tests/city_create1.c -o gcov_report/s21_test_create1 $(LIBS)
	$(CC) $(CFLAGS) --coverage -D USE_FAKE_CALLOC core/s21_create_matrix.c tests/city_create2.c -o gcov_report/s21_test_create2 $(LIBS)
	$(CC) $(CFLAGS) --coverage $(SRCFILES) tests/city.c -o gcov_report/s21_test $(LIBS)
	cd gcov_report
	./gcov_report/s21_test_create1
	./gcov_report/s21_test_create2
	./gcov_report/s21_test
	gcov -l -p -c *.gcno
	-rm -rf s21_test-asd*
	gcovr -e "tests/*" --html --html-details -o gcov_report/gcov_report.html
	open gcov_report/gcov_report.html 

clangn:
	clang-format-18 -n $(SRCFILES) *.h */*.h

clangi:
	clang-format-18 -i $(SRCFILES) *.h */*.h

rebuild: clean all 

clean:
	-rm -rf *.o && rm -rf */*.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./tests/test && rm -rf ./gcov_report
	-rm -rf ./tests/test*
	-rm -rf ./report/
	-rm -rf s21_test
	-rm -rf tests/*.o tests/*.c
	-rm -rf gcov*
	-rm -rf a.out
	-rm -rf val
	-rm -rf debug
	-rm -rf gdb
	-rm -rf minitest
	-rm -rf sani

clear: clean

.PHONY: s21_matrix.a test debug val sani minitest