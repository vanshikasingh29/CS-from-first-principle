CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = memory_management

TEST_PROGRAM = memory_tests


all:
	$(CC) $(CFLAGS) main.c memory_management.c -o $(PROGRAM)


run:
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) \
	test_memory_management.c \
	memory_management.c \
	-o $(TEST_PROGRAM)

	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean