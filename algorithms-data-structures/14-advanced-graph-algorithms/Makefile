CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = graph_algorithms

TEST_PROGRAM = graph_tests


all:
	$(CC) $(CFLAGS) main.c graph_algorithms.c -I. -o $(PROGRAM)


run:
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) test_graph_algorithms.c graph_algorithms.c -I. -o $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean