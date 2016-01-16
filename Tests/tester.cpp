#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <omp.h>

#include "../Algorithms/bitonic_sort.h"
#include "../Algorithms/merge_sort.h"
#include "../Algorithms/radix_sort.h"
#include "../Algorithms/std_sort.h"
#include "../Algorithms/quick_sort.h"

void test_std_sort(unsigned* T, int n) {
	std::cout << "Testing std::sort on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	std::sort(T, T+n);
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

void test_quick_sort_sequential(unsigned* T, int n) {
	std::cout << "Testing quicksort sequential on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	quick_sort(T, 0, n-1);
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

void test_quick_sort_parallel(unsigned* T, int n) {
	std::cout << "Testing quicksort parallel on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	quick_sort_parallel(T, 0, n-1, omp_get_max_threads());
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

void test_merge_sort_sequential(unsigned* T, int n) {
	std::cout << "Testing mergesort sequential on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	unsigned* copy = new unsigned[n];
	merge_sort(T, n, copy);
	delete [] copy;
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

void test_merge_sort_parallel(unsigned* T, int n) {
	std::cout << "Testing mergesort parallel on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	unsigned* copy = new unsigned[n];
	merge_sort_parallel(T, n, omp_get_max_threads(), copy);
	delete [] copy;
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

void test_radix_sort_sequential(unsigned* T, int n) {
	std::cout << "Testing radixsort sequential on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	radix_sort(T, n);
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

void test_radix_sort_parallel(unsigned* T, int n) {
	std::cout << "Testing radixsort parallel on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	radix_sort_parallel(T, n);
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

void test_bitonic_sort_sequential(unsigned* T, int n) {
	std::cout << "Testing bitonic sort sequential on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	bitonic_sort(T, n, true);
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

void test_bitonic_sort_parallel(unsigned* T, int n) {
	std::cout << "Testing bitonic sort parallel on array of size "<< n << std::endl; 
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	
	bitonic_sort_parallel(T, n, omp_get_max_threads(), true);
	
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;
}

int main(int argc, char* argv[]) {
	int n;
	std::cin >> n;
	unsigned* T = new unsigned[n];
	for (int i=0; i<n; ++i)
		std::cin >> T[i];
	
	test_quick_sort_parallel(T, n);
	assert(std::is_sorted(T, T+n));
	
	//std::cout << n << std::endl;
	/*for (int i=0; i<n; ++i)
	{
		std::cout << T[i];
		if (i %10 == 9)
			std::cout << std::endl;
		else if (i == n-1)
			std::cout << std::endl;
		else
			std::cout << " ";
	}*/

	delete [] T;
	return 0;
}
