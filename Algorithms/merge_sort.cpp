#include "merge_sort.h"
#include <cstring>
#include <omp.h>

void merge(unsigned* T1, int size1, unsigned* T2, int size2, unsigned* copy);
void merge_parallel(unsigned* first, int first_size, unsigned *second, int second_size, unsigned* dest, int threads);
int binsearch(unsigned *T, unsigned n, int value);

void merge_sort(unsigned* T, int n, unsigned* copyT)
{
	if (n <= 1)
		return ;
	
	merge_sort(T, n/2, copyT);
	merge_sort(T + n/2, n - n/2, copyT + n/2);
	
	merge(T, n/2, T + n/2, n - n/2, copyT);
	memcpy(T, copyT, n * sizeof(int));
}

void merge_sort_parallel(unsigned* T, int n, int threads, unsigned* copyT) 
{
	if (n <= 1)
		return;
	if (threads <= 1) 
	{
		merge_sort(T, n, copyT);
		return;
	}
	
	#pragma omp parallel sections num_threads(threads)
	{
		#pragma omp section
		{
			merge_sort_parallel(T, n/2, threads/2, copyT);
		}
		#pragma omp section
		{
			merge_sort_parallel(T + n/2, n - n/2, threads - threads/2, copyT + n/2);
		}
	}

	merge_parallel(T, n/2, T + n/2, n - n/2, copyT, threads);
	memcpy(T, copyT, n * sizeof(int));
}

int binsearch(unsigned *T, unsigned n, int value) 
{
	int L = 0, R = n;
	while (L < R) 
	{
		int m = (L+R)/2;
		if (T[m] < value)
			L = m + 1;
		else
			R = m;
	}
	return L;
}

void merge(unsigned* T1, int size1, unsigned* T2, int size2, unsigned* copy) 
{
	while (size1 > 0 && size2 > 0) {
		if (*T1 < *T2) {
			*copy = *T1;
			T1++;
			size1--;
		} else {
			*copy = *T2;
			T2++;
			size2--;
		}
		copy++;
	}
	if (size1 > 0)
		memcpy(copy, T1, size1*sizeof(int));
	if (size2 > 0)
		memcpy(copy, T2, size2*sizeof(int));
}

void merge_parallel(unsigned* T1, int size1, unsigned* T2, int size2, unsigned* copy, int threads) 
{
	if (threads <= 1) {
		merge(T1, size1, T2, size2, copy);
		return;
	}
	if (size1 < size2) {
		std::swap(T1, T2);
		std::swap(size1, size2);
	}

	if (size1 <= 0) 
		return;

	unsigned mid = T1[size1 / 2];
	int second_half_size = binsearch(T2, size2, mid);
	copy[size1 / 2 + second_half_size] = mid;

	#pragma omp parallel sections num_threads(threads)
	{
		#pragma omp section
		{
			merge_parallel(T1, size1 / 2, T2, second_half_size, copy, threads / 2);
		}
		#pragma omp section
		{
			merge_parallel(T1 + size1 / 2 + 1, size1 - size1 / 2 - 1,
						   T2 + second_half_size, size2 - second_half_size,
						   copy + size1 / 2 + second_half_size + 1, threads - threads / 2);
		}
	}
}
