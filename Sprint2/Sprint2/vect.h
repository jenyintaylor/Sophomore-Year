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
};


Vect<T>::Vect(const Vect<T> &) {

}
Vect<T>::Vect(int initSize = 10) {
    capacity = initSize;
}
T& Vect<T>::operator=(const Vect cT) {

}


Vect<T>::~Vect() {}


T& Vect<T>::elementAt(int location) {

}

void Vect<T>::push(typename T) {

}

void Vect<T>::pushAt(typename T, int location) {

}
void Vect<T>::pop() {

}
void Vect<T>::popAt(int location) {

}


#endif // VECT_H
