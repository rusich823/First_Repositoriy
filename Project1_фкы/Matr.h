#pragma once

std::vector<std::vector<int>> Matr_Create(int nCities);
void fillRandomMatr(std::vector<std::vector<int>>& matrix, int minCost, int maxCost);
bool isVisited(const std::vector<int>& path, int city);