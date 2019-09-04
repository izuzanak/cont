
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = gcc

all: queue

# -- LINKING --

queue: p.queue.o
	$(CPP) $(DEFS) $(OPT) $^ -o queue -Wall $(LIBS)

# -- COMPILE --

p.queue.o: p.queue.c
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.queue.o -Wall

# -- PROCESS --

p.queue.c: queue.h queue.c
	cont_c --geninc queue.c ../* > p.queue.c

clean:
	rm -f p.* *.o

