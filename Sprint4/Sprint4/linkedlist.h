#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

template <typename T>
class ListNode {
     friend class LinkedList ;
private:
     T data;
     ListNode *next, *prev;
};

template <typename T>
class LinkedList {
private:
    int length;
    ListNode *head, *tail, *c_iter;
public:
    LinkedList(); //figure it out
    ~LinkedList();
    void clear();
    T search(T val);
    void printForward();
    void printBackward();
    void push(T val);
    void pop();
    void insert(T val, int loc);
    int size();
};

template <typename T>
ListNode::ListNode(T val)
    :data(val), next(nullptr), prev(nullptr) {

}

template <typename T>
LinkedList<T> LinkedList::operator=(const LinkedList& src) {
    if(head != nullptr) {
        clear();
    }
}


#endif // LINKEDLIST_H
