#include <assert.h>
#include <iostream>
#include "DynamicArray.h"

// 1. Конструктор по умолчанию (без выделения памяти заранее)
DynamicArray::DynamicArray()
    : arrayData_(nullptr),
    arrayLength_(0),
    arrayCapacity_(0)
{
    std::cout << "DynamicArray::DynamicArray()" << std::endl;
}

// 2. Конструктор с параметрами
DynamicArray::DynamicArray(const int* const arrayData, const int arrayLength, const int arrayCapacity)
    : arrayData_(new int[arrayCapacity]),
    arrayLength_(arrayLength),
    arrayCapacity_(arrayCapacity)
{
    std::cout << "DynamicArray::DynamicArray(const int* const, const int)" << std::endl;

    for (int index = 0; index < arrayLength_; index++)
        arrayData_[index] = arrayData[index];
}

// 3. Конструктор копирования
DynamicArray::DynamicArray(const DynamicArray& other)
    : arrayData_(new int[other.arrayCapacity_]),
    arrayLength_(other.arrayLength_),
    arrayCapacity_(other.arrayCapacity_)
{
    std::cout << "DynamicArray::DynamicArray(const DynamicArray&)" << std::endl;

    for (int index = 0; index < arrayLength_; index++)
        arrayData_[index] = other.arrayData_[index];
}

// 4. Конструктор перемещения
DynamicArray::DynamicArray(DynamicArray&& other)
    : arrayData_(other.arrayData_),
    arrayLength_(other.arrayLength_),
    arrayCapacity_(other.arrayCapacity_)
{
    std::cout << "DynamicArray::DynamicArray(DynamicArray&&)" << std::endl;

    other.arrayLength_ = 0;
    other.arrayCapacity_ = 0;
    other.arrayData_ = nullptr;
}

// 5. Деструктор
DynamicArray::~DynamicArray()
{
    std::cout << "DynamicArray::~DynamicArray()" << std::endl;
    delete[] arrayData_;
}

// 6. Обычное копирующее присваивание
DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
    std::cout << "DynamicArray::operator=(const DynamicArray&)" << std::endl;

    if (this != &other)
    {
        delete[] arrayData_;

        arrayLength_ = other.arrayLength_;
        arrayCapacity_ = other.arrayCapacity_;
        arrayData_ = new int[arrayCapacity_];

        for (int index = 0; index < arrayLength_; index++)
            arrayData_[index] = other.arrayData_[index];
    }

    return *this;
}

// 7. Перемещающее присваивание
DynamicArray& DynamicArray::operator=(DynamicArray&& other)
{
    std::cout << "DynamicArray::operator=(DynamicArray&&)" << std::endl;

    if (this != &other)
    {
        delete[] arrayData_;

        arrayLength_ = other.arrayLength_;
        other.arrayLength_ = 0;

        arrayCapacity_ = other.arrayCapacity_;
        other.arrayCapacity_ = 0;

        arrayData_ = other.arrayData_;
        other.arrayData_ = nullptr;
    }

    return *this;
}

// 8. Геттеры размеров
int DynamicArray::getLength() const
{
    return arrayLength_;
}

int DynamicArray::getCapacity() const
{
    return arrayCapacity_;
}

// 9. Операторы квадратных скобок
int& DynamicArray::operator[](const int index)
{
    assert((index >= 0 && index < arrayLength_) && "Index is out of range.");
    return arrayData_[index];
}

const int& DynamicArray::operator[](const int index) const
{
    assert((index >= 0 && index < arrayLength_) && "Index is out of range.");
    return arrayData_[index];
}

// 10. Метод swap
void DynamicArray::swap(DynamicArray& other)
{
    int length = arrayLength_;
    arrayLength_ = other.arrayLength_;
    other.arrayLength_ = length;

    int capacity = arrayCapacity_;
    arrayCapacity_ = other.arrayCapacity_;
    other.arrayCapacity_ = capacity;

    int* data = arrayData_;
    arrayData_ = other.arrayData_;
    other.arrayData_ = data;
}

// 11.мой метод изменения размера массива
void DynamicArray::resize(int newCapacity)
{
    int* newData = new int[newCapacity];
    for (int index = 0; index < arrayLength_; index++)
    {
        newData[index] = arrayData_[index];
    }
    delete[] arrayData_;
    arrayData_ = newData;
    arrayCapacity_ = newCapacity;
}
