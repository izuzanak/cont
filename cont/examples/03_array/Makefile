
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = gcc

all: array

# -- LINKING --

array: p.array.o
	$(CPP) $(DEFS) $(OPT) $^ -o array -Wall $(LIBS)

# -- COMPILE --

p.array.o: p.array.c
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.array.o -Wall

# -- PROCESS --

p.array.c: array.h array.c
	process_c array.c ../* > p.array.c

clean:
	rm -f p.* *.o

