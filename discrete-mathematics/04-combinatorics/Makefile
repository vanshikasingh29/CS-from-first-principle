CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -g

TARGET = combinatorics_tests

SRC = src/combinatorics.c \
      tests/test_combinatorics.c

INCLUDE = -Iinclude

all:
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

test: run
