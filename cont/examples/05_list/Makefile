
LIBS =
DEFS = -D_REENTRANT
OPT = -O2 -Wno-class-memaccess

all: list

# -- LINKING --

list: p.list.o
	$(CXX) $(DEFS) $(OPT) $^ -o list -Wall $(LIBS)

# -- COMPILE --

p.list.o: p.list.cc
	$(CXX) $(DEFS) $(OPT) -c $^ -o p.list.o -Wall

# -- PROCESS --

p.list.cc: list.h list.cc
	cont --geninc list.cc ../* > p.list.cc

clean:
	rm -f p.* *.o

