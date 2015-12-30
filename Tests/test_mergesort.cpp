#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>
#include "../Algorithms/merge_sort.h"

int main()
{
	constexpr int SIZE = 100;
	constexpr int MAX_VALUE = 25;
	srand(time(NULL));
	
	int* T = new int[SIZE]();
	for (int i=0; i<SIZE; ++i)
		T[i] = rand() % MAX_VALUE;

	std::cout << std::endl;
	
	merge_sort_parallel(T, 0, SIZE - 1);
	std::cout << "OK" << std:: endl;
	assert(std::is_sorted(T, T+SIZE));
	return 0;
}
