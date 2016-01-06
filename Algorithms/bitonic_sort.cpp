#include "bitonic_sort.h"
#include <climits>
#include <iostream>

int findProperSize(int size)
{
	int i = 1;
	while (i < size)
		i <<= 1;
		
	return i;
}

int log2(int value)
{
	int lg = 0;
	int ex = 1;
	while (ex < value) {
		ex <<= 1;
		lg++;
	}
	return lg;
}

int power2(int value)
{
	int result = 1;
	int i=0;
	while (i < value) {
		++i;
		result <<= 1;
	}
	return result;
}


void compare_exchange(int& value1, int& value2, int current_global_block_start, int blockSize, int pos)
{
	if (pos >= current_global_block_start + blockSize/2) { // większy wcześniej
		if (value1 < value2)
			std::swap(value1, value2);
	} else {
		if (value1 > value2)
			std::swap(value1, value2);
	}
}

void bitonic_sort(int* T, int L, int R)
{
	int N = R+1;
	N = findProperSize(N);
	int* array = new int[N];
	for (int i=0;i<N;++i)
		array[i] = (i <= R) ? T[i] : INT_MAX ;
	
	int lg = log2(N);
	
	for (int iter = 0; iter<lg; ++iter) {
		int offset = power2(iter);
		int blockSize = 4*offset;
		for (; offset > 0; offset >>= 1)
		{
			int current_global_block_start = -blockSize;
			int current_block_start = -2*offset;
			for (int i=0;i<N;++i) {
				if (i % blockSize == 0)
					current_global_block_start += blockSize;
					
				if (i % (offset << 1) == 0)
					current_block_start += 2*offset;
					
				if (i >= current_block_start + offset)
					continue;
				
				compare_exchange(array[i], array[i+offset], current_global_block_start, blockSize, i);
			}
		}
	}
	for (int i=0;i<R+1;++i)
		T[i] = array[i];
	
	delete [] array;
}


void bitonic_sort_parallel(int* T, int L, int R)
{
	
}
