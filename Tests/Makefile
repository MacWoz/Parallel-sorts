CC=g++
CFLAGS=-O2 -std=c++11 -fopenmp
LDFLAGS=
SOURCES := \
	tester.cpp \
	../Algorithms/merge_sort.cpp \
	../Algorithms/std_sort.cpp \
	../Algorithms/quick_sort.cpp \
	../Algorithms/radix_sort.cpp \
	../Algorithms/bitonic_sort.cpp

BIN := first_test

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(BIN)

clean:
	rm -rf first_test
