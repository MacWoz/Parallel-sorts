#include "std_sort.h"
#include <algorithm>

void std_sort(unsigned* T, int L, int R)
{
	std::sort(T, T+R+1);
}
