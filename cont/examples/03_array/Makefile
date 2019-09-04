
LIBS =
DEFS = -D_REENTRANT
OPT = -O2 -Wno-class-memaccess
CPP = g++

all: array

# -- LINKING --

array: p.array.o
	$(CPP) $(DEFS) $(OPT) $^ -o array -Wall $(LIBS)

# -- COMPILE --

p.array.o: p.array.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.array.o -Wall

# -- PROCESS --

p.array.cc: array.h array.cc
	cont array.cc ../* > p.array.cc

clean:
	rm -f p.* *.o

