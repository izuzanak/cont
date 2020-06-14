
LIBS =
DEFS = -D_REENTRANT
OPT = -std=c++11 -O2 -Wno-class-memaccess

all: int_str_map

# -- LINKING --

int_str_map: p.int_str_map.o
	$(CXX) $(DEFS) $(OPT) $^ -o int_str_map -Wall $(LIBS)

# -- COMPILE --

p.int_str_map.o: p.int_str_map.cc
	$(CXX) $(DEFS) $(OPT) -c $^ -o p.int_str_map.o -Wall

# -- PROCESS --

p.int_str_map.cc: int_str_map.h int_str_map.cc
	cont --geninc int_str_map.cc ../* > p.int_str_map.cc

clean:
	rm -f p.* *.o

