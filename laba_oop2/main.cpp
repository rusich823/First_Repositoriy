#include <iostream>
#include <string>
#include <locale.h>
#include "DynamicArray.h"
#include "Temple_array.h"
#include <random>




int main() {
    setlocale(LC_ALL, "Russian");
#if 0

    std::cout << "=== ЧАСТЬ 1: ПРОВЕРКА ОБЫЧНОГО МАССИВА (IntDynamicArray) ===" << std::endl;
    IntDynamicArray intArr;

    std::cin >> intArr;
    std::cout << "Ваш массив: " << intArr << std::endl;
    intArr += 50;
    std::cout << "После += 50: " << intArr << " (Размер: " << intArr.getLength() << ")" << std::endl;

    std::cout << "Максимальный элемент: " << intArr.findMax() << std::endl;
    std::cout << "Минимальный элемент: " << intArr.findMin() << std::endl;

    intArr += 5;
    std::cout << "Перед сортировкой: " << intArr << std::endl;
    intArr.sort();
    std::cout << "После сортировки: " << intArr << std::endl;

    int c =intArr.removeAt(3);
    std::cout << "deletaAt 3  : " << c << std::endl;
    std::cout << "массив после изменений " << intArr << std::endl;
     int a=intArr.removeAll(1);
    std::cout << "deletall 1  : " << a << std::endl;
    std::cout << "массив после изменений " << intArr << std::endl;
    int v = intArr.removeByValue(5);
    std::cout << "deletatByValue 5 : " << v << std::endl;
    std::cout << "массив после изменений " << intArr << std::endl;
#endif

    std::random_device rd;          
    std::mt19937 gen(rd());         
    std::uniform_int_distribution<int> dist(-50, 50);
    DynamicArray <DynamicArray<int>> matr;
    int n;
    std::cout << "Введите размер матрицы : ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        DynamicArray<int> row;
        for (int j = 0; j < n; j++) {
            row += dist(gen);
        }
        matr += row;
    }
    std::cout << "\nСгенерированная матрица:\n";
    for (int i = 0; i < matr.getLength(); i++) {
        for (int j = 0; j < matr[i].getLength(); j++) {
            std::cout << matr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << matr[1][1];


#if 0
    auto it1 = intArr.begin();
    ++it1;
    intArr.insert(it1, 99);
    std::cout << "После вставки по итератору (99): " << intArr << std::endl;


    std::cout << "\n=== ЧАСТЬ 2: ПРОВЕРКА ШАБЛОННОЙ ВЕРСИИ (DynamicArray<T>) ===" << std::endl;

    std::cout << "\n--- Тест шаблона на числах (int) ---" << std::endl;
    DynamicArray<int> templateIntArr;

    std::cin >> templateIntArr;
    std::cout << "Ваш шаблонный массив: " << templateIntArr << std::endl;

    templateIntArr.sort();
    std::cout << "После сортировки шаблона: " << templateIntArr << std::endl;

    auto it2 = templateIntArr.begin();
    ++it2;
    templateIntArr.insert(it2, 777);
    std::cout << "После вставки по итератору (777): " << templateIntArr << std::endl;


    std::cout << "\n--- Тест шаблона на строках (std::string) ---" << std::endl;
    DynamicArray<std::string> strArr;

    strArr += "Яблоко";
    strArr += "Груша";
    strArr += "Апельсин";
    strArr += "Банан";

    std::cout << "Массив строк: " << strArr << std::endl;

    int index = strArr.find("Апельсин");
    std::cout << "Индекс элемента 'Апельсин': " << index << std::endl;

    strArr.sort();
    std::cout << "Строки после сортировки по алфавиту: " << strArr << std::endl;


    std::cout << "\n--- Тест константных итераторов и перемещения шаблона ---" << std::endl;
    std::cout << "Вывод через const_iterator: ";
    for (auto cit = strArr.cbegin(); cit != strArr.cend(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    std::cout << "\nПеремещаем шаблонный массив чисел..." << std::endl;
    DynamicArray<int> movedArr = std::move(templateIntArr);
    std::cout << "Новый перемещенный массив: " << movedArr << std::endl;
    std::cout << "Размер старого массива: " << templateIntArr.getLength() << std::endl;
#endif
    return 0;
}
