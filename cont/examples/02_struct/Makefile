
LIBS =
DEFS = -D_REENTRANT
OPT = -std=c++11 -O2 -Wno-class-memaccess

all: struct

# -- LINKING --

struct: p.struct.o
	$(CXX) $(DEFS) $(OPT) $^ -o struct -Wall $(LIBS)

# -- COMPILE --

p.struct.o: p.struct.cc
	$(CXX) $(DEFS) $(OPT) -c $^ -o p.struct.o -Wall

# -- PROCESS --

p.struct.cc: struct.h struct.cc
	cont --geninc struct.cc ../* > p.struct.cc

clean:
	rm -f p.* *.o

