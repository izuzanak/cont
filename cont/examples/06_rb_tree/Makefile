
LIBS =
DEFS = -D_REENTRANT
OPT = -O2 -Wno-class-memaccess
CPP = g++

all: rb_tree

# -- LINKING --

rb_tree: p.rb_tree.o
	$(CPP) $(DEFS) $(OPT) $^ -o rb_tree -Wall $(LIBS)

# -- COMPILE --

p.rb_tree.o: p.rb_tree.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.rb_tree.o -Wall

# -- PROCESS --

p.rb_tree.cc: rb_tree.h rb_tree.cc
	cont rb_tree.cc ../* > p.rb_tree.cc

clean:
	rm -f p.* *.o

