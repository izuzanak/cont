
LIBS =
DEFS = -D_REENTRANT
OPT = -std=c++11 -O2 -Wno-class-memaccess

all: rb_tree

# -- LINKING --

rb_tree: p.rb_tree.o
	$(CXX) $(DEFS) $(OPT) $^ -o rb_tree -Wall $(LIBS)

# -- COMPILE --

p.rb_tree.o: p.rb_tree.cc
	$(CXX) $(DEFS) $(OPT) -c $^ -o p.rb_tree.o -Wall

# -- PROCESS --

p.rb_tree.cc: rb_tree.h rb_tree.cc
	cont --geninc rb_tree.cc ../* > p.rb_tree.cc

clean:
	rm -f p.* *.o

