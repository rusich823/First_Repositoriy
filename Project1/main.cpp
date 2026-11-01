#include <iostream>
#include "DynamicArray.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    DynamicArray arr;
    std::cout << "Введите массив: " << arr ;
    std::cin >> arr;
    
    std::cout << "Ваш массив: " << arr << std::endl;

    arr += 50;
    std::cout << "После += 50: " << arr << " (Размер: " << arr.getLength() << ")" << std::endl;

    std::cout << "Максимальный элемент: " << arr.findMax() << std::endl;
    std::cout << "Минимальный элемент: " << arr.findMin() << std::endl;

    arr += 5;
    std::cout << "Перед сортировкой: " << arr << std::endl;
    arr.sort();
    std::cout << "После сортировки: " << arr << std::endl;

    arr.removeAt(1);
    std::cout << "После удаления элемента по индексу 1: " << arr << std::endl;

    auto it = arr.begin();
    ++it;
    arr.insert(it, 99);
    std::cout << "После вставки по итератору (99): " << arr << std::endl;

    return 0;
}
