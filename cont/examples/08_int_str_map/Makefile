
LIBS =
DEFS = -D_REENTRANT
OPT = -O2

all: int_str_map

# -- LINKING --

int_str_map: p.int_str_map.o
	$(CC) $(DEFS) $(OPT) $^ -lm -o int_str_map -Wall $(LIBS)

# -- COMPILE --

p.int_str_map.o: p.int_str_map.c
	$(CC) $(DEFS) $(OPT) -c $^ -o p.int_str_map.o -Wall

# -- PROCESS --

p.int_str_map.c: int_str_map.h int_str_map.c
	cont_c --geninc int_str_map.c ../* > p.int_str_map.c

clean:
	rm -f p.* *.o

