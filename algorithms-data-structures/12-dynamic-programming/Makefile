CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = dynamic_programming

TEST_PROGRAM = dynamic_programming_tests


all:
	$(CC) $(CFLAGS) main.c dynamic_programming.c -I. -o $(PROGRAM)


run:
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) test_dynamic_programming.c dynamic_programming.c -I. -o $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean