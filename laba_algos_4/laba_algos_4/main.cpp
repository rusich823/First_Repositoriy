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