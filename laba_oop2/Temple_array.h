#pragma once
#include <assert.h>
#include <iostream>



    template <class T>
    class DynamicArray {
    public:

        class iterator;
        class const_iterator;

        DynamicArray();

        DynamicArray(const T* const arrayData, const int arrayLength, const int arrayCapacity);
        DynamicArray(const DynamicArray& other);
        DynamicArray(DynamicArray&& other) noexcept;
        ~DynamicArray();

        DynamicArray& operator=(const DynamicArray& other);
        DynamicArray& operator=(DynamicArray&& other) noexcept;
        DynamicArray& operator+=(const T& value);
        DynamicArray operator+(const T& newarrayData) const;
        DynamicArray& operator+=(const DynamicArray& other);
        DynamicArray operator+(const DynamicArray& other) const;

        int getLength() const;
        int getCapacity() const;
        T& operator[](const int index);
        const T& operator[](const int index) const;
        int find(const T& value) const;
        T findMax() const;
        T findMin() const;

        void swap(DynamicArray& other);
        void sort();

        bool insert(int index, const T& value);
        bool removeAt(int index);
        bool removeByValue(const T& value);
        bool removeAll(const T& value);
        bool operator==(const DynamicArray& other) const;
        bool operator!=(const DynamicArray& other) const;


        template <typename U>
        friend std::ostream& operator<<(std::ostream& out, const DynamicArray<U>& s);
        template <typename U>
        friend std::istream& operator>>(std::istream& inp, DynamicArray<U>& s);

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        void insert(iterator pos, const T& value);
        bool erase(iterator pos);

    private:

        T* arrayData_ = nullptr;
        int arrayLength_ = 0;
        int arrayCapacity_ = 0;

        void resize(int newCapacity);
    };





    template <typename T>
    class DynamicArray<T>::iterator
    {
    public:
        iterator() = default;
        iterator(T* arrayData, int elementIndex);

        bool operator!=(const iterator& otherIterator) const;
        bool operator==(const iterator& other) const;
        iterator& operator++();
        iterator operator++(int);
        iterator operator-(int n) const;
        T& operator*();
        int getelementIndex() const;

    private:
        T* arrayData_ = nullptr;
        int elementIndex_ = 0;
    };

    template <typename T>
    class DynamicArray<T>::const_iterator {
    public:
        const_iterator() = default;
        const_iterator(const T* arrayData, int elementIndex);

        bool operator!=(const const_iterator& otherIterator) const;
        bool operator==(const const_iterator& other) const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator operator-(int n) const;
        const T& operator*() const;
        int getelementIndex() const;

    private:
        const T* arrayData_ = nullptr;
        int elementIndex_ = 0;
    };
#include "tempel_array.inl"
