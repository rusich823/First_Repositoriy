#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include "Bm_.h"
void findFirstBM(const std::string& text, const std::string& sub) {
    int n = text.size();
    int m = sub.size();

    if (m == 0 || m > n) return;

       std::vector<int> tabl(256, m);
    for (int i = 0; i < m - 1; i++) {
        tabl[sub[i]] = m - 1 - i;
    }

    for (int i = m - 1; i < n; ) {
        int k = i;    
        int j = m - 1; 

        while (j >= 0) {
             if (text[k] == sub[j]) {
                j--;
                k--;
            }
            else {
                break;
            }
        }

        if (j < 0) {
            std::cout << "Первый индекс вхождения подстроки: " << k + 1 << std::endl;
            return;
        }
        else {
            i = i + tabl[(unsigned char)text[i]];
        }
    }

    std::cout << "Подстрока не найдена." << std::endl;
}
