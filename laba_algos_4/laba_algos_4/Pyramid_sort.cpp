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
void Sort_Pyro(int* mas, const int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		Sift1(mas, n, i);
	}
	for (int i = n - 1; i >= 1; i--) {
		int a = mas[0];
		mas[0] = mas[i];
		mas[i] = a;
		Sift1(mas, i, 0);
	}
}