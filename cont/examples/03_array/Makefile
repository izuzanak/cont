
LIBS =
DEFS = -D_REENTRANT
OPT = -O2

all: array

# -- LINKING --

array: p.array.o
	$(CC) $(DEFS) $(OPT) $^ -o array -Wall $(LIBS)

# -- COMPILE --

p.array.o: p.array.c
	$(CC) $(DEFS) $(OPT) -c $^ -o p.array.o -Wall

# -- PROCESS --

p.array.c: array.h array.c
	cont_c --geninc array.c ../* > p.array.c

clean:
	rm -f p.* *.o

