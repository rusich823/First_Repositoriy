#include "BoolVec.h"
#include <stdint.h>
#include <cstring>
#include <iostream>


int main() {
    setlocale(LC_ALL, "Russian");
    BoolVec vec("110010");
    std::cout << vec << std::endl;
    vec.swap_bit(1, 3);
    std::cout << vec << std::endl;
    vec.sdvig();
    std::cout << vec << std::endl;
    bool a =vec.equality();
    std::cout << a << std::endl;
    vec.revers();
    std::cout << vec << std::endl;



    return 0;
}


