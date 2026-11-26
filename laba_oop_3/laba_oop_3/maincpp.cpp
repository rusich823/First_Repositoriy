#include "BoolVec.h"
#include <stdint.h>
#include <cstring>
#include <iostream>


int main() {
    setlocale(LC_ALL, "Russian");
    BoolVec vec("01111");
    BoolVec vec1("00111");
    std::cout << vec << std::endl;
    std::cout << vec1 << std::endl;
    vec.comparison(vec1);
    vec.swap_bit(1, 3);
    std::cout << vec << std::endl;
    vec.sdvig();
    std::cout << vec << std::endl;
    bool a =vec.equality();
    std::cout << a << std::endl;
    vec.revers();
    std::cout << vec << std::endl;
    vec.revers_id(1, 4);
    std::cout << vec << std::endl;
    std::cout << vec.find_1() << std::endl;
    std::cout << vec.find_last_1() << std::endl;
    return 0;
}


