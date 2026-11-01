#include <iostream>
#include "met_shell.h"
#include<locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    // 1. Создаем небольшой тестовый массив из случайных чисел
    int const N = 12;
    int test_mass[N] = { 42, -10, 5, 0, 99, -3, 5, 14, 22, -100, 7, 1 };

    std::cout << "=== Тестирование алгоритма Шелла ===\n\n";

    // 2. Выводим массив до сортировки
    std::cout << "Исходный массив: ";
    for (int i = 0; i < N; i++) {
        std::cout << test_mass[i] << " ";
    }
    std::cout << "\n";

    // 3. Проверяем статус ДО сортировки
    std::cout << "Массив упорядочен? " << (is_sorted(test_mass, N) ? "ДА" : "НЕТ") << "\n\n";

    // 4. Запускаем твою сортировку Шелла
    std::cout << "Сортируем массив...\n";
    shell_sort(test_mass, N);

    // 5. Выводим массив ПОСЛЕ сортировки
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < N; i++) {
        std::cout << test_mass[i] << " ";
    }
    std::cout << "\n";

    // 6. Проверяем статус ПОСЛЕ сортировки
    std::cout << "Массив упорядочен? " << (is_sorted(test_mass, N) ? "ДА" : "НЕТ") << "\n\n";

    return 0;
}