#include "Pyramid_sort.h"
#include <locale.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <chrono>
#include <vector>
void test_speed(const std::string& filename, int const size) {
	std::ifstream fin(filename);
	if (!fin.is_open()) {
		std::cout << "Файл не открылся: " << filename << "\n";
		return;
	}
	std::vector<int> original_arr(size);
	for (int i = 0; i < size; i++) {
		fin >> original_arr[i];
	}
	fin.close();

	double time_shell = 0.0;

	for (int run = 0; run < 3; run++) {
		std::vector<int> arr_shell = original_arr;
		auto start = std::chrono::high_resolution_clock::now();
		Sort_Pyro(&arr_shell[0], size);
		auto end = std::chrono::high_resolution_clock::now();
		time_shell += std::chrono::duration<double, std::milli>(end - start).count();

	}
	std::cout << size << "\t" << filename
		<< "\tПирамидальная сортировка: " << (time_shell / 3.0) << " мс\n";
}
int main() {
		setlocale(LC_ALL, "Russian");

		int sizes[3] = { 10000, 100000, 1000000 };
		int minVals[3] = { -10, -1000, -100000 };
		int maxVals[3] = { 10, 1000, 100000 };
		const char* filenames[3][3] = {
		{ "arr_10000_10.txt", "arr_10000_1000.txt", "arr_10000_100000.txt" },
		{ "arr_100000_10.txt", "arr_100000_1000.txt", "arr_100000_100000.txt" },
		{ "arr_1000000_10.txt", "arr_1000000_1000.txt", "arr_1000000_100000.txt" }
		};

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				test_speed(filenames[i][j], sizes[i]);

			}
		}

		return 0;
	}