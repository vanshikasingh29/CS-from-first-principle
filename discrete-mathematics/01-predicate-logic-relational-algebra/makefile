CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

INCLUDE = -Iinclude

SOURCE = src/logic.c

TEST_SOURCE = tests/test_logic.c

OUTPUT = logic_tests


.PHONY: all test clean


all: test


test: $(OUTPUT)
	./$(OUTPUT)


$(OUTPUT): $(TEST_SOURCE) $(SOURCE)
	$(CC) $(CFLAGS) $(TEST_SOURCE) $(SOURCE) $(INCLUDE) -o $(OUTPUT)


clean:
	rm -f $(OUTPUT)