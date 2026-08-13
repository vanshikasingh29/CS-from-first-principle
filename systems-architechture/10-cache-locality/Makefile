CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -O2 -g

PROGRAM = cache_benchmark

TEST_PROGRAM = cache_tests


all: $(PROGRAM)


$(PROGRAM): cache_benchmark.c
	$(CC) $(CFLAGS) cache_benchmark.c -o $(PROGRAM)


run: $(PROGRAM)
	./$(PROGRAM)


test: $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


$(TEST_PROGRAM): test_cache.c
	$(CC) $(CFLAGS) test_cache.c -o $(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean