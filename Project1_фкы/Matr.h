#pragma once

int** Creat_eMatr(int nCities);
void Destroy_Matr(int** matrix, int nCities);
void fillimg_RandomMatr(int** matrix, int nCities, int minCost, int maxCost);
bool isVisited(const int* path, int count, int cit);