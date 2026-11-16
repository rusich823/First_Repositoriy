#include "method.h"



void hoar_sort(int* arr, int l, int r) {
	if (l >= r) return;
	int i = l, j = r, x = arr[(l + r) / 2];
	while (i <= j) {
		for (; arr[i] < x; i++);
		for (; arr[j] > x; j--);
		if (i <= j) {
			int cop = arr[i];
			arr[i] = arr[j];
			arr[j] = cop;
			i++;
			j--;

		}
		
	}
	hoar_sort(arr, l, j);
	hoar_sort(arr, i, r);

}
bool is_sorted(int const* mass, int const n) {
	for (int i = 0; i < n - 1; i++) {
		if (mass[i] > mass[i + 1]) {
			return false;
		}
	}
	return true;
}
