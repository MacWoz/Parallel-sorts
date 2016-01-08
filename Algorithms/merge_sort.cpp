#include "merge_sort.h"
#include <omp.h>

void merge(unsigned* T, int L, int R);

void merge_sort(unsigned* T, int L, int R)
{
	if (L >= R)
		return ;
	
	int m = (L+R)/2;
	
	merge_sort(T, L, m);
	merge_sort(T, m+1, R);
	
	merge(T, L, R);
}

void merge_sort_parallel(unsigned* T, int L, int R, int threads) 
{
	if (L >= R)
		return ;
	if (threads <= 1) {
		merge_sort(T, L, R);
		return;
	}
		
	int m = (L+R)/2; 
	#pragma omp parallel shared(T) firstprivate(L, R, m, threads)
	{
		#pragma omp sections
		{
			#pragma omp section
			{
				merge_sort_parallel(T, L, m, threads/2);
			}
			#pragma omp section
			{
				merge_sort_parallel(T, m+1, R, threads-threads/2);
			}
		}
	}
	
	merge(T, L, R);
}

void merge(unsigned* T, int L, int R)
{
	int m = (L+R)/2;
	std::vector<unsigned> copyT(R-L+1);
	for (int i=L; i<=R; ++i)
		copyT[i-L] = T[i];
	
	int i=L;
    int j=m+1;
    int k=L;

	while (i <= m && j <= R) {
		if (copyT[i-L] <= copyT[j-L]) {
			T[k] = copyT[i-L];
			i++;
		} else {
			T[k] = copyT[j-L];
			j++;
		}
		k++;
	}

	while (i<=m) {
		T[k] = copyT[i-L];
		k++;
		i++;
	}
	while (j<=R) {
		T[k] = copyT[j-L];
		k++;
		j++;
	}
}
