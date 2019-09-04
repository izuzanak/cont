
LIBS =
DEFS = -D_REENTRANT
OPT = -O2 -Wno-class-memaccess
CPP = g++

all: base

# -- LINKING --

base: p.base.o
	$(CPP) $(DEFS) $(OPT) $^ -o base -Wall $(LIBS)

# -- COMPILE --

p.base.o: p.base.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.base.o -Wall

# -- PROCESS --

p.base.cc: base.h base.cc
	cont base.cc > p.base.cc

clean:
	rm -f p.* *.o

