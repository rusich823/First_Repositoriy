#include <iostream>
#include "Matr.h"
#include <random>
#include <chrono>
#include <clocale>
#include "travel_method.h"


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int sizes[] = { 4, 6, 8, 10, 12 };

    for (int i = 0; i < 5; i++) {
        int N = sizes[i];
        std::cout << "\n=============================================" << std::endl;
        std::cout << "--- ТЕСТИРОВАНИЕ ДЛЯ N = " << N << " ---" << std::endl;
        std::cout << "=============================================" << std::endl;

        for (int test = 1; test <= 4; test++) {
            std::cout << "\n--- Тест №" << test << " ---" << std::endl;

            int** matr = Creat_eMatr(N);
            fillimg_RandomMatr(matr, N, 10, 1000);

            int start_ct = 0;

            int* path = new int[N];
            int* best_path = new int[N];
            path[0] = start_ct;
            int min_cost = 100;

            std::chrono::high_resolution_clock::time_point timeBeginExact = std::chrono::high_resolution_clock::now();
            City_Check(matr, N, path, 1, start_ct, min_cost, best_path);
            std::chrono::high_resolution_clock::time_point timeEndExact = std::chrono::high_resolution_clock::now();
            std::chrono::milliseconds intervalExact = std::chrono::duration_cast<std::chrono::milliseconds>(timeEndExact - timeBeginExact);

            std::cout << "[Точный перебор]" << std::endl;
            std::cout << "Стоимость: " << min_cost << std::endl;
            std::cout << "Время: " << intervalExact.count() / 1000.0 << " сек." << std::endl;

            int* path_greedy = new int[N];
            path_greedy[0] = start_ct;
            int total_cost = 0;

            std::chrono::high_resolution_clock::time_point timeBeginGreedy = std::chrono::high_resolution_clock::now();
            Greedy_Worst_Row(matr, N, path_greedy, 1, total_cost);
            std::chrono::high_resolution_clock::time_point timeEndGreedy = std::chrono::high_resolution_clock::now();
            std::chrono::milliseconds intervalGreedy = std::chrono::duration_cast<std::chrono::milliseconds>(timeEndGreedy - timeBeginGreedy);

            std::cout << "[Метод худшей строки]" << std::endl;
            std::cout << "Стоимость: " << total_cost << std::endl;
            std::cout << "Время: " << intervalGreedy.count() / 1000.0 << " сек." << std::endl;

            Destroy_Matr(matr, N);
            delete[] path;
            delete[] best_path;
            delete[] path_greedy;
        }
    }
    return 0;
}
