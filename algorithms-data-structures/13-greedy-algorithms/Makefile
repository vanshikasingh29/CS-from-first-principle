CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = greedy_algorithms

TEST_PROGRAM = greedy_tests


all:
	$(CC) $(CFLAGS) main.c greedy_algorithms.c -I. -o $(PROGRAM)


run:
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) test_greedy_algorithms.c greedy_algorithms.c -I. -o $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean