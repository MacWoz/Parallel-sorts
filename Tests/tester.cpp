#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "../Algorithms/bitonic_sort.h"
#include "../Algorithms/merge_sort.h"
#include "../Algorithms/radix_sort.h"
#include "../Algorithms/std_sort.h"
#include "../Algorithms/quick_sort.h"

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	int* T = new int[n];
	for (int i=0; i<n; ++i)
		cin >> T[i];
		
	radix_sort(T, 0, n-1);
	
	if(std::is_sorted(T, T+n))
		std::cout << "OK" << std:: endl;
	else
		std::cout << "FAIL" << std:: endl;
		
	delete [] T;
	return 0;
}
