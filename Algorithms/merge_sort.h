#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <iostream>
#include <vector>

void merge_sort(unsigned* T, int L, int R);
void merge_sort_parallel(unsigned* T, int L, int R, int threads);

#endif
