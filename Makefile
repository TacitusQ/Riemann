CC  = clang++
CXX = clang++

CXXFLAGS = -g -Wall #-std=c++11
LDFLAGS  = -g

executables = series
objects = series.o frac.o poly.o

$(executables): frac.o poly.o

$(objects): global.h 

.PHONY: default
default: $(executables)

.PHONY: clean
clean:
	rm -f a.out *~ $(objects) $(executables)

.PHONY: all
all: clean default
