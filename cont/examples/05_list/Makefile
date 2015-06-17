
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = gcc

all: list

# -- LINKING --

list: p.list.o
	$(CPP) $(DEFS) $(OPT) $^ -o list -Wall $(LIBS)

# -- COMPILE --

p.list.o: p.list.c
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.list.o -Wall

# -- PROCESS --

p.list.c: list.h list.c
	process_c list.c ../* > p.list.c

clean:
	rm -f p.* *.o

