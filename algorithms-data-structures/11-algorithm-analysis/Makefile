CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = algorithm_analysis

TEST_PROGRAM = algorithm_tests


all:
	$(CC) $(CFLAGS) main.c algorithms.c -I. -o $(PROGRAM)


run:
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) tests.c algorithms.c -I. -o $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean