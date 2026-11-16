#include "method.h"
#include <iostream>
int main() {
	int a[] = { 1,2,4,5,1,2,8,9 };

	for (int i = 0; i < 8; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	hoar_sort(a, 0, 7);

	for (int i = 0; i < 8; i++) {
		std::cout << a[i] << " ";
	}

	return 0;
} 