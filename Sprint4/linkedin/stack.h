#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"
template <typename T>
class Stack {
private:
    LinkedList<T> data;
    int length;

public:
    Stack();
    Stack(const Stack<T> &src);
    Stack& operator=(const Stack<T> &src);
    void push(T val);
    T pop();
    bool isEmpty();
    bool contains(T val);
    T peek();
    int size();
};

template <typename T>
Stack<T>::Stack()
    :length(0) {

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
    length++;
}

template <typename T>
T Stack<T>::pop() {
    T temp = data[data.size()-1];
    data.popBack();
    length--;
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
        if(data[i] == val)
            return true;
    }
    return false;
}

template <typename T>
T Stack<T>::peek() {
    return data[data.size()-1];
}

template <typename T>
int Stack<T>::size() {
    return length;
}
#endif // STACK_H
