#include <iostream>
#include <fstream>
#include <random>
#include <string>    
#include <locale.h>
#include "met_shell.h"
#include <chrono>



int main() {
    setlocale(LC_ALL, "Russian");
    int const N = 10;
    int const original[N] = { 23, -5, 8, 0, 99, -12, 4, 7, 42, 1 };

    std::cout << "=== Проверка функций генерации шагов и сортировки ===\n\n";

    // 1. Тестируем шаги Шелла
    int mass_shell[N];
    std::copy(original, original + N, mass_shell); 
    std::vector<int> gaps_shell = shell(N);

    std::cout << "Шаги Шелла для N=" << N << ": ";
    for (int g : gaps_shell) std::cout << g << " ";
    std::cout << "\n";

    shell_sort(mass_shell, N, gaps_shell);
    std::cout << "Шелл отсортировал? " << (is_sorted(mass_shell, N) ? "ДА" : "НЕТ") << "\n\n";

    // 2. Тестируем шаги Хиббарда
    int mass_hibbart[N];
    std::copy(original, original + N, mass_hibbart);
    std::vector<int> gaps_hibbart = hibbart(N);

    std::cout << "Шаги Хиббарда для N=" << N << ": ";
    for (int g : gaps_hibbart) std::cout << g << " ";
    std::cout << "\n";

    shell_sort(mass_hibbart, N, gaps_hibbart);
    std::cout << "Хиббард отсортировал? " << (is_sorted(mass_hibbart, N) ? "ДА" : "НЕТ") << "\n\n";

    // 3. Тестируем шаги Кнута
    int mass_knyt[N];
    std::copy(original, original + N, mass_knyt);
    std::vector<int> gaps_knyt = knyt(N);

    std::cout << "Шаги Кнута для N=" << N << ": ";
    for (int g : gaps_knyt) std::cout << g << " ";
    std::cout << "\n";

    shell_sort(mass_knyt, N, gaps_knyt);
    std::cout << "Кнут отсортировал? " << (is_sorted(mass_knyt, N) ? "ДА" : "НЕТ") << "\n\n";

    return 0;
}