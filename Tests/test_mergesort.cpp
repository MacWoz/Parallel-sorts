#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>

#include "../Algorithms/merge_sort.h"
#include "../Algorithms/std_sort.h"
#include "../Algorithms/quick_sort.h"

int main()
{
	constexpr int SIZE = 10000000;
	constexpr int MAX_VALUE = 25000000;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i)
		T[i] = rand() % MAX_VALUE;

	std::cout << std::endl;
	
	quick_sort_parallel(T, 0, SIZE - 1);
	assert(std::is_sorted(T, T+SIZE));
	std::cout << "OK" << std:: endl;
	return 0;
}
