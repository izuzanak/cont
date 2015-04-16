
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = g++

all: array

# -- LINKING --

array: p.array.o
	$(CPP) $(DEFS) $(OPT) $^ -o array -Wall -fno-strict-aliasing $(LIBS)

# -- COMPILE --

p.array.o: p.array.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.array.o -Wall -fno-strict-aliasing

# -- PROCESS --

p.array.cc: array.h array.cc
	process array.cc ../* > p.array.cc

clean:
	rm -f p.* *.o

