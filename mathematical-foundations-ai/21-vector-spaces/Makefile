CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = vector_space

TEST_PROGRAM = vector_tests


all:
	$(CC) $(CFLAGS) vector_space.c -c -o vector_space.o
	$(CC) $(CFLAGS) -c test_vector_space.c -o test_vector_space.o
	$(CC) vector_space.o test_vector_space.o -lm -o $(TEST_PROGRAM)


run:
	@echo "Vector Space Laboratory"
	@echo "======================="
	@echo ""
	@echo "Build complete."
	@echo "Run 'make test' to execute the mathematical tests."


test: all
	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM) *.o


.PHONY: all run test clean