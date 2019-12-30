
LIBS =
DEFS = -D_REENTRANT
OPT = -O2

all: list

# -- LINKING --

list: p.list.o
	$(CC) $(DEFS) $(OPT) $^ -o list -Wall $(LIBS)

# -- COMPILE --

p.list.o: p.list.c
	$(CC) $(DEFS) $(OPT) -c $^ -o p.list.o -Wall

# -- PROCESS --

p.list.c: list.h list.c
	cont_c --geninc list.c ../* > p.list.c

clean:
	rm -f p.* *.o

