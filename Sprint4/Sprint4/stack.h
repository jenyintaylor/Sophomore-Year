#ifndef STACK_H
#define STACK_H
template <typename T>
class Node {
private:
    T data;
    Node* next;

    Node(T val, Node* n)
        :data(val), next(n) {}
};
#endif // STACK_H
