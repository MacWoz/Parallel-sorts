#include "bitonic_sort.h"
#include <climits>
#include <iostream>
#include <cstring>

void sequential_merge(unsigned* T, int length, bool up)
{
	if(length == 1)
		return;

	int half_length = length >> 1;
	
	for(int i=0; i < half_length; i++)
	{
		if((T[i] > T[i + half_length]) == up)
			std::swap(T[i], T[i + half_length]);
	}

	sequential_merge(T, half_length, up);
	sequential_merge(T + half_length, half_length, up);
}

void parallel_merge(unsigned* T, int length, int threads, bool up)
{
	if(length == 1)
		return;
	if (threads <= 1)
	{
		sequential_merge(T, length, up);
		return;
	}
		
	int half_length = length >> 1;
	
	#pragma omp parallel for num_threads(threads) firstprivate(T, half_length, up) schedule(guided)
	for(int i=0; i < half_length; i++)
	{
		if((T[i] > T[i + half_length]) == up)
			std::swap(T[i], T[i + half_length]);
	}
			
	#pragma omp parallel sections num_threads(threads)
	{
		#pragma omp section
		{
			parallel_merge(T, half_length, threads >> 1, up);
		}
		#pragma omp section
		{
			parallel_merge(T + half_length, half_length, threads - threads/2, up);
		}
	}
}

void bitonic_sort(unsigned* T, int length, bool up)
{
	if(length == 1)
		return;
		
	bitonic_sort(T, length >> 1, up);
	bitonic_sort(T + length/2, length >> 1, !up);

	sequential_merge(T, length, up);
}

void bitonic_sort_parallel(unsigned* T, int length, int threads, bool up)
{
	if(length == 1)
		return;
	if (threads == 1)
	{
		bitonic_sort(T, length, up);
		return;
	}
	
	#pragma omp parallel sections num_threads(threads)
	{
		#pragma omp section
		{
			bitonic_sort_parallel(T, length >> 1, threads >> 1, up);
		}
		#pragma omp section
		{
			bitonic_sort_parallel(T + length/2, length >> 1, threads - threads/2, !up);
		}
	}
	parallel_merge(T, length, threads, up);
}
