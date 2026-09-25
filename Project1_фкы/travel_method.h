#pragma once
int worst_line(int** matr, int N, int* path, int count);
void Greedy_Worst_Row(int** matr, int N, int* path, int count, int& total_cost);
void City_Check(int** matr, int N, int* path, int count, int current_city, int& min_cost, int* best_path);