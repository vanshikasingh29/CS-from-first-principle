CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = cpu_simulator

TEST_PROGRAM = cpu_tests


all:
	$(CC) $(CFLAGS) main.c cpu.c -I. -o $(PROGRAM)


run:
	./$(PROGRAM)


test:
	$(CC) $(CFLAGS) \
	test_cpu.c \
	cpu.c \
	-I. \
	-o $(TEST_PROGRAM)

	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM)


.PHONY: all run test clean