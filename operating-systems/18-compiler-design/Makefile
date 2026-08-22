CC = gcc

CFLAGS = -Wall -Wextra -std=c17 -g

PROGRAM = compiler_demo


all: $(PROGRAM)


$(PROGRAM): main.c lexer.c lexer.h
	$(CC) $(CFLAGS) main.c lexer.c -I. -o $(PROGRAM)


run: $(PROGRAM)
	./$(PROGRAM)


clean:
	rm -f $(PROGRAM)


.PHONY: all run clean