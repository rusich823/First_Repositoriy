#pragma once

class DynamicArray
{
public:

    class iterator;


    DynamicArray();

    DynamicArray(const int* const arrayData, const int arrayLength, const int arrayCapacity);
    DynamicArray(const DynamicArray& other);
    DynamicArray(DynamicArray&& other);
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray& operator=(DynamicArray&& other);
    DynamicArray& operator+=(const int value);
    DynamicArray operator+(const int newarrayData) const;

    int getLength() const;
    int getCapacity() const;
    int find(const int value) const;
    int findMax() const;
    int findMin() const;


    bool insert(int index, int value);

    int& operator[](const int index);
    const int& operator[](const int index) const;
    


    void swap(DynamicArray& other);
    void sort();

    iterator begin();
    iterator end();

private:

    int* arrayData_ = nullptr;
    int arrayLength_ = 0;
    int arrayCapacity_ = 0;

    void resize(int newCapacity);
};

class DynamicArray::iterator
{
public:

    iterator() = default;
    iterator(int* arrayData, int elementIndex);

    bool operator!=(const iterator& otherIterator);
    iterator& operator++();
    iterator operator++(int);
    int& operator*();

private:

    int* arrayData_ = nullptr;
    int elementIndex_ = 0;
};
