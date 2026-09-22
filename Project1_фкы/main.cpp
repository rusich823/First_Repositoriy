#include <iostream>
#include "Matr.h"
#include <random>

int main() {
    
    for (int i = 0; i < N; i++) {

        if (!isVisited(path, i) && matr[current_city][i] != 0) {

            path[count] = i;
            path.pop_back();
        }
    }
}