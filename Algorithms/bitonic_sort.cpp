#include "bitonic_sort.h"
#include <climits>
#include <iostream>
#include <cstring>

unsigned findProperSize(unsigned size)
{
	unsigned i = 1;
	while (i < size)
		i <<= 1;
		//qqq
	return i;
}

unsigned log2(unsigned value)
{
	unsigned lg = 0;
	unsigned ex = 1;
	while (ex < value)
	{
		ex <<= 1;
		lg++;
	}
	return lg;
}

unsigned power2(unsigned value)
{
	unsigned result = 1;
	unsigned i = 0;
	while (i < value) 
	{
		++i;
		result <<= 1;
	}
	return result;
}

void compare_exchange(unsigned& value1, unsigned& value2, int current_global_block_start, int blockSize, int pos)
{
	if (pos >= current_global_block_start + blockSize/2) { // większy wcześniej
		if (value1 < value2)
			std::swap(value1, value2);
	} else {
		if (value1 > value2)
			std::swap(value1, value2);
	}
}

void bitonic_sort(unsigned* T, int L, int R)
{
	unsigned N = R+1;
	N = findProperSize(N);
	unsigned* array = new unsigned[N];
	
	memcpy(array, T, (R+1)*sizeof(unsigned));
	for (int i=R+1;i<N;++i)
		array[i] = UINT_MAX;
		
	unsigned lg = log2(N);
	
	for (unsigned iter = 0; iter<lg; ++iter) {
		int offset = (int) power2(iter);
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


void bitonic_sort_parallel(unsigned* T, int L, int R)
{
	unsigned N = R+1;
	N = findProperSize(N);
	unsigned* array = new unsigned[N];
	for (unsigned i=0;i<N;++i)
		array[i] = (i <= R) ? T[i] : UINT_MAX ;
	
	unsigned lg = log2(N);
	
	for (unsigned iter = 0; iter<lg; ++iter) {
		int offset = (int) power2(iter);
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
