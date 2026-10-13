#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Bm_.h"



int main() {
    setlocale(LC_ALL, ".UTF8");

 
    std::string text = "ramumama myla ";
    std::string sub = "ramu";

    std::cout << "Text: " << text << std::endl;
    std::cout << "Sub: " << sub << std::endl;

    findFirstBM(text, sub);

    std::string text1 = "ramumama myla ramu , myla mama ramu ";
    std::string sub1 = "ma";


    std::cout << "Text1: " << text1 << std::endl;
    std::cout << "Sub: " << sub1 << std::endl;

    std::vector<int> results = findAllBM(text1, sub1);

    std::cout << "Indices found: ";     
    for (size_t i = 0; i < results.size(); i++) {
        std::cout << results[i] << " ";
    }
    std::cout << std::endl;
   


    int start, end;
    std::cout << "Введите start и end:\n";
    std::cin >> start >> end;


    std::vector<int> range_indices = findAllBM_gr(text1, sub1, start, end);

    std::cout << "Indices found: ";
    for (int idx : range_indices) {
        std::cout << idx << " ";
    }



    return 0;
}