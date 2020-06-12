
LIBS =
DEFS = -D_REENTRANT
OPT = -O2 -Wno-class-memaccess

all: queue

# -- LINKING --

queue: p.queue.o
	$(CXX) $(DEFS) $(OPT) $^ -o queue -Wall $(LIBS)

# -- COMPILE --

p.queue.o: p.queue.cc
	$(CXX) $(DEFS) $(OPT) -c $^ -o p.queue.o -Wall

# -- PROCESS --

p.queue.cc: queue.h queue.cc
	cont --geninc queue.cc ../* > p.queue.cc

clean:
	rm -f p.* *.o

