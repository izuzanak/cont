
all: allocator

p.allocator.cc: allocator.h allocator.cc
	process allocator.cc > p.allocator.cc

allocator: p.allocator.cc
	g++ -O2 -ffast-math p.allocator.cc -o allocator -Wall

clean:
	rm -f p.allocator.cc

