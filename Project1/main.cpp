#include <iostream>
#include "DynamicArray.h"

int main() {
    DynamicArray arr;
    std::cout << "Initial array: " << arr << std::endl;

    std::cin >> arr;
    std::cout << "Your array: " << arr << std::endl;

    arr += 50;
    std::cout << "After += 50: " << arr << " (Size: " << arr.getLength() << ")" << std::endl;

    std::cout << "Max element: " << arr.findMax() << std::endl;
    std::cout << "Min element: " << arr.findMin() << std::endl;

    arr += 5;
    std::cout << "Before sort: " << arr << std::endl;
    arr.sort();
    std::cout << "After sort: " << arr << std::endl;

    arr.removeAt(1);
    std::cout << "After removing element at index 1: " << arr << std::endl;

    auto it = arr.begin();
    ++it;
    arr.insert(it, 99);
    std::cout << "After iterator insert (99): " << arr << std::endl;

    return 0;
}
