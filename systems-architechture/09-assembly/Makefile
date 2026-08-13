CC = gcc
ASM = nasm

CFLAGS = -Wall -Wextra -std=c17 -g
ASMFLAGS = -f elf64

PROGRAM = assembly_demo
TEST_PROGRAM = assembly_tests

ASM_OBJECT = assembly_basics.o


all: $(PROGRAM)


$(ASM_OBJECT):
	$(ASM) $(ASMFLAGS) assembly_basics.asm -o $(ASM_OBJECT)


$(PROGRAM): main.c $(ASM_OBJECT)
	$(CC) $(CFLAGS) main.c $(ASM_OBJECT) -o $(PROGRAM)


run: $(PROGRAM)
	./$(PROGRAM)


test: $(ASM_OBJECT)
	$(CC) $(CFLAGS) test_assembly.c $(ASM_OBJECT) -o $(TEST_PROGRAM)
	./$(TEST_PROGRAM)


clean:
	rm -f $(PROGRAM) $(TEST_PROGRAM) $(ASM_OBJECT)


.PHONY: all run test clean