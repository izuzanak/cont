
LIBS =
DEFS = -D_REENTRANT
OPT = -O2 -Wno-class-memaccess
CPP = g++

all: dynamic

# -- LINKING --

dynamic: p.dynamic.o
	$(CPP) $(DEFS) $(OPT) $^ -o dynamic -Wall $(LIBS)

# -- COMPILE --

p.dynamic.o: p.dynamic.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.dynamic.o -Wall

# -- PROCESS --

p.dynamic.cc: dynamic.h dynamic.cc
	cont dynamic.cc ../* > p.dynamic.cc

clean:
	rm -f p.* *.o

