    #include <iostream>
    #include <fstream>
    #include <random>
    #include <string>    
    #include <locale.h>
    #include "met_shell.h"
    #include <chrono>

    void test_speed(const std::string& filename, int const size) {
        std::ifstream fin(filename);
        if (!fin.is_open()) {
            std::cout << "‘‡ÈÎ ÌÂ ÓÚÍ˚ÎÒˇ: " << filename << "\n";
            return;
        }
        std::vector<int> original_arr(size);
        for (int i = 0; i < size; i++) {
            fin >> original_arr[i];
        }
        fin.close();

        std::vector<int> gaps_shell = shell(size);
        std::vector<int> gaps_hibbart = hibbart(size);
        std::vector<int> gaps_knyt = knyt(size);

        double time_shell = 0.0, time_hibbart = 0.0, time_knyt = 0.0;

        for (int run = 0; run < 3; run++) {
            // --- 1. “≈—“ ÿ≈ÀÀ¿ ---
            std::vector<int> arr_shell = original_arr;
            auto start = std::chrono::high_resolution_clock::now();
            shell_sort(&arr_shell[0], size, gaps_shell);
            auto end = std::chrono::high_resolution_clock::now();
            time_shell += std::chrono::duration<double, std::milli>(end - start).count();

            // --- 2. “≈—“ ’»¡¡¿–ƒ¿ ---
            std::vector<int> arr_hibbart = original_arr;
            start = std::chrono::high_resolution_clock::now();
            shell_sort(&arr_hibbart[0], size, gaps_hibbart);
            end = std::chrono::high_resolution_clock::now();
            time_hibbart += std::chrono::duration<double, std::milli>(end - start).count();

            // --- 3. “≈—“  Õ”“¿ ---
            std::vector<int> arr_knyt = original_arr;
            start = std::chrono::high_resolution_clock::now();
            shell_sort(&arr_knyt[0], size, gaps_knyt);
            end = std::chrono::high_resolution_clock::now();
            time_knyt += std::chrono::duration<double, std::milli>(end - start).count();
        }

        std::cout << size << "\t" << filename
            << "\tÿÂÎÎ: " << (time_shell / 3.0) << " ÏÒ"
            << "\t’Ë··‡‰: " << (time_hibbart / 3.0) << " ÏÒ"
            << "\t ÌÛÚ: " << (time_knyt / 3.0) << " ÏÒ\n";
     
    }


    int main() {
        setlocale(LC_ALL, "Russian");
        int sizes[3] = { 10000, 100000, 1000000 };
        int minVals[3] = { -10, -1000, -100000 };
        int maxVals[3] = { 10, 1000, 100000 };
        const char* filenames[3][3] = {
        { "arr_10000_10.txt", "arr_10000_1000.txt", "arr_10000_100000.txt" },
        { "arr_100000_10.txt", "arr_100000_1000.txt", "arr_100000_100000.txt" },
        { "arr_1000000_10.txt", "arr_1000000_1000.txt", "arr_1000000_100000.txt" }
    };
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                test_speed(filenames[i][j], sizes[i]);
              
            }
        }

        return 0;
    }