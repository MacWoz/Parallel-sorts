#include <iostream>
#include <vector>

void merge(int* T, int L, int R);

void mergesort(int* T, int L, int R)
{
	if (L >= R)
		return ;
	
	int m = (L+R)/2;
	
	mergesort(T, L, m);
	mergesort(T, m+1, R);
	
	merge(T, L, R);
}

void merge(int* T, int L, int R)
{

	int m = (L+R)/2;
	std::vector<int> copyT(R-L+1);
	for (int i=L; i<=R; ++i)
		copyT[i-L] = T[i];
	
	int i=L;
    int j=m+1;
    int k=L;

	while (i <= m && j <= R) {
		if (copyT[i-L] <= copyT[j-L]) {
			T[k] = copyT[i-L];
			k++;
			i++;
		} else {
			T[k] = copyT[j-L];
			k++;
			j++;
		}
	}

	while (i<=m) {
		T[k] = copyT[i-L];
		k++;
		i++;
	}
	while (j<=R) {
		T[k] = copyT[j-L];
		k++;
		j++;
	}
}
