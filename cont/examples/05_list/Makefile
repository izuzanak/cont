
LIBS =
DEFS = -D_REENTRANT
OPT = -O2 -Wno-class-memaccess
CPP = g++

all: list

# -- LINKING --

list: p.list.o
	$(CPP) $(DEFS) $(OPT) $^ -o list -Wall $(LIBS)

# -- COMPILE --

p.list.o: p.list.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.list.o -Wall

# -- PROCESS --

p.list.cc: list.h list.cc
	cont list.cc ../* > p.list.cc

clean:
	rm -f p.* *.o

