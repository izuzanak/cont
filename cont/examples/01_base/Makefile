
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = gcc

all: base

# -- LINKING --

base: p.base.o
	$(CPP) $(DEFS) $(OPT) $^ -o base -Wall $(LIBS)

# -- COMPILE --

p.base.o: p.base.c
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.base.o -Wall

# -- PROCESS --

p.base.c: base.h base.c
	process_c base.c > p.base.c

clean:
	rm -f p.* *.o

