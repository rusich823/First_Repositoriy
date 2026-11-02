#include <assert.h>
#include <iostream>
#include "DynamicArray.h"


    //  онструктор по умолчанию (без выделени€ пам€ти заранее)
    DynamicArray::DynamicArray()
        : arrayData_(nullptr),
        arrayLength_(0),
        arrayCapacity_(0)
    {
        std::cout << "DynamicArray::DynamicArray()" << std::endl;
    }

    //   онструктор с параметрами
    DynamicArray::DynamicArray(const int* const arrayData, const int arrayLength, const int arrayCapacity)
        : arrayData_(new int[arrayCapacity]),
        arrayLength_(arrayLength),
        arrayCapacity_(arrayCapacity)
    {
        std::cout << "DynamicArray::DynamicArray(const int* const, const int)" << std::endl;

        for (int index = 0; index < arrayLength_; index++)
            arrayData_[index] = arrayData[index];
    }

    //   онструктор копировани€
    DynamicArray::DynamicArray(const DynamicArray& other)
        : arrayData_(new int[other.arrayCapacity_]),
        arrayLength_(other.arrayLength_),
        arrayCapacity_(other.arrayCapacity_)
    {
        std::cout << "DynamicArray::DynamicArray(const DynamicArray&)" << std::endl;

        for (int index = 0; index < arrayLength_; index++)
            arrayData_[index] = other.arrayData_[index];
    }

    //   онструктор перемещени€
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

    //  ƒеструктор
    DynamicArray::~DynamicArray()
    {
        std::cout << "DynamicArray::~DynamicArray()" << std::endl;
        delete[] arrayData_;
    }

    //  ќбычное копирующее присваивание
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

    //  ѕеремещающее присваивание
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

    //  √еттеры размеров
    int DynamicArray::getLength() const
    {
        return arrayLength_;
    }

    int DynamicArray::getCapacity() const
    {
        return arrayCapacity_;
    }

    //  ќператоры квадратных скобок
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

    //. ћетод swap
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

    //метод изменени€ размера массива
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
    // оператор добавлени€ в конец массива число
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
    //добавление всех элементов массива в конец другого маассива
    DynamicArray& DynamicArray::operator+=(const DynamicArray& other) {
        if (arrayCapacity_ < arrayLength_ + other.arrayLength_) {
            resize(arrayLength_ + other.arrayLength_);
        }
        for (int j = 0; j < other.arrayLength_; j++) {
            arrayData_[arrayLength_ + j] = other.arrayData_[j];
        }
        arrayLength_ += other.arrayLength_;
        return *this;
    }
    //проверка равности массивов
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
    //проверка на неравность двух массивов
    bool DynamicArray::operator!=(const DynamicArray& other) const {
        if (arrayLength_ != other.arrayLength_) return true;
        return !(*this == other);
    }

    //опертор псложени€ двух масивов
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
    //удаление по индексу
    bool DynamicArray::removeAt(int index) {
        if (index >= 0 && index < arrayLength_) {
            for (int i = index; i < arrayLength_ - 1; i++) {
                arrayData_[i] = arrayData_[i + 1];
            }
            arrayLength_--;
            return true;
        }
        return false;
    }
    //удаление по значению
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
    //удаление заданного элемента с его дубликатами
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
    //тело дл€ оператора >> чтобы вводить массивы
    std::istream& operator>>(std::istream& inp, DynamicArray& s)
    {
        delete[] s.arrayData_;
        s.arrayData_ = nullptr;
        s.arrayLength_ = 0;
        s.arrayCapacity_ = 0;

        std::cout << "\n¬ведите число элементов , а затем массив чисел, в конце Enter: ";
        int count = 0;
        inp >> count;

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
    //получени€ значени€ итератора
    int& DynamicArray::iterator::operator*()
    {
        return arrayData_[elementIndex_];
    }
    //смещение итератора вперед и возращение нового значени€
    DynamicArray::iterator& DynamicArray::iterator::operator++()
    {
        elementIndex_++;
        return *this;
    }
    //возвращение старого значени€, а после смещение на индекс вперед
    DynamicArray::iterator DynamicArray::iterator::operator++(int) {
        iterator old(*this);
        ++(*this);
        return old;
    }
    //перемещение  итерартора на одну позицию назад.
    DynamicArray::iterator DynamicArray::iterator::operator-(int n) const {

        return iterator(arrayData_, elementIndex_ - n);
    }
    //оператор проверки на неравность итераторов
    bool DynamicArray::iterator::operator!=(const iterator& otherIterator) const {
        return !(*this == otherIterator);
    }
    //оператор проверки равности итераторв массивов
    bool DynamicArray::iterator::operator==(const iterator& other) const {
        if (arrayData_ == other.arrayData_ && elementIndex_ == other.elementIndex_) return true;
        return false;
    }
    //геттер дл€ индексовэлементов
    int DynamicArray::iterator::getelementIndex() const {
        return elementIndex_;
    }


    //добавление перед итератрм
    void DynamicArray::insert(iterator pos, int value)
    {
        int index = pos.getelementIndex();
        insert(index, value);
    }
    //удаление по итератору
    bool DynamicArray::erase(iterator pos) {
        int index = pos.getelementIndex();
        return removeAt(index);
    }

    //begin
    DynamicArray::iterator DynamicArray::begin() {
        return iterator(arrayData_, 0);
    }
    //end
    DynamicArray::iterator DynamicArray::end() {
        return iterator(arrayData_, arrayLength_);
    }
    DynamicArray::const_iterator::const_iterator(const int* arrayData, int elementIndex)
        : arrayData_(arrayData), elementIndex_(elementIndex) {
    }

    // ќператор разыменовани€ возвращает неизмен€емую (const) ссылку
    const int& DynamicArray::const_iterator::operator*() const {
        return arrayData_[elementIndex_];
    }

    DynamicArray::const_iterator& DynamicArray::const_iterator::operator++() {
        elementIndex_++;
        return *this;
    }

    DynamicArray::const_iterator DynamicArray::const_iterator::operator++(int) {
        const_iterator temp = *this;
        elementIndex_++;
        return temp;
    }

    DynamicArray::const_iterator DynamicArray::const_iterator::operator-(int n) const {
        const_iterator temp = *this;
        temp.elementIndex_ -= n;
        return temp;
    }

    bool DynamicArray::const_iterator::operator==(const const_iterator& other) const {
        return (arrayData_ == other.arrayData_) && (elementIndex_ == other.elementIndex_);
    }

    bool DynamicArray::const_iterator::operator!=(const const_iterator& other) const {
        return !(*this == other);
    }

    int DynamicArray::const_iterator::getelementIndex() const {
        return elementIndex_;
    }
    DynamicArray::const_iterator DynamicArray::begin() const
    {
        return const_iterator(arrayData_, 0);
    }
    DynamicArray::const_iterator DynamicArray::end() const
    {
        return const_iterator(arrayData_, arrayLength_);
    }
    DynamicArray::const_iterator DynamicArray::cbegin() const
    {
        return const_iterator(arrayData_, 0);
    }
    DynamicArray::const_iterator DynamicArray::cend() const
    {
        return const_iterator(arrayData_, arrayLength_);
    }
