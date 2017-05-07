CC  = clang++
CXX = clang++

CXXFLAGS = -g -Wall 
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
	rm -rf *.dSYM

.PHONY: all
all: clean default
