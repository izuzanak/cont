
LIBS =
DEFS = -D_REENTRANT
OPT = -std=c++11 -O2 -Wno-class-memaccess

all: base

# -- LINKING --

base: p.base.o
	$(CXX) $(DEFS) $(OPT) $^ -o base -Wall $(LIBS)

# -- COMPILE --

p.base.o: p.base.cc
	$(CXX) $(DEFS) $(OPT) -c $^ -o p.base.o -Wall

# -- PROCESS --

p.base.cc: base.h base.cc
	cont --geninc base.cc > p.base.cc

clean:
	rm -f p.* *.o

