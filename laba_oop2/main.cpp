#include <iostream>
#include <string>
#include <locale.h>
#include "Temple_array.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== ТЕСТ 1: ИНТЫ ===" << std::endl;
    DynamicArray<int> arr;

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


    std::cout << "\n=== ТЕСТ 2: ШАБЛОН НА СТРОКАХ ===" << std::endl;
    DynamicArray<std::string> strArr;

    strArr += "Яблоко";
    strArr += "Груша";
    strArr += "Апельсин";
    strArr += "Банан";

    std::cout << "Массив строк: " << strArr << std::endl;

    int index = strArr.find("Апельсин");
    std::cout << "Индекс элемента 'Апельсин': " << index << std::endl;

    strArr.sort();
    std::cout << "Строки после сортировки: " << strArr << std::endl;


    std::cout << "\n=== ТЕСТ 3: КОНСТАНТНЫЕ ИТЕРАТОРЫ И ПЕРЕМЕЩЕНИЕ ===" << std::endl;
    // Просто вывод через константный итератор
    std::cout << "Вывод через const_iterator: ";
    for (auto cit = strArr.cbegin(); cit != strArr.cend(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    // Проверка мув-конструктора
    std::cout << "\nПеремещаем массив..." << std::endl;
    DynamicArray<int> movedArr = std::move(arr);
    std::cout << "Новый массив: " << movedArr << std::endl;
    std::cout << "Размер старого: " << arr.getLength() << std::endl;

    return 0;
}
