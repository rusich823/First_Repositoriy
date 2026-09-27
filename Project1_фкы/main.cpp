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


            std::chrono::high_resolution_clock::time_point timeBeginExact = std::chrono::high_resolution_clock::now();

            int* path = new int[N];
            for (int i = 0; i < N; i++) path[i] = i;

            int min_cost = 2147483647;

            do {
                int current_cost = 0;
                bool valid_route = true;

                for (int i = 0; i < N - 1; i++) {
                    if (matr[path[i]][path[i + 1]] == 0) { valid_route = false; break; }
                    current_cost += matr[path[i]][path[i + 1]];
                }

                if (matr[path[N - 1]][path[0]] == 0) valid_route = false;
                else current_cost += matr[path[N - 1]][path[0]];

                if (valid_route && current_cost < min_cost) {
                    min_cost = current_cost;

                }

            } while (next_deykstra_permutation(path, N));
            std::chrono::high_resolution_clock::time_point timeEndExact = std::chrono::high_resolution_clock::now();
            std::chrono::milliseconds intervalExact = std::chrono::duration_cast<std::chrono::milliseconds>(timeEndExact - timeBeginExact);

            std::cout << "[Точный перебор]" << std::endl;
            std::cout << "Стоимость: " << min_cost << std::endl;
            std::cout << "Время: " << intervalExact.count() / 1000.0 << " сек." << std::endl;

            //std::chrono::high_resolution_clock::time_point timeBeginGreedy = std::chrono::high_resolution_clock::now();
          
            //std::chrono::high_resolution_clock::time_point timeEndGreedy = std::chrono::high_resolution_clock::now();
            //std::chrono::milliseconds intervalGreedy = std::chrono::duration_cast<std::chrono::milliseconds>(timeEndGreedy - timeBeginGreedy);

            //std::cout << "[Метод худшей строки]" << std::endl;
            //std::cout << "Стоимость: " << total_cost << std::endl;
            //std::cout << "Время: " << intervalGreedy.count() / 1000.0 << " сек." << std::endl;

            Destroy_Matr(matr, N);
            delete[] path;
          
        }
    }
    return 0;
}
