
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = gcc

all: rb_tree

# -- LINKING --

rb_tree: p.rb_tree.o
	$(CPP) $(DEFS) $(OPT) $^ -lm -o rb_tree -Wall $(LIBS)

# -- COMPILE --

p.rb_tree.o: p.rb_tree.c
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.rb_tree.o -Wall

# -- PROCESS --

p.rb_tree.c: rb_tree.h rb_tree.c
	cont_c --geninc rb_tree.c ../* > p.rb_tree.c

clean:
	rm -f p.* *.o

