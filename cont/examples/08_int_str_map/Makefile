
LIBS =
DEFS = -D_REENTRANT
OPT = -O3
CPP = g++

all: int_str_map

# -- LINKING --

int_str_map: p.int_str_map.o
	$(CPP) $(DEFS) $(OPT) $^ -o int_str_map -Wall -fno-strict-aliasing $(LIBS)

# -- COMPILE --

p.int_str_map.o: p.int_str_map.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.int_str_map.o -Wall -fno-strict-aliasing

# -- PROCESS --

p.int_str_map.cc: int_str_map.h int_str_map.cc
	process int_str_map.cc ../* > p.int_str_map.cc

clean:
	rm -f p.* *.o

