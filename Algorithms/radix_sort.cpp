#include "radix_sort.h"
#include <cstring>
#include <omp.h>

void prefixSum(std::vector<int>& T, int n)
{
	int all_threads = omp_get_max_threads();
	int size_for_thread = n/all_threads;
	
	std::vector<int> lastValues(all_threads, 0);

	#pragma omp parallel num_threads(all_threads) firstprivate(all_threads, size_for_thread) 
	{
		int threadIdx = omp_get_thread_num();
		int startIndex = threadIdx * size_for_thread;
		int endIndex = threadIdx == all_threads-1 ? n: (threadIdx + 1) * size_for_thread;

		for (int i=startIndex+1; i<endIndex; ++i) 
			T[i] += T[i-1];

		lastValues[threadIdx] = T[endIndex-1];
	} 
	for (int i=1; i<all_threads; ++i) {
		lastValues[i] += lastValues[i-1];
	} 
	#pragma omp parallel num_threads(all_threads) firstprivate(all_threads, size_for_thread) 
	{
		int threadIdx = omp_get_thread_num();
		int startIndex = threadIdx * size_for_thread;
		int endIndex = threadIdx == all_threads-1 ? n: (threadIdx + 1) * size_for_thread;
		int addValue = threadIdx == 0 ? 0 : lastValues[threadIdx-1];
		for (int i=startIndex; i<endIndex; ++i) 
			T[i] += addValue;
	}
}

void radix_sort(unsigned* T, int N)
{
	unsigned andValue = 1;
	
	unsigned* Tcopy = new unsigned[N];
	for (int i=0;i<31;++i)
	{
		unsigned* source = (i%2 == 0) ? T : Tcopy;
		unsigned* destination = (i%2 == 0) ? Tcopy : T;
		if (i > 0)
			andValue <<= 1;
			
		std::vector<int> Falses(N, 0);
		for(unsigned j=0; j<N ;++j)
			if ((source[j] & andValue) == 0)
				Falses[j] = 1;
		
		for (unsigned j=1; j<N; ++j)
			Falses[j] += Falses[j-1];
			
		int totalFalses = Falses[N-1];
		
		for (unsigned j=0;j<N;++j) {
			if ((source[j] & andValue) == 0)
				destination[Falses[j] - 1] = source[j];
			else 
			{
				int index = totalFalses + j - Falses[j];
				destination[index] = source[j];
			}
		}
		memcpy(source, destination, N*sizeof(unsigned));
	}
	
	delete [] Tcopy;
}

void radix_sort_parallel(unsigned* T, int N)
{
	unsigned andValue = 1;
	
	unsigned* Tcopy = new unsigned[N];
	for (int i=0;i<31;++i)
	{
		unsigned* source = (i%2 == 0) ? T : Tcopy;
		unsigned* destination = (i%2 == 0) ? Tcopy : T;
		if (i > 0)
			andValue <<= 1;
			
		std::vector<int> Falses(N, 0);
		
		#pragma omp parallel for firstprivate(N, andValue) schedule (guided)
		for(unsigned j=0; j<N ;++j)
			if ((source[j] & andValue) == 0)
				Falses[j] = 1;
		
		prefixSum(Falses, N);
			
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
		
		memcpy(source, destination, N*sizeof(unsigned));
	}
	
	delete [] Tcopy;
}
