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

std::vector<int> findAllBM(const std::string& text, const std::string& sub) {
    int n = text.size();
    int m = sub.size();
    std::vector<int> positions;

    if (m == 0 || m > n) {
        return positions;
    }

    std::vector<int> tabl(256, m);
    for (int i = 0; i < m - 1; i++) {
        tabl[(unsigned char)sub[i]] = m - 1 - i;
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
            positions.push_back(k + 1);
            i += 1;
        }
        else {
            i = i + tabl[(unsigned char)text[i]];
        }
    }

    return positions;
}
std::vector<int> findAllBM_gr(const std::string& text, const std::string& sub, int start, int end) {
    int n = text.size();
    int m = sub.size();
    std::vector<int> positions;

    if (m == 0 || m > n || start < 0 || end >= n || start > end) {
        return positions;
    }

    std::vector<int> tabl(256, m);
    for (int i = 0; i < m - 1; i++) {
        tabl[(unsigned char)sub[i]] = m - 1 - i;
    }

    for (int i = start + m - 1; i <= end; ) {
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
            positions.push_back(k + 1);
            i += 1;
        }
        else {
            i = i + tabl[(unsigned char)text[i]];
        }
    }

    return positions;
}
    