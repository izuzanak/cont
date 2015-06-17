
LIBS =
DEFS = -D_REENTRANT
OPT = -g
CPP = gcc

all: dynamic

# -- LINKING --

dynamic: p.dynamic.o
	$(CPP) $(DEFS) $(OPT) $^ -o dynamic -Wall $(LIBS)

# -- COMPILE --

p.dynamic.o: p.dynamic.c
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.dynamic.o -Wall

# -- PROCESS --

p.dynamic.c: dynamic.h dynamic.c
	process_c dynamic.c ../* > p.dynamic.c

clean:
	rm -f p.* *.o

