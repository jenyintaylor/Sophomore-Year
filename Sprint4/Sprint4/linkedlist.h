#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class ListNode {
    template <class U>
    friend class LinkedList ;
private:
    T data;
    ListNode<T> *next, *prev;
};
//-----------------------------------------------------------------Node Header ends

template <typename T>
ListNode::ListNode(T val)
    :data(val), next(nullptr), prev(nullptr) {}

//-----------------------------------------------------------------Node implementation ends
template <typename T>
class LinkedList {
private:
    int length;
    ListNode *head, *tail, *c_iter;

    void printBackward(ListNode* var) {
        if(var == nullptr)
            return; //At the end of the list, this will be true, then it does the thing that's two lines below
        printBackward(var->next); //This will just keep going recursively
        cout << curr->data << endl;
        //The last one will do this first, then the line of returns just keeps printing out lines in reverse order
        return;
    }
public:
    LinkedList();
    LinkedList(const LinkedList<T> &src);
    LinkedList& operator=(const LinkedList<T> &src);

    void push(T val);
    void popFront();
    void popBack();
    void pushAt(T val, int loc);
    void popAt(int loc);
    bool isEmpty();
    void printForward();
    void printBackward();
    int search(T val);
    int size();
    void clear();

    void resetIterator();
    T& next();

    ~LinkedList();
};
//------------------------------------------------------LL Header ends


template <typename T>
LinkedList<T>::LinkedList()
    :head(nullptr), tail(nullptr), length(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &src) {
    head = src.head;
    tail = src.tail;
    length = src.length;
}

template <typename T>
LinkedList LinkedList<T>::operator=(const LinkedList<T> &src) {
    if(head != nullptr) {
        clear();
    }
    ListNode *curr = src.head;
    while(curr != nullptr) {
        push(curr->data);
        curr = curr->next;
    }
}

template <typename T>
void LinkedList<T>::push(T val) {
    if(head == nullptr) {
        head = new ListNode(val);
        tail = head;
    } else {
        tail->next = new ListNode(val);
        tail->next->prev = tail;
        tail = tail->next;
    }
    length++;

}
template <typename T>
void LinkedList<T>::popFront() {
    if(isEmpty())
        return;
    if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
    } else {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        length--;
    }
}

template <typename T>
void LinkedList<T>::popBack() {
    if(isEmpty())
        return;
    if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
    } else {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        length--;
    }
}

template <typename T>
void LinkedList<T>::pushAt(T val, int loc) {
    ListNode* curr = head;
    if(curr = head) {
        push(val);
        return;
    }
    while(curr->next != nullptr && loc > 0) {
        curr = curr->next;
        loc--;
    }
    if(curr == head || curr == tail)
        push(val);
    else {
        ListNode* elem = new ListNode(val); //Dynamically allocate the new thing
        elem->prev = curr; //its previous ptr now points to whatever curr is (thus putting it after curr)
        elem->next = curr->next; //its next pointer now points to whatever was after curr (putting it in between the two of them)
        curr->next->prev = elem; //the thing-after-curr's previous pointer now points to the new thing
        curr->next = elem; //and last, curr's next ptr now points to the new thing
        length++;
    }
}

template <typename T>
void LinkedList<T>::popAt(int loc) {
    if(loc >= length)
        throw out_of_range;
    ListNode* curr = head;
    while(loc > 0) {
        curr = curr->next;
        loc--;
        //This is another one from class.  It's interesting because it's moving to the location instead of immediately hopping to it
    }
    if(curr == head) //Basically if the list had only a single element
        popFront();
    else if(curr == tail)
        popBack();
    else {
        curr->prev->next = curr->next; //The element-before-curr's next pointer now points to the element after curr
        curr->next->prev = curr->prev; //The element-after-curr's prev pointer now points to the element before curr
        delete curr; //then you delete curr
        length--; //Proud that I understand this now
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    if(head == nullptr)
        return true;
    else
        return false;
}

template <typename T>
void LinkedList<T>::printForward() {
    ListNode* curr = head;
    while(curr != nullptr) {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

template <typename T>
void LinkedList<T>::printBackward() {
    printBackward(head);
    //I could just do this with tail and basically just merge this and its private-overloaded version, but I wanted to try this
}
template <typename T>
int LinkedList<T>::search(T val) {
    ListNode* curr = head;
    int count = 0;
    while(curr->data != val || curr->next != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;

}

template <typename T>
int LinkedList<T>::size() {
    return length;
}

template <typename T>
void LinkedList<T>::clear() {
    ListNode* curr = head;
    while(curr->next != nullptr) {
        delete curr;
        curr = curr->next;
    }
    head = nullptr;
    length = 0;
}

template <typename T>
void LinkedList<T>::resetIterator() {
    c_iter = head;
}

template <typename T>
T& LinkedList<T>::next() {
    if(c_iter == nullptr)
        throw out_of_range;
    c_iter = c_iter->next;
    return c_iter->prev->data;

}

template <typename T>
LinkedList<T>::~LinkedList() {}
#endif // LINKEDLIST_H
