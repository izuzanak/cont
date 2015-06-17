
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = gcc

all: struct

# -- LINKING --

struct: p.struct.o
	$(CPP) $(DEFS) $(OPT) $^ -o struct -Wall $(LIBS)

# -- COMPILE --

p.struct.o: p.struct.c
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.struct.o -Wall

# -- PROCESS --

p.struct.c: struct.h struct.c
	process_c struct.c ../* > p.struct.c

clean:
	rm -f p.* *.o

