CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = matrix_demo

TEST_PROGRAM = matrix_tests


all: $(PROGRAM)


$(PROGRAM): main.c matrix.c matrix.h
	$(CC) $(CFLAGS) main.c matrix.c -I. -o $(PROGRAM)


run: $(PROGRAM)
	./$(PROGRAM)


test: $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


$(TEST_PROGRAM): test_matrix.c matrix.c matrix.h
	$(CC) $(CFLAGS) test_matrix.c matrix.c -I. -lm -o $(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean