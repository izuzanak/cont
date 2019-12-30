
LIBS =
DEFS = -D_REENTRANT
OPT = -O2

all: struct

# -- LINKING --

struct: p.struct.o
	$(CC) $(DEFS) $(OPT) $^ -o struct -Wall $(LIBS)

# -- COMPILE --

p.struct.o: p.struct.c
	$(CC) $(DEFS) $(OPT) -c $^ -o p.struct.o -Wall

# -- PROCESS --

p.struct.c: struct.h struct.c
	cont_c --geninc struct.c ../* > p.struct.c

clean:
	rm -f p.* *.o

