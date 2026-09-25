#include "travel_method.h"
#include "Matr.h"

int worst_line(int** matr, int N, int* path, int count) {
    int max_sum = -1;
    int worst_row_index = -1;

    for (int i = 0; i < N; i++) {
        if (isVisited(path, count, i)) continue;

        int sum_str = 0;
        for (int j = 0; j < N; j++) {
            if (!isVisited(path, count, j)) {
                sum_str += matr[i][j];
            }
        }

        if (sum_str > max_sum) {
            max_sum = sum_str;
            worst_row_index = i;
        }
    }
    return worst_row_index;
}

void Greedy_Worst_Row(int** matr, int N, int* path, int count, int& total_cost) {
    if (count == N) {
        int last_city = path[N - 1];
        int start_city = path[0];
        if (matr[last_city][start_city] != 0) {
            total_cost += matr[last_city][start_city];
        }
        return;
    }

    int index_worst = worst_line(matr, N, path, count);

    int min_road = 1000;
    int best_city_to_go = -1;

    for (int j = 0; j < N; j++) {
        if (!isVisited(path, count, j) && matr[index_worst][j] != 0) {
            if (matr[index_worst][j] < min_road) {
                min_road = matr[index_worst][j];
                best_city_to_go = j;
            }
        }
    }

    if (best_city_to_go != -1) {
        path[count] = best_city_to_go;
        total_cost += min_road;
        Greedy_Worst_Row(matr, N, path, count + 1, total_cost);
    }
}


void City_Check(int** matr, int N, int* path, int count, int current_city, int& min_cost, int* best_path) {
    if (count == N) {
        int Last_ct = path[N - 1];
        int start_ct = path[0];

        if (matr[Last_ct][start_ct] != 0) {
            int current_cost = 0;

            for (int i = 0; i < N - 1; i++) {
                current_cost += matr[path[i]][path[i + 1]];
            }
            current_cost += matr[Last_ct][start_ct];

            if (current_cost < min_cost) {
                min_cost = current_cost;
                for (int i = 0; i < N; i++) {
                    best_path[i] = path[i];
                }
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isVisited(path, count, i) && matr[current_city][i] != 0) {
            path[count] = i;
            City_Check(matr, N, path, count + 1, i, min_cost, best_path);
        }
    }
}
