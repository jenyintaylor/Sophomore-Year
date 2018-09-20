#ifndef VECT_H
#define VECT_H

//inc
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
// Header Part
class Vect {
private:
    int size;
    int capacity;
    T* data;


public:
    Vect(const Vect<T>&src);
    Vect(int initCap = 10, int initSize = 0);
    Vect& operator=(const Vect<T> &src);
    ~Vect();

    T& operator[](int location);
    T& elementAt(int location);
    void setElementAt(int location, T obj);

    void push(const T obj);
    void pushAt(T obj, int location);
    void pop();
    void popAt(int location);
    T& first();
    T& last();
    int tot();
    int cap();

};



template <typename T>
Vect<T>::Vect(const Vect<T>&src) {
}

template <typename T>
Vect<T>::Vect(int initCap, int initSize)
    :capacity(initCap), size(initSize) {
    data = new T[capacity];
}


template <typename T>
Vect<T>::~Vect() {}

template <typename T>
Vect<T>& Vect<T>::operator=(const Vect<T> &src) {//https://en.cppreference.com/w/cpp/language/operators
                                      // I got help here
    if(*this != &src) { //Makes sure these aren't the same
        delete[] data;
        size = src.tot();
        capacity = src.cap();
        data = nullptr;
        data = new T[capacity];
        for(int i = 0; i < size; i++) {
            data[i] = src[i];
        }
    }
    return *this;
}

template <typename T>
T& Vect<T>::operator[](int location) {
    if(location < 0 || location > size)
        throw out_of_range("Index is out of range");
    return this->data[location];
}


template <typename T>
T& Vect<T>::elementAt(int location) {
    return this->data[location];
}

template <typename T>
void Vect<T>::setElementAt(int location, T obj) {

}

template <typename T>
void Vect<T>::push(const T obj) {
    if(size == capacity) {
        T* temp = new T[capacity*2];
        for(int i = 0; i < capacity; i++) {
            temp[i] = data[i];
        }
        capacity *= 2;
        delete[] data;
        data = temp;
        delete[] temp;
        data[size] = obj;
        size++;
    }
    else {
        data[size] = obj;
        size++;
    }
}


template <typename T>
void Vect<T>::pushAt(T obj, int location) {

}


template <typename T>
void Vect<T>::pop() {
    delete data[size-1];
    size = size -1;
}

template <typename T>
void Vect<T>::popAt(int location) {

}

template <typename T>
T& Vect<T>::first() {
    return this->data[0];
}

template <typename T>
T& Vect<T>::last() {
    return this->data[size-1];
}

template <typename T>
int Vect<T>::tot() {
    return size;
}

template <typename T>
int Vect<T>::cap() {
    return capacity;
}



#endif // VECT_H
