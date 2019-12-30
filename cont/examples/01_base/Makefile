
LIBS =
DEFS = -D_REENTRANT
OPT = -O2

all: base

# -- LINKING --

base: p.base.o
	$(CC) $(DEFS) $(OPT) $^ -o base -Wall $(LIBS)

# -- COMPILE --

p.base.o: p.base.c
	$(CC) $(DEFS) $(OPT) -c $^ -o p.base.o -Wall

# -- PROCESS --

p.base.c: base.h base.c
	cont_c --geninc base.c > p.base.c

clean:
	rm -f p.* *.o

