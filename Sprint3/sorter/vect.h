//Jeffrey Taylor, 47400760, Sprint3
    //Contains the evolution of the Jefe-Vector
    //my resize function is no longer trash


//def
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
    int capacity;
    int size;
    T* data;


public:
    Vect(int initCap = 10, int initSize = 0);
    Vect(const Vect<T>&src);
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
    void resize(int r);
    void lazySort();

};


//the working bits

//default with the default values for inital size and cap
template <typename T>
Vect<T>::Vect(int initCap, int initSize)
    :capacity(initCap), size(initSize) {
    data = new T[capacity];
}

//copy constructor
template <typename T>
Vect<T>::Vect(const Vect<T>&src) {
    data = src.data;
    size = src.size;
    capacity = src.capacity;
}


template <typename T>
Vect<T>::~Vect() {}

template <typename T>
Vect<T>& Vect<T>::operator=(const Vect<T> &src) {//https://en.cppreference.com/w/cpp/language/operators
                                      // I got help here, and then we went over the exact thing in class
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
    if(location < 0 || location > size)
        throw out_of_range("Index is out of range");
    return this->data[location];
}

template <typename T>
void Vect<T>::setElementAt(int location, T obj) {
    data[location] = obj;
}

template <typename T>
void Vect<T>::push(const T obj) {
    if(size >= capacity) {
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
    if(size == capacity) {
        T* temp = new T[capacity*2];
        for(int i = 0; i < location; i++) {
            temp[i] = data[i];
        }
        temp[location] = obj;
        capacity++;
        size++;
        for(int i = location+1; i < capacity; i++) {
            temp[i] = data[i-1];
        }
        capacity *= 2;
        delete[] data;
        data = temp;
        delete[] temp;

    }
    else {
        T* temp = new T[capacity];
        for(int i = 0; i < location; i++) {
            temp[i] = data[i];
        }
        temp[location] = obj;
        capacity++;
        size++;
        for(int i = location+1; i < size; i++) {
            temp[i] = data[i-1];
        }
        delete[] data;
        data = temp;
        delete[] temp;
    }
}


template <typename T>
void Vect<T>::pop() {
    size = size-1;
    T* temp = new T[capacity];
    for(int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
    delete[] temp;
}

template <typename T>
void Vect<T>::popAt(int location) {
    if(location != size-1) {
        T* temp = new T[capacity];
        for(int i = 0; i < size; i++) {
            if(i != location) {
                temp[i] = data[i];
            } else { continue; }
        }
        size--;
        delete[] data;
        data = temp;
        delete[] temp;

    } else { pop(); }
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

template <typename T>
void Vect<T>::resize(int r) {
    if(r < size)
        throw length_error("You are attempting to shrink the vector without deleting elements");
    else {
        capacity = r;
        T* temp = new T[capacity];
        for(int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        delete[] temp;

    }
}

template <typename T>
void lazySort() {

} //Not using this here, but I know for a fact that being able to sort will come in handy in the future and I'm lazy
  //This will probably contain the finished result


#endif // VECT_H
