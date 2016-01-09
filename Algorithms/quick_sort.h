#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <iostream>
#include <vector>

void quick_sort(unsigned* T, int L, int R);
void quick_sort_parallel(unsigned* T, int L, int R, int threads);

#endif
