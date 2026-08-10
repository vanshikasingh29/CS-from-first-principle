CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -g

TARGET = automata_tests

SRC = src/dfa.c \
      tests/test_dfa.c

INCLUDE = -Iinclude

all:
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

test: run
