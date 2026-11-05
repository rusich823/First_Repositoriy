#include <iostream>
#include <fstream>
#include <random>
#include <string>    
#include <locale.h>
#include "met_shell.h"

    void generate_file(int const size, int const min_val, int const max_val,  const std::string  filename) {
        std::mt19937 gen(1337);
        std::uniform_int_distribution<int> dist(min_val, max_val);
        std::ofstream fout(filename);
        for (int i = 0; i < size; ++i) {
            fout << dist(gen);
            if (i != size - 1) {
                fout << " "; 
            }
        }

        fout.close(); 
    }



int main() {
    setlocale(LC_ALL, "Russian");

    int sizzes[3] = { 10000, 100000, 1000000 };
    int minVals[3] = { -10, -1000, -100000 };
    int maxVals[3] = { 10, 1000, 100000 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::string filename = "arr_" + std::to_string(sizzes[i]) + "_" + std::to_string(maxVals[j]) + ".txt";
            generate_file(sizzes[i], minVals[j], maxVals[j],filename);
        }
    }
    return 0;
}