#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>
#include "mergesort.cpp"

int main()
{
	srand(time(NULL));
	
	int* T = new int[1300]();
	for (int i=0; i<1300; ++i)
	{
		T[i] = rand() % 25;
		std::cout << T[i] << " " ;
	}
	std::cout << std::endl;
	
	mergesort(T, 0, 1299);
	
	assert(std::is_sorted(T, T+1300));
	return 0;
}
