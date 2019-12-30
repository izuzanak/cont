
LIBS =
DEFS = -D_REENTRANT
OPT = -g

all: dynamic

# -- LINKING --

dynamic: p.dynamic.o
	$(CC) $(DEFS) $(OPT) $^ -o dynamic -Wall $(LIBS)

# -- COMPILE --

p.dynamic.o: p.dynamic.c
	$(CC) $(DEFS) $(OPT) -c $^ -o p.dynamic.o -Wall

# -- PROCESS --

p.dynamic.c: dynamic.h dynamic.c
	cont_c --geninc dynamic.c ../* > p.dynamic.c

clean:
	rm -f p.* *.o

