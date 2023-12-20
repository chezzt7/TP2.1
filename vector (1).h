#pragma once

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

template<typename T>
class MyVector
{
public:
    MyVector(int size = 0);
    ~MyVector();

    T& at(int index) const;
    T& front() const;
    T& back() const;
    T& operator[](int index);

    bool empty() const;
    int size() const;
    int capacity() const;

    void clear();
    void insert(int index, const T& d);
    void remove(int index);
    void push_back(const T& d);
    void pop_back();

private:
    T* data;
    int length;
    int current_pos;
};




template<typename T>
MyVector<T>::MyVector(int size) : length(size), current_pos(0)
{
    if (length != 0) {
        delete[] data;
        data = nullptr;
    }
    data = new T[length];

}

template<typename T>
MyVector<T>::~MyVector()
{
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
}

template<typename T>
T& MyVector<T>::at(int index) const
{
    assert(index >= 0 && index < current_pos);
    return data[index];
}

template<typename T>
T& MyVector<T>::front() const
{
    assert(current_pos > 0);
    return data[0];
}

template<typename T>
T& MyVector<T>::back() const
{
    assert(current_pos > 0);
    return data[current_pos - 1];
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
    assert(index > 0 || index < current_pos);
    return data[index];
}

template<typename T>
bool MyVector<T>::empty() const
{
    return current_pos == 0 ? true : false;
}

template<typename T>
int MyVector<T>::size() const
{
    return current_pos;
}

template<typename T>
int MyVector<T>::capacity() const
{
    return length;
}

template<typename T>
void MyVector<T>::clear()
{
    current_pos = 0;
}

template<typename T>
void MyVector<T>::insert(int index, const T& d)
{
    assert(index > 0 || index < current_pos);
    if (current_pos == length) {
        T* temp = new T[length + 10];
        //memset(temp, 0, (length + 10) * sizeof(T));
        memcpy(temp, data, length * sizeof(T));
        length += 10;
        delete[] data;
        data = nullptr;
        data = temp;
    }

    memcpy(data + index + 1, data + index, (length - index) * sizeof(T));
    data[index] = d;

    current_pos++;
}

template<typename T>
void MyVector<T>::remove(int index)
{
    assert(index > 0 || index < current_pos);

    memcpy(data + index, data + index + 1, (current_pos - index) * sizeof(T));
    current_pos--;
}

template<typename T>
void MyVector<T>::push_back(const T& d)
{
    if (current_pos == length) {
        T* temp = new T[length + 10];
        //memset(temp, 0, (length + 10) * sizeof(T));
        memcpy(temp, data, length * sizeof(T));
        length += 10;
        delete[] data;
        data = nullptr;
        data = temp;
    }

    data[current_pos] = d;

    current_pos++;
}

template<typename T>
void MyVector<T>::pop_back()
{
    assert(current_pos > 0);
    current_pos--;
}
