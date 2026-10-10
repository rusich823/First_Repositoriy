#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Bm_.h"



int main() {
    setlocale(LC_ALL, ".UTF8");

    // Тестовые строки для проверки алгоритма
    std::string text = "ramumama myla ";
    std::string sub = "ramu";

    std::cout << "Text: " << text << std::endl;
    std::cout << "Sub: " << sub << std::endl;

    // Запускаем твою первую функцию поиска
    findFirstBM(text, sub);
    

    std::string text1 = "ramumama myla ramu , myla mama ramu ";
    std::string sub1 = "ramu";


    std::cout << "Text: " << text1 << std::endl;
    std::cout << "Sub: " << sub1 << std::endl;

    std::vector<int> results = findAllBM(text1, sub1);

    std::cout << "Indices found: ";
    for (size_t i = 0; i < results.size(); i++) {
        std::cout << results[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}