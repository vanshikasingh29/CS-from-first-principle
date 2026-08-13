CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = bit_arithmetic

TEST_PROGRAM = bit_tests


all:
	$(CC) $(CFLAGS) main.c bit_arithmetic.c -I. -o $(PROGRAM)


run:
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) \
	test_bit_arithmetic.c \
	bit_arithmetic.c \
	-I. \
	-o $(TEST_PROGRAM)

	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean