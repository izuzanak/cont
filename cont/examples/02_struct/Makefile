
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = g++

all: struct

# -- LINKING --

struct: p.struct.o
	$(CPP) $(DEFS) $(OPT) $^ -o struct -Wall $(LIBS)

# -- COMPILE --

p.struct.o: p.struct.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.struct.o -Wall

# -- PROCESS --

p.struct.cc: struct.h struct.cc
	process struct.cc ../* > p.struct.cc

clean:
	rm -f p.* *.o

