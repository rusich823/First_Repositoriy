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
void Greedy_Worst_Row_Iterative(int** matr, int n, int* path, int& total_cost) {
    int count = 1;
    int* sum_str = new int[n];

    while (count < n) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            if (isVisited(path, count, i)) {
                sum_str[i] = -2;
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!isVisited(path, count, j)) {
                    sum += matr[i][j];
                }
            }
            sum_str[i] = sum;
        }

        int max_sum = 0;
        int indx = 0;
        for (int i = 0; i < n; i++) {
            if (sum_str[i] > max_sum) {
                max_sum = sum_str[i];
                indx = i;
            }
        }

        if (indx <0 || indx >= n) break;

        int min_rl = 0;
        int best_city = 0;
        for (int i = 0; i < n; i++) {
            if (!isVisited(path, count, i) && matr[indx][i] != 0) {
                if (matr[indx][i] < min_rl) {
                    min_rl = matr[indx][i];
                    best_city = i;
                }
            }
        }

        if (best_city != -1) {
            path[count] = best_city;
            total_cost += min_rl;
            count++;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (!isVisited(path, count, i)) {
                    path[count] = i;
                    total_cost += matr[path[count - 1]][i];
                    count++;
                    break;
                }
            }
        }
    }

    int last_city = path[n - 1];
    int start_city = path[0];
    if (matr[last_city][start_city] != 0) {
        total_cost += matr[last_city][start_city];
    }

    delete[] sum_str;
}
