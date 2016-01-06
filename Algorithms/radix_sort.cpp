#include "radix_sort.h"
#include <cstring>
#include <omp.h>

void radix_sort(int* T, int L, int R)
{
	const int N = R+1;
	int andValue = 1;
	
	int* Tcopy = new int[N];
	for (int i=0;i<31;++i)
	{
		int* source = (i%2 == 0) ? T : Tcopy;
		int* destination = (i%2 == 0) ? Tcopy : T;
		if (i > 0)
			andValue <<= 1;
			
		std::vector<int> Falses(N, 0);
		for(int j=0; j<N ;++j)
			if ((source[j] & andValue) == 0)
				Falses[j] = 1;
		
		for (int j=1; j<N; ++j)
			Falses[j] += Falses[j-1];
			
		int totalFalses = Falses[N-1];
		
		for (int j=0;j<N;++j) {
			if ((source[j] & andValue) == 0)
				destination[Falses[j] - 1] = source[j];
			else 
			{
				int index = totalFalses + j - Falses[j];
				destination[index] = source[j];
			}
		}
		memcpy(source, destination, N*sizeof(int));
	}
	
	delete [] Tcopy;
}

void radix_sort_parallel(int* T, int L, int R)
{
	const int N = R+1;
	int andValue = 1;
	
	int* Tcopy = new int[N];
	for (int i=0;i<31;++i)
	{
		int* source = (i%2 == 0) ? T : Tcopy;
		int* destination = (i%2 == 0) ? Tcopy : T;
		if (i > 0)
			andValue <<= 1;
			
		std::vector<int> Falses(N, 0);
		
		#pragma omp parallel for firstprivate(N, andValue) schedule (guided)
		for(int j=0; j<N ;++j)
			if ((source[j] & andValue) == 0)
				Falses[j] = 1;
		
		for (int j=1; j<N; ++j)
			Falses[j] += Falses[j-1];
			
		int totalFalses = Falses[N-1];
		
		#pragma omp parallel for firstprivate(N, andValue, totalFalses) schedule (guided)
		for (int j=0;j<N;++j) {
			if ((source[j] & andValue) == 0)
				destination[Falses[j] - 1] = source[j];
			else 
			{
				int index = totalFalses + j - Falses[j];
				destination[index] = source[j];
			}
		}
		
		memcpy(source, destination, N*sizeof(int));
	}
	
	delete [] Tcopy;
}
