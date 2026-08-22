CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

THREAD_FLAGS = -pthread

PROGRAM = concurrency_demo

TEST_PROGRAM = concurrency_tests


all:
	$(CC) $(CFLAGS) $(THREAD_FLAGS) \
	main.c concurrency.c \
	-o $(PROGRAM)


run: all
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) $(THREAD_FLAGS) \
	test_concurrency.c concurrency.c \
	-o $(TEST_PROGRAM)

	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean