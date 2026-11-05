#include "met_shell.h"
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> knyt(int const n) {
	std::vector<int> mas_h;
	int h = 1;

	
	while (h < n) {
		mas_h.push_back(h);
		h = 3 * h + 1; 
	}
	std::reverse(mas_h.begin(), mas_h.end());
	return mas_h;
}
std::vector<int> hibbart(int const n) {
	std::vector<int> mas_h;
	for (int i = 1; i < n; i++) {
		int a = (1 <<i) - 1;
		if (a < n)mas_h.push_back(a);
		else break;
	}
	std::reverse(mas_h.begin(), mas_h.end());
	return mas_h;
}
std::vector<int> shell(int const n) {
std::vector<int> mas_h;
if (n <= 1) return mas_h;
for (int h = n / 2; h > 0; h /= 2) {
	mas_h.push_back(h);
}
	return mas_h;
}

	void shell_sort(int* mass, int const n,const std::vector<int>& mas_h) {
	
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
