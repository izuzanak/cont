
LIBS =
DEFS = -D_REENTRANT
OPT = -O2

all: rb_tree

# -- LINKING --

rb_tree: p.rb_tree.o
	$(CC) $(DEFS) $(OPT) $^ -lm -o rb_tree -Wall $(LIBS)

# -- COMPILE --

p.rb_tree.o: p.rb_tree.c
	$(CC) $(DEFS) $(OPT) -c $^ -o p.rb_tree.o -Wall

# -- PROCESS --

p.rb_tree.c: rb_tree.h rb_tree.c
	cont_c --geninc rb_tree.c ../* > p.rb_tree.c

clean:
	rm -f p.* *.o

