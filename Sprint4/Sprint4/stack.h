#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"
template <typename T>
class Stack {
private:
    LinkedList<T> data;

public:
    Stack();
    Stack(const Stack<T> &src);
    Stack& operator=(const Stack<T> &src);
    void push(T val);
    T pop();
    bool isEmpty();
    bool contains(T val);
    T peek();
};

template <typename T>
Stack<T>::Stack() {

}

template <typename T>
Stack<T>::Stack(const Stack<T> &src) {
    data = src.data;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T> &src) {
    if(*this != &src) {
        delete data;
        Stack(src);
    }
    return *this;
}

template <typename T>
void Stack<T>::push(T val) {
    data.push(val);
}

template <typename T>
T Stack<T>::pop() {
    T temp = data[data.size()-1];
    data.popBack();
    return temp;
}

template <typename T>
bool Stack<T>::isEmpty() {
    if(data.isEmpty())
        return true;
    else
        return false;
}

template <typename T>
bool Stack<T>::contains(T val) {
    for(int i = 0; i < data.size(); i++) {
        if(data[i] == T)
            return true;
    }
    return false;
}

template <typename T>
T Stack<T>::peek() {
    return data[data.size()-1];
}
#endif // STACK_H
