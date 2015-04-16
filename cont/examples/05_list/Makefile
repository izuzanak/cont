
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = g++

all: list

# -- LINKING --

list: p.list.o
	$(CPP) $(DEFS) $(OPT) $^ -o list -Wall -fno-strict-aliasing $(LIBS)

# -- COMPILE --

p.list.o: p.list.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.list.o -Wall -fno-strict-aliasing

# -- PROCESS --

p.list.cc: list.h list.cc
	process list.cc ../* > p.list.cc

clean:
	rm -f p.* *.o

