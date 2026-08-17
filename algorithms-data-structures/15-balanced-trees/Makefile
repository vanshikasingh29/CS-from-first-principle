CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = balanced_tree

TEST_PROGRAM = balanced_tree_tests


all:
	$(CC) $(CFLAGS) main.c balanced_tree.c -I. -o $(PROGRAM)


run:
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) test_balanced_tree.c balanced_tree.c -I. -o $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean