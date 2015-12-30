CC=g++
CFLAGS=-O2 -std=c++11 -fopenmp
LDFLAGS=
SOURCES := \
	test_mergesort.cpp \
	../Algorithms/merge_sort.cpp \
	../Algorithms/std_sort.cpp

BIN := first_test

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(BIN)

clean:
	rm -rf first_test
