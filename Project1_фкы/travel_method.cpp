#include "travel_method.h"
#include "Matr.h"


void swap(int& a, int& b) {
    int copy = a;
    a = b;
    b = copy;
}



bool next_deykstra_permutation(int* path, int N) {

    int i = N - 2;
    while (i >= 1 && path[i] >= path[i + 1]) {
        i--;
    }

    if (i < 1) return false;

    int j = N - 1;
    while (path[j] <= path[i]) {
        j--;
    }

    swap(path[i], path[j]);

    int L = i + 1;
    int R = N - 1;
    while (L < R) {
        swap(path[L], path[R]);
        L++;
        R--;
    }

    return true;
}
