
LIBS =
DEFS = -D_REENTRANT
OPT = -std=c++11 -O2 -Wno-class-memaccess

all: dynamic

# -- LINKING --

dynamic: p.dynamic.o
	$(CXX) $(DEFS) $(OPT) $^ -o dynamic -Wall $(LIBS)

# -- COMPILE --

p.dynamic.o: p.dynamic.cc
	$(CXX) $(DEFS) $(OPT) -c $^ -o p.dynamic.o -Wall

# -- PROCESS --

p.dynamic.cc: dynamic.h dynamic.cc
	cont --geninc dynamic.cc ../* > p.dynamic.cc

clean:
	rm -f p.* *.o

