CC = gcc
CFLAG = -fPIC -fprofile-arcs -ftest-coverage

simple: simple.h simple.c
	@$(CC) $(CFLAG) -Wall -Wextra -Wshadow -Werror -std=c99 -pedantic -g -DDEBUG test_simple.c simple.c

run-simple: simple
	@./a.out

clean: ## Clean all generate files
	@rm -rf *.out *.dSYM *.gcda *.gcno *.gcov gcovr-report/*

coverage:
	@gcov simple.c test_simple.c

coverage-report: coverage ## Generate gcovr report
	@mkdir -p gcovr-report
	@gcovr --root . --html --html-details --output gcovr-report/coverage.html

deps: ## Install dependencies
	@pip install gcovr
