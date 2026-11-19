#include "Temple_array.h"
#include <iostream>
#include <assert.h>



    template <typename T>
    DynamicArray<T>::DynamicArray()
        : arrayData_(nullptr),
        arrayLength_(0),
        arrayCapacity_(0)
    {
        std::cout << "DynamicArray::DynamicArray()" << std::endl;
    }

    // Конструктор с параметрами
    template <typename T>
    DynamicArray<T>::DynamicArray(const T* const arrayData, const int arrayLength, const int arrayCapacity)
        : arrayData_(new T[arrayCapacity]),
        arrayLength_(arrayLength),
        arrayCapacity_(arrayCapacity)
    {
        std::cout << "DynamicArray::DynamicArray(const T* const, const int, const int)" << std::endl;

        for (int index = 0; index < arrayLength_; index++)
            arrayData_[index] = arrayData[index];
    }

    // Конструктор копирования
    template <typename T>
    DynamicArray<T>::DynamicArray(const DynamicArray& other)
        : arrayData_(new T[other.arrayCapacity_]),
        arrayLength_(other.arrayLength_),
        arrayCapacity_(other.arrayCapacity_)
    {
        std::cout << "DynamicArray::DynamicArray(const DynamicArray&)" << std::endl;

        for (int index = 0; index < arrayLength_; index++)
            arrayData_[index] = other.arrayData_[index];
    }

    // Конструктор перемещения
    template <typename T>
    DynamicArray<T>::DynamicArray(DynamicArray&& other) noexcept
        : arrayData_(other.arrayData_),
        arrayLength_(other.arrayLength_),
        arrayCapacity_(other.arrayCapacity_)
    {
        std::cout << "DynamicArray::DynamicArray(DynamicArray&&)" << std::endl;

        other.arrayLength_ = 0;
        other.arrayCapacity_ = 0;
        other.arrayData_ = nullptr;
    }

    // Деструктор
    template <typename T>
    DynamicArray<T>::~DynamicArray()
    {
        std::cout << "DynamicArray::~DynamicArray()" << std::endl;
        delete[] arrayData_;
    }

    // Обычное копирующее присваивание
    template <typename T>
    DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
    {
        std::cout << "DynamicArray::operator=(const DynamicArray&)" << std::endl;

        if (this != &other)
        {
            delete[] arrayData_;

            arrayLength_ = other.arrayLength_;
            arrayCapacity_ = other.arrayCapacity_;
            arrayData_ = new T[arrayCapacity_];

            for (int index = 0; index < arrayLength_; index++)
                arrayData_[index] = other.arrayData_[index];
        }

        return *this;
    }

    // Перемещающее присваивание
    template <typename T>
    DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray&& other) noexcept
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

    // Геттеры размеров
    template <typename T>
    int DynamicArray<T>::getLength() const
    {
        return arrayLength_;
    }

    template <typename T>
    int DynamicArray<T>::getCapacity() const
    {
        return arrayCapacity_;
    }

    // Операторы квадратных скобок
    template <typename T>
    T& DynamicArray<T>::operator[](const int index)
    {
        assert((index >= 0 && index < arrayLength_) && "Index is out of range.");
        return arrayData_[index];
    }

    template <typename T>
    const T& DynamicArray<T>::operator[](const int index) const
    {
        assert((index >= 0 && index < arrayLength_) && "Index is out of range.");
        return arrayData_[index];
    }

    // Метод swap
    template <typename T>
    void DynamicArray<T>::swap(DynamicArray& other)
    {
        int length = arrayLength_;
        arrayLength_ = other.arrayLength_;
        other.arrayLength_ = length;

        int capacity = arrayCapacity_;
        arrayCapacity_ = other.arrayCapacity_;
        other.arrayCapacity_ = capacity;

        T* data = arrayData_;
        arrayData_ = other.arrayData_;
        other.arrayData_ = data;
    }

    // Метод изменения размера массива
    template <typename T>
    void DynamicArray<T>::resize(int newCapacity)
    {
        T* newData = new T[newCapacity];
        for (int index = 0; index < arrayLength_; index++)
        {
            newData[index] = arrayData_[index];
        }
        delete[] arrayData_;
        arrayData_ = newData;
        arrayCapacity_ = newCapacity;
    }

    // Оператор добавления в конец массива элемента T
    template <typename T>
    DynamicArray<T>& DynamicArray<T>::operator+=(const T& value) {
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

    // Добавление всех элементов массива в конец другого массива
    template <typename T>
    DynamicArray<T>& DynamicArray<T>::operator+=(const DynamicArray& other) {
        if (arrayCapacity_ < arrayLength_ + other.arrayLength_) {
            resize(arrayLength_ + other.arrayLength_);
        }
        for (int j = 0; j < other.arrayLength_; j++) {
            arrayData_[arrayLength_ + j] = other.arrayData_[j];
        }
        arrayLength_ += other.arrayLength_;
        return *this;
    }

    // Проверка равенства массивов
    template <typename T>
    bool DynamicArray<T>::operator==(const DynamicArray& other) const {
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

    // Проверка на неравенность двух массивов
    template <typename T>
    bool DynamicArray<T>::operator!=(const DynamicArray& other) const {
        if (arrayLength_ != other.arrayLength_) return true;
        return !(*this == other);
    }

    // Оператор сложения двух массивов
    template <typename T>
    DynamicArray<T> DynamicArray<T>::operator+(const DynamicArray& other) const {
        DynamicArray newArray(*this);
        newArray += other;
        return newArray;
    }

    // Оператор добавления в конец элемента T
    template <typename T>
    DynamicArray<T> DynamicArray<T>::operator+(const T& newarrayData) const
    {
        DynamicArray newArray(*this);
        newArray += newarrayData;
        return newArray;
    }

    // Метод поиска элемента по значению (возвращает индекс или -1)
    template <typename T>
    int DynamicArray<T>::find(const T& value) const
    {
        for (int i = 0; i < arrayLength_; i++) {
                if (arrayData_[i] == value) return i;
        }
        return -1;
    }
    // Поиск максимального элемента в массиве
    template<typename T>
    T DynamicArray<T>::findMax() const {
        if (arrayLength_) {
            T max = arrayData_[0];
            for (int i = 1; i < arrayLength_; i++) {
                if (arrayData_[i] > max) max = arrayData_[i];
            }
            return max;
        }
        else return T(); // Возвращает значение по умолчанию для типа T
    }
    // Поиск минимального элемента в массиве
    template<typename T>
    T DynamicArray<T>::findMin() const {
        if (arrayLength_) {
            T min = arrayData_[0];
            for (int i = 1; i < arrayLength_; i++) {
                if (arrayData_[i] < min) min = arrayData_[i];
            }
            return min;
        }
        else return T(); // Возвращает значение по умолчанию для типа T
    }
    // Сортировка массива по возрастанию
    template<typename T>
    void DynamicArray<T>::sort() {
        if (arrayLength_) {
            T a = T();
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
    // Вставка элемента по индексу
    template<typename T>
    bool DynamicArray<T>::insert(int index, const T& value) {
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
    // Удаление по индексу
    template<typename T>
    bool DynamicArray<T>::removeAt(int index) {
        if (index >= 0 && index < arrayLength_) {
            for (int i = index; i < arrayLength_ - 1; i++) {
                arrayData_[i] = arrayData_[i + 1];
            }
            arrayLength_--;
            return true;
        }
        return false;
    }
    // Удаление по значению
    template<typename T>
    bool DynamicArray<T>::removeByValue(const T& value) {
        if (arrayLength_) {
            for (int i = 0; i < arrayLength_; i++) {
                if (arrayData_[i] == value) {
                    removeAt(i);
                    return true;
                }
            }
            return false;
        }
        return false;
    }
    // Удаление заданного элемента с его дубликатами
    template<typename T>
    bool DynamicArray<T>::removeAll(const T& value) {
        if (arrayLength_) {
            bool wasDeleted = false;
            for (int i = 0; i < arrayLength_; i++) {
                if (arrayData_[i] == value) {
                    removeAt(i);
                    i--;
                    wasDeleted = true;
                }
            }
            return wasDeleted;
        }
        return false;
    }
    // Потоковый вывод
    template<typename U>
    std::ostream& operator<<(std::ostream& out, const DynamicArray<U>& s)
    {
        for (int i = 0; i < s.arrayLength_; i++) {
            out << s.arrayData_[i] << " ";
        }
        return out;
    }
    // Тело для оператора >> чтобы вводить массивы
    template<typename U>
    std::istream& operator>>(std::istream& inp, DynamicArray<U>& s)
    {
        delete[] s.arrayData_;
        s.arrayData_ = nullptr;
        s.arrayLength_ = 0;
        s.arrayCapacity_ = 0;
        std::cout << "\nВведите число элементов ,а затем массив массив , в конце Enter: ";
        int count = 0;
        inp >> count;
        s.arrayLength_ = 0;
        for (int i = 0; i < count; i++) {
            U value = U();
            inp >> value;
            s += value;
        }
        return inp;
    }
    // Добавление перед итератором
    template<typename T>
    void DynamicArray<T>::insert(iterator pos, const T& value)
    {
        int index = pos.getelementIndex();
        insert(index, value);
    }
    // Удаление по итератору
    template<typename T>
    bool DynamicArray<T>::erase(iterator pos) {
        int index = pos.getelementIndex();
        return removeAt(index);
    }
    // begin
    template <typename T>
    typename DynamicArray<T>::iterator DynamicArray<T>::begin() {
        return iterator(arrayData_, 0);
    }

    // end
    template <typename T>
    typename DynamicArray<T>::iterator DynamicArray<T>::end() {
        return iterator(arrayData_, arrayLength_);
    }

    // Константные методы begin/end/cbegin/cend
    template <typename T>
    typename DynamicArray<T>::const_iterator DynamicArray<T>::begin() const {
        return const_iterator(arrayData_, 0);
    }

    template <typename T>
    typename DynamicArray<T>::const_iterator DynamicArray<T>::end() const {
        return const_iterator(arrayData_, arrayLength_);
    }

    template <typename T>
    typename DynamicArray<T>::const_iterator DynamicArray<T>::cbegin() const {
        return const_iterator(arrayData_, 0);
    }

    template <typename T>
    typename DynamicArray<T>::const_iterator DynamicArray<T>::cend() const {
        return const_iterator(arrayData_, arrayLength_);
    }

    template <typename T>
    DynamicArray<T>::iterator::iterator(T* arrayData, int elementIn)
        : arrayData_(arrayData), elementIndex_(elementIn) {
    }

    // Получение значения итератора
    template <typename T>
    T& DynamicArray<T>::iterator::operator*() {
        return arrayData_[elementIndex_];
    }

    // Смещение итератора вперед и возвращение нового значения
    template <typename T>
    typename DynamicArray<T>::iterator& DynamicArray<T>::iterator::operator++() {
        elementIndex_++;
        return *this;
    }

    // Возвращение старого значения, а после смещение на индекс вперед
    template <typename T>
    typename DynamicArray<T>::iterator DynamicArray<T>::iterator::operator++(int) {
        iterator old(*this);
        ++(*this);
        return old;
    }

    // Перемещение итератора назад
    template <typename T>
    typename DynamicArray<T>::iterator DynamicArray<T>::iterator::operator-(int n) const {
        return iterator(arrayData_, elementIndex_ - n);
    }

    // Оператор проверки на неравенность итераторов
    template <typename T>
    bool DynamicArray<T>::iterator::operator!=(const iterator& otherIterator) const {
        return !(*this == otherIterator);
    }

    // Оператор проверки равенства итераторов массивов
    template <typename T>
    bool DynamicArray<T>::iterator::operator==(const iterator& other) const {
        return (arrayData_ == other.arrayData_ && elementIndex_ == other.elementIndex_);
    }

    // Геттер для индексов элементов
    template <typename T>
    int DynamicArray<T>::iterator::getelementIndex() const {
        return elementIndex_;
    }

    template <typename T>
    DynamicArray<T>::const_iterator::const_iterator(const T* arrayData, int elementIndex)
        : arrayData_(arrayData), elementIndex_(elementIndex) {
    }

    // Оператор разыменования возвращает неизменяемую (const) ссылку
    template <typename T>
    const T& DynamicArray<T>::const_iterator::operator*() const {
        return arrayData_[elementIndex_];
    }

    template <typename T>
    typename DynamicArray<T>::const_iterator& DynamicArray<T>::const_iterator::operator++() {
        elementIndex_++;
        return *this;
    }

    template <typename T>
    typename DynamicArray<T>::const_iterator DynamicArray<T>::const_iterator::operator++(int) {
        const_iterator temp = *this;
        elementIndex_++;
        return temp;
    }

    template <typename T>
    typename DynamicArray<T>::const_iterator DynamicArray<T>::const_iterator::operator-(int n) const {
        const_iterator temp = *this;
        temp.elementIndex_ -= n;
        return temp;
    }

    template <typename T>
    bool DynamicArray<T>::const_iterator::operator==(const const_iterator& other) const {
        return (arrayData_ == other.arrayData_) && (elementIndex_ == other.elementIndex_);
    }

    template <typename T>
    bool DynamicArray<T>::const_iterator::operator!=(const const_iterator& other) const {
        return !(*this == other);
    }

    // Геттер для индексов константного итератора
    template <typename T>
    int DynamicArray<T>::const_iterator::getelementIndex() const {
        return elementIndex_;
    }
