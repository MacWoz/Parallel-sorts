#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <iostream>
#include <vector>

void merge_sort(unsigned* T, int n, unsigned* copyT);
void merge_sort_parallel(unsigned* T, int n, int threads, unsigned* copyT);

#endif
