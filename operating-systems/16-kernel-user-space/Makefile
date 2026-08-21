CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = kernel_boundary

PROCESS_PROGRAM = process_demo

EXEC_PROGRAM = exec_demo

TEST_PROGRAM = kernel_tests


all: $(PROGRAM) $(PROCESS_PROGRAM) $(EXEC_PROGRAM)


$(PROGRAM): kernel_boundary.c
	$(CC) $(CFLAGS) kernel_boundary.c -o $(PROGRAM)


$(PROCESS_PROGRAM): process_demo.c
	$(CC) $(CFLAGS) process_demo.c -o $(PROCESS_PROGRAM)


$(EXEC_PROGRAM): exec_demo.c
	$(CC) $(CFLAGS) exec_demo.c -o $(EXEC_PROGRAM)


run: $(PROGRAM)
	./$(PROGRAM)


process: $(PROCESS_PROGRAM)
	./$(PROCESS_PROGRAM)


exec: $(EXEC_PROGRAM)
	./$(EXEC_PROGRAM)


test: $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


$(TEST_PROGRAM): test_kernel_boundary.c
	$(CC) $(CFLAGS) test_kernel_boundary.c -o $(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) \
	      $(PROCESS_PROGRAM) \
	      $(EXEC_PROGRAM) \
	      $(TEST_PROGRAM)


.PHONY: all run process exec test clean