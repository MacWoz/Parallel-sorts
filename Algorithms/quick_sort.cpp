#include "quick_sort.h"
#include <omp.h>

std::pair<int, int> partition(int* T, int L, int R)
{
	int pos = rand() % (R - L + 1) + L;
	int pivot = T[pos];
	int i = L - 1; /// i - ostatni < x, j - ostatni == x
	int j = i;
	
	for (int k=L; k<=R; k++) {
		if (T[k] < pivot) 
		{
			++i;
			++j;
			std::swap(T[k], T[i]);
			if(i != j)
				std::swap(T[k], T[j]);
		}
		else if(T[k] == pivot)
		{
			++j;
			std::swap(T[k], T[j]);
		}
	}
	if(i == -1) 
		i = 0;
	return std::make_pair(i, j);
}

void quick_sort(int* T, int L, int R)
{
	if (L >= R)
		return ;
		
	std::pair<int, int> parts = partition(T, L, R);
	int R1 = parts.first;
	int L2 = parts.second;
	
	quick_sort(T, L, R1);
	quick_sort(T, L2+1, R);
}

void quick_sort_parallel(int* T, int L, int R)
{
	if (L >= R)
		return ;
		
	std::pair<int, int> parts = partition(T, L, R);
	int R1 = parts.first;
	int L2 = parts.second;
	
	#pragma omp parallel
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				quick_sort_parallel(T, L, R1);
			}
			#pragma omp section
			{
				quick_sort_parallel(T, L2+1, R);
			}
		}
	}
}
