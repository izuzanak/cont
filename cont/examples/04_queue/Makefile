
LIBS =
DEFS = -D_REENTRANT
OPT = -O2
CPP = g++

all: queue

# -- LINKING --

queue: p.queue.o
	$(CPP) $(DEFS) $(OPT) $^ -o queue -Wall $(LIBS)

# -- COMPILE --

p.queue.o: p.queue.cc
	$(CPP) $(DEFS) $(OPT) -c $^ -o p.queue.o -Wall

# -- PROCESS --

p.queue.cc: queue.h queue.cc
	process queue.cc ../* > p.queue.cc

clean:
	rm -f p.* *.o

