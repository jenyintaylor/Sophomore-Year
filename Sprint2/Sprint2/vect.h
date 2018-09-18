#ifndef VECT_H
#define VECT_H

//inc

template <typename T>


// Header Part
class Vect {
private:
    int size;
    int capacity;
    T* data;


public:
    Vect(const Vect<T>&);
    Vect(int initSize = 10);
    Vect& operator=(const Vect cT);
    ~Vect();

    T& operator[](int location);
    T& elementAt(int location);
    void setElementAt(int location, T);

    void push(T);
    void pushAt(T, int location);
    void pop();
    void popAt(int location);
    T& first();
    T& last();
};


template <typename T>
Vect<T>::Vect(const Vect<T> &) {

}

template <typename T>
Vect<T>::Vect(int initSize = 10) {
    capacity = initSize;
}

template <typename T>
T& Vect<T>::operator=(const Vect cT) {

}

template <typename T>
T& Vect<T>::operator[](int location) {

}

template <typename T>
Vect<T>::~Vect() {}


template <typename T>
T& Vect<T>::elementAt(int location) {

}

template <typename T>
void Vect<T>::push(T) {

}


template <typename T>
void Vect<T>::pushAt(T, int location) {

}


template <typename T>
void Vect<T>::pop() {

}

template <typename T>
void Vect<T>::popAt(int location) {

}

template <typename T>
T& Vect<T>::first() {
    return T[1];
}

template <typename T>
T& Vect<T>::last() {
    return T[size-1];
}


#endif // VECT_H
