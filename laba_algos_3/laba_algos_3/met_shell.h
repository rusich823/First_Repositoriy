#pragma once

#include <vector>    
#include <algorithm>

bool is_sorted(int const* mass, int const n);
void shell_sort(int * mass, int const n, const std::vector<int>& mas_h);
std::vector<int> knyt(int const n);
std::vector<int> shell(int const n);
std::vector<int> hibbart(int const n);