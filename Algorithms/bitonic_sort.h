#ifndef _BITONIC_SORT_H_
#define _BITONIC_SORT_H_

void bitonic_sort(unsigned* T, int length, bool up = true);
void bitonic_sort_parallel(unsigned* T, int length, int threads, bool up = true);

#endif
