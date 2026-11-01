#include "met_shell.h"
#include <vector>

void shell_sort(int* mass, int const n) {
	std::vector<int> mas_h;
	int k = n / 2;
	mas_h.push_back(k);
	for (int i = 0; k != 1; i++) {
		mas_h.push_back(mas_h[i] / 2);
		k = mas_h[i + 1];
	}
	for (int i = 0; i < mas_h.size(); i++) {

		for (int s = mas_h[i], b = 0; b < s; b++) {

			for (int j = b + s; j < n;) {
				int x = mass[j];
				int k = j - s;

				while (k >= 0 && mass[k] > x) {
					mass[k + s] = mass[k];
					k = k - s;
				}
				mass[k + s] = x;
				j = j + s;
			}
		}
	}
}
bool is_sorted(int const* mass, int const n) {
	for (int i = 0; i < n - 1; i++) {
		if (mass[i] > mass[i + 1]) {
			return false; 
		}
	}
	return true; 
}
