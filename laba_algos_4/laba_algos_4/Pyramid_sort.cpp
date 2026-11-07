#include "Pyramid_sort.h"
#include <iostream>
#include <vector>

void Sift1(int* mas, const int n,int i) {
	int j = 2 * i + 1;
	while (j < n) {
		if (j + 1 < n && mas[j + 1] > mas[j]) {
			j = j + 1;
		}
		if (mas[j] > mas[i]) {

			int a = mas[i];
			mas[i] = mas[j];
			mas[j] = a;
			i = j;
			j = 2 * i + 1;
		}
		else return;
	}
}