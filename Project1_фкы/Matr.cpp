#include "Matr.h"
#include <random>

int** Creat_eMatr(int nCities) {
    int** matrix = new int* [nCities];
    for (int i = 0; i < nCities; i++) {
        matrix[i] = new int[nCities];
    }
    return matrix;
}

void Destroy_Matr(int** matrix, int nCities) {
    for (int i = 0; i < nCities; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fillimg_RandomMatr(int** matrix, int nCities, int minCost , int maxCost) {
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

bool isVisited(const int* path, int count, int cit) {
    for (int i = 0; i < count; i++) {

        if (path[i] == cit) return true;

    }
    return false;
}
