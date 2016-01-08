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

using namespace std;

int main(int argc, char* argv[]) {
	std::chrono::time_point<std::chrono::high_resolution_clock> global_start = std::chrono::high_resolution_clock::now();
	int n;
	cin >> n;
	unsigned* T = new unsigned[n];
	for (int i=0; i<n; ++i)
		cin >> T[i];
		
	std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
	//std::sort(T, T+n);
	merge_sort_parallel(T, 0, n-1, omp_get_max_threads());
    std::chrono::time_point<std::chrono::high_resolution_clock> finish = std::chrono::high_resolution_clock::now();
    std::cout << "Real time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(finish-start).count() << "ms" << std::endl;

	
	if(std::is_sorted(T, T+n))
		std::cout << "OK" << std:: endl;
	else
		std::cout << "FAIL" << std:: endl;
		
	/*for (int i=0; i<n; ++i)
		cout << T[i] << " ";
	cout << endl;*/
		
	delete [] T;
	std::chrono::time_point<std::chrono::high_resolution_clock> global_finish = std::chrono::high_resolution_clock::now();
	std::cout << "Whole program time used: " << std::chrono::duration_cast<std::chrono::milliseconds>(global_finish - global_start).count() << "ms" << std::endl;
	return 0;
}
