CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -g

TARGET = graph_tests

SRC = src/graph.c \
      tests/test_graph.c

INCLUDE = -Iinclude

all:
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

test: run