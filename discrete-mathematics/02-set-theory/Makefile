CC=gcc

CFLAGS=-Wall -Wextra -std=c17 -g

INCLUDE=include

SOURCE=src/set_theory.c

TEST_SOURCE=tests/test_set_theory.c

OUTPUT=set_theory_tests


all:
	$(CC) $(CFLAGS) $(TEST_SOURCE) $(SOURCE) -I$(INCLUDE) -o $(OUTPUT)


test:
	./$(OUTPUT)


clean:
	rm -f $(OUTPUT)