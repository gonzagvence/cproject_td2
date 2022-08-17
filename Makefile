CC=c99
CFLAGS=-Wall -Wextra -pedantic -O0 -ggdb
LIBS=-lm
all: main.out

main.out: trencito.c main.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f *.o *.out
