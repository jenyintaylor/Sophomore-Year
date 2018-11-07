#ifndef LINKEDLIST_H
#define LINKEDLIST_H


//started making doubly sure that the heads and tails were the ends each time.
//Also, I had an idea to code in an array to make using the []operator a lot easier.  Did not work
//Will keep working on it but need to turn this in for now
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class ListNode {
    template <class U>
    friend class LinkedList;
public:
    ListNode();
    ListNode(T val);
    ListNode(const ListNode<T> &src);
    ListNode& operator=(const ListNode<T> &src);
    ~ListNode();
private:
    T data;
    ListNode<T> *next, *prev;
};
//-----------------------------------------------------------------Node Header ends
template <typename T>
ListNode<T>::ListNode()
    :next(nullptr), prev(nullptr) {}

template <typename T>
ListNode<T>::ListNode(T val)
    :data(val), next(nullptr), prev(nullptr) {}

template <typename T>
ListNode<T>::ListNode(const ListNode<T> &src) {
    data = src.data;

}

template <typename T>
ListNode<T>& ListNode<T>::operator=(const ListNode<T> &src) {
    if(*this != &src) {
        delete data;
        delete next;
        delete prev;

        data = src.data;
        next = src.next;
        prev = src.prev;
    }
    return *this;
}

template <typename T>
ListNode<T>::~ListNode() {}

//-----------------------------------------------------------------Node implementation ends
template <typename T>
class LinkedList {
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int length;
    ListNode<T> *c_iter;


    void printBackward(ListNode<T>* var) {
        if(var == nullptr) {
            return;
        } //At the end of the list, this will be true, then it does the thing that's two lines below
        printBackward(var->next);
        //This will just keep going recursively
        cout << var->data << endl;
        //The last one will do this first, then the line of returns just keeps printing out lines in reverse order
        return;
    }

//priv ends


public:
    LinkedList();
    LinkedList(const LinkedList<T> &src);
    LinkedList& operator=(const LinkedList<T> &src);
    T& operator[](int location); //Since i'm not using pointers for data, I kinda have to send the item itself

    void push(T val);
    void pushFront(T val);
    void popFront();
    void popBack();
    void pushTo(T val, int loc);
    void popAt(int loc);
    bool isEmpty();
    void printForward();
    void printBackward();
    int search(T &val);
    int size();
    void clear();

    void resetIterator();
    T& next();
    T& getHead();
    T& getTail();

    ~LinkedList();
};
//------------------------------------------------------LL Header ends


template <typename T>
LinkedList<T>::LinkedList()
    :head(nullptr), tail(nullptr), length(0), c_iter(nullptr) {

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &src) {
    head = src.head;
    tail = src.tail;
    length = src.length;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &src) {

        if(*this != &src) {
            clear();
        }
        head = src.head;
        ListNode<T> *curr = head;
        while(curr != nullptr) {
            push(curr->data);
            curr = curr->next;
        }

        return *this; //A bug which I could not fix was solved by changing the return's name.  I am broken.
}

template <typename T>
T& LinkedList<T>::operator[](int location) {
    if(location < 0 || location >= length)
        throw out_of_range("Location is out of range");

    resetIterator();

    if(location != 0) {
        for(int i = 0; i < location; i++) {
            next();
        }
    }

    return this->c_iter->data;

}


template <typename T>
void LinkedList<T>::push(T val) {
    if(this->isEmpty()) {
        ListNode<T> *curr = new ListNode<T>(val);

        head = curr;
        tail = head;
    } else {
        ListNode<T> *curr = new ListNode<T>(val);

        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    head->prev = nullptr;
    tail->next = nullptr;
    length++;

}

template <typename T>
void LinkedList<T>::pushFront(T val) {
    if(isEmpty()) {
        push(val);
        return;
    } else {
        ListNode<T> *curr = new ListNode<T>(val);

        head->prev = curr;
        curr->next = head;
        head = curr;
    }
    length++;
    head->prev = nullptr;
    tail->next = nullptr;
}
template <typename T>
void LinkedList<T>::popFront() {
    if(isEmpty())
        return;
    if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;


    } else {
        ListNode<T> *temp = head->next;
        delete head;
        head = nullptr;
        temp->prev = nullptr;
        head = temp;

    }
    head->prev = nullptr;
    tail->next = nullptr;
    length--;
}

template <typename T>
void LinkedList<T>::popBack() {
    if(isEmpty())
        return;
    if(head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;

    } else {
        ListNode<T> *temp = tail->prev;
        delete tail;
        tail = nullptr;
        temp->next = nullptr;
        tail = temp;

    }
    head->prev = nullptr;
    tail->next = nullptr;
    length--;
}

template <typename T>
void LinkedList<T>::pushTo(T val, int loc) {
    if(loc < 0 || loc >= length)
        throw out_of_range("The location you're trying to push is out of range. Try pushFront(value) or pushBack(value) instead");

    if(loc == 0) {
        pushFront(val);
        return;
    }
    resetIterator();
    ListNode<T>* curr = head;
    if(curr == nullptr) {
        push(val);
        return;
    }


    while(curr->next != nullptr && loc > 0) {
        curr = curr->next;
        loc--;
    }
    if(curr == head)
        pushFront(val);
    else if(curr == tail)
        push(val);
    else {
        ListNode<T> *temp = new ListNode<T>(val);
        temp->prev = curr->prev;
        temp->next = curr;
        curr->prev->next = temp;
        curr->prev = temp;

        head->prev = nullptr;
        tail->next = nullptr;
        length++;
    }
}

template <typename T>
void LinkedList<T>::popAt(int loc) {
    int pos = loc;
    if(loc >= length) {
        throw out_of_range("That position does not exist in the Linked List.\n");
    }
    ListNode<T>* curr = head;
    if(loc == 0) {
        popFront();
        return;
    }
    if(loc == (length-1)){
        popBack();
        return;
    }

    while(pos > 0) {
        curr = curr->next;
        pos--;
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
        head->prev = nullptr;
        tail->next = nullptr;
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
    ListNode<T>* curr = head;
    while(curr != nullptr) {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

template <typename T>
void LinkedList<T>::printBackward() {
    printBackward(head);
    //I could just do something like the implementation of printForward with tail and basically just merge this and its private-overloaded version, but I wanted to try this
    //Neato. It worked.
}
template <typename T>
int LinkedList<T>::search(T& val) {
    ListNode<T>* curr = head;
    int count = 0;
    T stopper = curr->data;
    while(&stopper != &val || curr->next != nullptr) {
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
    if(isEmpty())
        return;
    ListNode<T>* curr = head;
    while(curr->next != nullptr) {
        delete curr;
        curr = curr->next;
    }

    head = nullptr;
    tail = nullptr;
    length = 0;
    delete curr;
}


template <typename T>
void LinkedList<T>::resetIterator() {
    c_iter = head;
}

template <typename T>
T& LinkedList<T>::next() {
    if(c_iter == nullptr) {
        throw out_of_range("The iterator has not been reset or the linked list has not been filled.\n");
    } else if (c_iter == tail) {
        return tail->data;
    }
    c_iter = c_iter->next;
    return c_iter->prev->data;

}

template <typename T>
T& LinkedList<T>::getHead() {
    return head->data;
}

template <typename T>
T& LinkedList<T>::getTail() {
    return tail->data;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

#endif // LINKEDLIST_H
