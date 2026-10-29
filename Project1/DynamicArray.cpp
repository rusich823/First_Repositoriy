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
// оператор добавления в конец массива число
DynamicArray& DynamicArray::operator+=(const int value) {
    if (arrayLength_ == arrayCapacity_)
    {
        int newCapacity;
        if (arrayCapacity_ == 0) {
            newCapacity = 1;
        }
        else {
            newCapacity = arrayCapacity_ * 2;
        }
        resize(newCapacity);
    }

    arrayData_[arrayLength_] = value;
    arrayLength_++;

    return *this;
}
//
DynamicArray& DynamicArray::operator+=(const DynamicArray& other) {
    if (arrayCapacity_ < arrayLength_ + other.arrayLength_) {
        resize(arrayLength_ + other.arrayLength_);
    }
    for (int j=0; j < other.arrayLength_; j++) {
        arrayData_[arrayLength_ + j] = other.arrayData_[j];
    }
    arrayLength_ += other.arrayLength_;
    return *this;
}
//
bool DynamicArray::operator==(const DynamicArray& other) const {
    if (arrayLength_ == other.arrayLength_) {
        for (int i = 0; i < arrayLength_; i++) {
            if (arrayData_[i] != other.arrayData_[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}
//
bool DynamicArray::operator!=(const DynamicArray& other) const {
    if (arrayLength_ != other.arrayLength_) return true;
    return !(*this == other);
}

//
DynamicArray DynamicArray::operator+(const  DynamicArray& other) const {
    DynamicArray newArray(*this);
    newArray += other;
    return newArray;
}
//оператор добавлени в конец числа
DynamicArray DynamicArray::operator+(const int newarrayData) const
{
    DynamicArray newArray(*this);
    newArray += newarrayData;
    return newArray;
}
// метод поиска элемента по значению (возвращает индекс или -1)
int DynamicArray::find(const int value) const
{
    for (int i = 0; i < arrayLength_; i++) {
        if (arrayData_[i] == value) return i;
    }
    return -1;
}

// поиск максимального элемента в массиве
int DynamicArray::findMax() const {
    if (arrayLength_) {
        int max = arrayData_[0];
        for (int i = 1; i < arrayLength_; i++) {
            if (arrayData_[i] > max) max = arrayData_[i];
        }
        return max;
    }
    else return 0;
}

//  поиск минимального элемента в массиве
int DynamicArray::findMin() const {
    if (arrayLength_) {
        int min = arrayData_[0];
        for (int i = 1; i < arrayLength_; i++) {
            if (arrayData_[i] < min) min = arrayData_[i];
        }
        return min;
    }
    else return 0;
}

//  сортировка массива по возрастанию
void DynamicArray::sort() {
    if (arrayLength_) {
        int a = 0;
        for (int i = 0; i < arrayLength_ - 1; i++) {
            for (int j = 0; j < arrayLength_ - 1; j++) {
                if (arrayData_[j + 1] < arrayData_[j]) {
                    a = arrayData_[j + 1];
                    arrayData_[j + 1] = arrayData_[j];
                    arrayData_[j] = a;
                }
            }
        }
    }
    else std::cout << "error";
}

//  вставка элемента по индексу
bool DynamicArray::insert(int index, int value) {
    if (index >= 0 && index <= arrayLength_) {
        if (arrayLength_ == arrayCapacity_)
        {
            int newCapacity;
            if (arrayCapacity_ == 0) {
                newCapacity = 1;
            }
            else {
                newCapacity = arrayCapacity_ * 2;
            }
            resize(newCapacity);
        }
        for (int i = arrayLength_ - 1; i >= index; i--) {
            arrayData_[i + 1] = arrayData_[i];
        }
        arrayData_[index] = value;
        arrayLength_++;
        return true;
    }
    return false;
}
//
bool DynamicArray::removeAt(int index) {
    if (index >= 0 && index < arrayLength_) {
        for (int i = index; i < arrayLength_-1; i++) {
            arrayData_[i ] = arrayData_[i+1];
        }
        arrayLength_--;
        return true;
    }
    return false;
}
//
bool DynamicArray::removeByValue(int value) {
    if (arrayLength_) {
        for (int i = 0; i < arrayLength_; i++) {
            if (arrayData_[i] == value) {
                removeAt(i);
                return true;
            }
        }
        return false;
    }
}
//
bool DynamicArray::removeAll(int value) {
    if (arrayLength_) {
        for (int i = 0; i < arrayLength_; i++) {
            if (arrayData_[i] == value) {
                removeAt(i); 
                i--;
            }
        }
    return true;
    }
    return false;
}
// потоковый вывод
std::ostream& operator<<(std::ostream& out, const DynamicArray& s)
{
    for (int i = 0; i < s.arrayLength_; i++) {
        out << s.arrayData_[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& inp, DynamicArray& s)
{
    int count = 0;
    inp >> count;
    std::cout << "\nВведите массив чисел, в конце Enter: ";

    s.arrayLength_ = 0;
    for (int i = 0; i < count; i++) {
        int value = 0;
        inp >> value;

        s += value;
    }

    return inp;
}

// итераторы
DynamicArray::iterator::iterator(int* arrayData, int elementIn) : arrayData_(arrayData), elementIndex_(elementIn)
{
}
//
int& DynamicArray::iterator::operator*()
{
    return arrayData_[elementIndex_];
}











