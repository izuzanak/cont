
LIBS =
DEFS = -D_REENTRANT
OPT = -O2 -Wno-class-memaccess

all: array

# -- LINKING --

array: p.array.o
	$(CXX) $(DEFS) $(OPT) $^ -o array -Wall $(LIBS)

# -- COMPILE --

p.array.o: p.array.cc
	$(CXX) $(DEFS) $(OPT) -c $^ -o p.array.o -Wall

# -- PROCESS --

p.array.cc: array.h array.cc
	cont --geninc array.cc ../* > p.array.cc

clean:
	rm -f p.* *.o

