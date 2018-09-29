CC=gcc
CFLAGS=-I.
DEPS = list.h
OBJ = list.o main.o stage0.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

assignment2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
