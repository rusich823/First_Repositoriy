#include "BoolVec.h"
#include <stdint.h>
#include <cstring>
#include <iostream>


int main() {
    setlocale(LC_ALL, "Russian");

   BoolVec v1(6, false);
    BoolVec v2("101100");
    BoolVec v3 = v2;
    v1.swap(v3);
    std::cout << "v1 после swap: " << v1 << "\n";
    std::cout << "v3 после swap: " << v3 << "\n\n";

    BoolVec a("110010");
    BoolVec b("101011");
    std::cout << "~a:     " << ~a << "\n";
    std::cout << "a & b:  " << (a & b) << "\n";
    std::cout << "a | b:  " << (a | b) << "\n";
    std::cout << "a ^ b:  " << (a ^ b) << "\n";
    std::cout << "a << 2: " << (a << 2) << "\n";
    std::cout << "a >> 2: " << (a >> 2) << "\n\n";

    BoolVec g("100101");
    std::cout << "Вес g: " << g.weight() << "\n";
    g.invert_id(0);
    g.add_k_id(2, 3, true);
    std::cout << "g после изменений: " << g << "\n";

    g &= BoolVec("111000");
    g <<= 1;
    std::cout << "g после &= и <<=:  " << g << "\n\n";

    BoolVec p("1001");
    p[1] = p[0];
    p[2] |= true;
    std::cout << "p после BitReference: " << p << "\n";
    std::cout << "p[0] == true: " << (p[0] == true) << "\n\n";

    std::cout << "Введите размер и биты (например 4 1 0 1 1): ";
    BoolVec inVec;
    std::cin >> inVec;
    std::cout << "Введено: " << inVec << "\n";


    return 0;
}


