CC=gcc
CFLAGS=-I ./cpg/libpq -lpq
OBJ=example.o ./cpg/cpg.o

%.o: %.c
	$(CC) -c -o $@  $< $(CFLAGS)

example: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
