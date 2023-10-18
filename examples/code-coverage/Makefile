CC	= gcc
CFLAG = -fPIC -fprofile-arcs -ftest-coverage

simple: simple.h simple.c
	$(CC) $(CFLAG) -Wall -Wextra -Wshadow -Werror -std=c99 -pedantic -g -DDEBUG test_simple.c simple.c

run-simple: simple
	./a.out

clean:
	rm -rf a.out a.out.dSYM

coverage:
	gcov simple.c test_simple.c

coverage-report: coverage ## Generate gcovr report
	mkdir gcovr-report
	gcovr --root . --html --html-details --output gcovr-report/coverage.html

deps: ## Install dependencies
	pip install gcovr

clean: ## Clean all generate files
	$(RM) main *.out *.o *.so *.gcno *.gcda *.gcov lcov-report gcovr-report
