#include <iostream>
#include "Matr.h"
#include <random>
#include <chrono>
#include <clocale>

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


    int main() {
        setlocale(LC_ALL, "ru_RU.UTF-8");
        int N ;

        std::cout << "Введите количество городов для теста: ";
        std::cin >> N;

        int** matr = Creat_eMatr(N);
        fillimg_RandomMatr(matr, N, 10, 100);

        int* path = new int[N];
        int* best_path = new int[N];

        int start_ct = 0;
        path[0] = start_ct;
        int min_cost = 2147483647;
        
        std::chrono::high_resolution_clock::time_point timeBegin = std::chrono::high_resolution_clock::now();

        City_Check(matr, N, path, 1, start_ct, min_cost, best_path);

        std::chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();

        std::chrono::milliseconds interval = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeBegin);

        std::cout << "Количество городов: " << N << std::endl;
        std::cout << "Минимальная стоимость: " << min_cost << std::endl;
        std::cout << "Время " << interval.count() / 1000.0 << std::endl;

        Destroy_Matr(matr, N);
        delete[] path;
        delete[] best_path;

        return 0;
        
}