#include <assert.h>
#include <iostream>
#include "DynamicArray.h"


    //  онструктор по умолчанию (без выделени€ пам€ти заранее)
    IntDynamicArray::IntDynamicArray()
        : arrayData_(nullptr),
        arrayLength_(0),
        arrayCapacity_(0)
    {
        std::cout << "DynamicArray::DynamicArray()" << std::endl;
    }

    //   онструктор с параметрами
    IntDynamicArray::IntDynamicArray(const int* const arrayData, const int arrayLength, const int arrayCapacity)
        : arrayData_(new int[arrayCapacity]),
        arrayLength_(arrayLength),
        arrayCapacity_(arrayCapacity)
    {
        std::cout << "DynamicArray::DynamicArray(const int* const, const int)" << std::endl;

        for (int index = 0; index < arrayLength_; index++)
            arrayData_[index] = arrayData[index];
    }

    //   онструктор копировани€
    IntDynamicArray::IntDynamicArray(const IntDynamicArray& other)
        : arrayData_(new int[other.arrayCapacity_]),
        arrayLength_(other.arrayLength_),
        arrayCapacity_(other.arrayCapacity_)
    {
        std::cout << "DynamicArray::DynamicArray(const DynamicArray&)" << std::endl;

        for (int index = 0; index < arrayLength_; index++)
            arrayData_[index] = other.arrayData_[index];
    }

    //   онструктор перемещени€
    IntDynamicArray::IntDynamicArray(IntDynamicArray&& other)
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
    IntDynamicArray::~IntDynamicArray()
    {
        std::cout << "DynamicArray::~DynamicArray()" << std::endl;
        delete[] arrayData_;
    }

    //  ќбычное копирующее присваивание
    IntDynamicArray& IntDynamicArray::operator=(const IntDynamicArray& other)
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
    IntDynamicArray& IntDynamicArray::operator=(IntDynamicArray&& other)
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
    int IntDynamicArray::getLength() const
    {
        return arrayLength_;
    }

    int IntDynamicArray::getCapacity() const
    {
        return arrayCapacity_;
    }

    //  ќператоры квадратных скобок
    int& IntDynamicArray::operator[](const int index)
    {
        assert((index >= 0 && index < arrayLength_) && "Index is out of range.");
        return arrayData_[index];
    }

    const int& IntDynamicArray::operator[](const int index) const
    {
        assert((index >= 0 && index < arrayLength_) && "Index is out of range.");
        return arrayData_[index];
    }

    //. ћетод swap
    void IntDynamicArray::swap(IntDynamicArray& other)
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
    void IntDynamicArray::resize(int newCapacity)
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
    IntDynamicArray& IntDynamicArray::operator+=(const int value) {
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
    IntDynamicArray& IntDynamicArray::operator+=(const IntDynamicArray& other) {
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
    bool IntDynamicArray::operator==(const IntDynamicArray& other) const {
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
    bool IntDynamicArray::operator!=(const IntDynamicArray& other) const {
        if (arrayLength_ != other.arrayLength_) return true;
        return !(*this == other);
    }

    //опертор псложени€ двух масивов
    IntDynamicArray IntDynamicArray::operator+(const  IntDynamicArray& other) const {
        IntDynamicArray newArray(*this);
        newArray += other;
        return newArray;
    }
    //оператор добавлени в конец числа
    IntDynamicArray IntDynamicArray::operator+(const int newarrayData) const
    {
        IntDynamicArray newArray(*this);
        newArray += newarrayData;
        return newArray;
    }
    // метод поиска элемента по значению (возвращает индекс или -1)
    int IntDynamicArray::find(const int value) const
    {
        for (int i = 0; i < arrayLength_; i++) {
            if (arrayData_[i] == value) return i;
        }
        return -1;
    }

    // поиск максимального элемента в массиве
    int IntDynamicArray::findMax() const {
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
    int IntDynamicArray::findMin() const {
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
    void IntDynamicArray::sort() {
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
    bool IntDynamicArray::insert(int index, int value) {
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
    bool IntDynamicArray::removeAt(int index) {
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
    bool IntDynamicArray::removeByValue(int value) {
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
    bool IntDynamicArray::removeAll(int value) {
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
    std::ostream& operator<<(std::ostream& out, const IntDynamicArray& s)
    {
        for (int i = 0; i < s.arrayLength_; i++) {
            out << s.arrayData_[i] << " ";
        }
        return out;
    }
    //тело дл€ оператора >> чтобы вводить массивы
    std::istream& operator>>(std::istream& inp, IntDynamicArray& s)
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
    IntDynamicArray::iterator::iterator(int* arrayData, int elementIn) : arrayData_(arrayData), elementIndex_(elementIn)
    {
    }
    //получени€ значени€ итератора
    int& IntDynamicArray::iterator::operator*()
    {
        return arrayData_[elementIndex_];
    }
    //смещение итератора вперед и возращение нового значени€
    IntDynamicArray::iterator& IntDynamicArray::iterator::operator++()
    {
        elementIndex_++;
        return *this;
    }
    //возвращение старого значени€, а после смещение на индекс вперед
    IntDynamicArray::iterator IntDynamicArray::iterator::operator++(int) {
        iterator old(*this);
        ++(*this);
        return old;
    }
    //перемещение  итерартора на одну позицию назад.
    IntDynamicArray::iterator IntDynamicArray::iterator::operator-(int n) const {

        return iterator(arrayData_, elementIndex_ - n);
    }
    //оператор проверки на неравность итераторов
    bool IntDynamicArray::iterator::operator!=(const iterator& otherIterator) const {
        return !(*this == otherIterator);
    }
    //оператор проверки равности итераторв массивов
    bool IntDynamicArray::iterator::operator==(const iterator& other) const {
        if (arrayData_ == other.arrayData_ && elementIndex_ == other.elementIndex_) return true;
        return false;
    }
    //геттер дл€ индексовэлементов
    int IntDynamicArray::iterator::getelementIndex() const {
        return elementIndex_;
    }


    //добавление перед итератрм
    void IntDynamicArray::insert(iterator pos, int value)
    {
        int index = pos.getelementIndex();
        insert(index, value);
    }
    //удаление по итератору
    bool IntDynamicArray::erase(iterator pos) {
        int index = pos.getelementIndex();
        return removeAt(index);
    }

    //begin
    IntDynamicArray::iterator IntDynamicArray::begin() {
        return iterator(arrayData_, 0);
    }
    //end
    IntDynamicArray::iterator IntDynamicArray::end() {
        return iterator(arrayData_, arrayLength_);
    }
    IntDynamicArray::const_iterator::const_iterator(const int* arrayData, int elementIndex)
        : arrayData_(arrayData), elementIndex_(elementIndex) {
    }

    // ќператор разыменовани€ возвращает неизмен€емую (const) ссылку
    const int& IntDynamicArray::const_iterator::operator*() const {
        return arrayData_[elementIndex_];
    }

    IntDynamicArray::const_iterator& IntDynamicArray::const_iterator::operator++() {
        elementIndex_++;
        return *this;
    }

    IntDynamicArray::const_iterator IntDynamicArray::const_iterator::operator++(int) {
        const_iterator temp = *this;
        elementIndex_++;
        return temp;
    }

    IntDynamicArray::const_iterator IntDynamicArray::const_iterator::operator-(int n) const {
        const_iterator temp = *this;
        temp.elementIndex_ -= n;
        return temp;
    }

    bool IntDynamicArray::const_iterator::operator==(const const_iterator& other) const {
        return (arrayData_ == other.arrayData_) && (elementIndex_ == other.elementIndex_);
    }

    bool IntDynamicArray::const_iterator::operator!=(const const_iterator& other) const {
        return !(*this == other);
    }

    int IntDynamicArray::const_iterator::getelementIndex() const {
        return elementIndex_;
    }
    IntDynamicArray::const_iterator IntDynamicArray::begin() const
    {
        return const_iterator(arrayData_, 0);
    }
    IntDynamicArray::const_iterator IntDynamicArray::end() const
    {
        return const_iterator(arrayData_, arrayLength_);
    }
    IntDynamicArray::const_iterator IntDynamicArray::cbegin() const
    {
        return const_iterator(arrayData_, 0);
    }
    IntDynamicArray::const_iterator IntDynamicArray::cend() const
    {
        return const_iterator(arrayData_, arrayLength_);
    }
