#include "Matr.h"
#include <random>
#include <vector> 

std::vector<std::vector<int>> Matr_Create(int nCities) {

    std::vector<std::vector<int>> matrix;

    for (int i = 0; i < nCities; i++) {

        std::vector<int> row(nCities, 0);

        matrix.push_back(row);
    }

    return matrix;
}

void fillRandomMatr(std::vector<std::vector<int>>& matrix, int minCost, int maxCost) {

    int nCities = matrix.size();

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(minCost, maxCost);


    for (int i = 0; i < nCities; i++) {

        for (int j = 0; j < nCities; j++) {

            if (i == j) {
                matrix[i][j] = 0;
            }

            else {
                matrix[i][j] = distribution(generator);
            }

        }
    }
}
bool isVisited(const std::vector<int>& path, int city) {
    for (int i = 0; i < path.size(); i++) {

        if (path[i] == city) return true;

    }
    return false;
}
