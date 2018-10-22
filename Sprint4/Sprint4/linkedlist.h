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
    next = src.next;
    prev = src.prev;
}

template <typename T>
ListNode<T>& ListNode<T>::operator=(const ListNode<T> &src) {
    if(*this != &src) {
        delete data;
        delete next;
        delete prev;

        ListNode(src);
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
    //T* list;
    //int holder = 50;
    //int counter = 0;

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
public:
    LinkedList();
    LinkedList(const LinkedList<T> &src);
    LinkedList& operator=(const LinkedList<T> &src);
    T operator[](int location); //Since i'm not using pointers for data, I kinda have to send the item itself

    void push(T val);
    void pushFront(T val);
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
    //void organizerFix();

    void resetIterator();
    T& next();

    ~LinkedList();
};
//------------------------------------------------------LL Header ends


template <typename T>
LinkedList<T>::LinkedList()
    :head(nullptr), tail(nullptr), length(0), c_iter(nullptr) {

    //list = new T[holder];
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &src) {
    head = src.head;
    tail = src.tail;
    length = src.length;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &src) {
    if(head != nullptr) {
        clear();
    }
    head = src.head;
    ListNode<T> *curr = head;
    while(curr != nullptr) {
        push(curr->data);
        curr = curr->next;
    }
    return *curr;
}

template <typename T>
T LinkedList<T>::operator[](int location) {

    if(location < 0 || location >= length)
        throw out_of_range("Location is out of range");


    resetIterator();
    T result;
    for(int i = 0; i < location+1; i++) {
        result = next();
    }
    return result;
    //return this->list[location];  //will figure out a way to make this work later

}


template <typename T>
void LinkedList<T>::push(T val) {
    if(this->isEmpty()) {
        ListNode<T> *curr = new ListNode<T>(val);
        //organizerFix();
        //list[counter] = val;

        head = curr;
        tail = head;
    } else {
        ListNode<T> *curr = new ListNode<T>(val);
        //organizerFix();
        //list[counter] = val;

        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    head->prev = nullptr;
    tail->next = nullptr;
    //counter++;
    length++;

}

template <typename T>
void LinkedList<T>::pushFront(T val) {
    if(isEmpty()) {
        push(val);
        return;
    } else {
        ListNode<T> *curr = new ListNode<T>(val);

//        organizerFix();
//        T* temp = new T[holder];
//        for(int i = 0; i < length; i++) {
//            temp[i+1] = list[i];
//        }
//        temp[0] = val;
//        delete[] list;
//        list = temp;
//        delete[] temp;

        head->prev = curr;
        curr->next = head;
        head = curr;
    }
    //counter++;
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
        //list[0] = nullptr;


    } else {
        ListNode<T> *temp = head->next;
        delete head;
        head = nullptr;
        temp->prev = nullptr;
        head = temp;

//        T* standin = new T[holder];
//        for(int i = 0; i < length; i++) {
//            standin[i] = list[i+1];
//        }
//        delete[] list;
//        list = standin;
//        delete[] standin;


    }
    //counter--;
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
        //list[length-1] = nullptr;

    } else {
        ListNode<T> *temp = tail->prev;
        delete tail;
        tail = nullptr;
        temp->next = nullptr;
        tail = temp;
        //list[length-1] = nullptr;

    }
    //counter--;
    head->prev = nullptr;
    tail->next = nullptr;
    length--;
}

template <typename T>
void LinkedList<T>::pushAt(T val, int loc) {
    if(loc == 0) {
        pushFront(val);
        return;
    }

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
    else if(curr = tail)
        push(val);
    else {
        ListNode<T> *temp = new ListNode<T>(val);
        temp->prev = curr;
        temp->next = curr->next;
        curr->next->prev = temp;
        curr->next = temp;

//        T* temp = new T[holder];
//        for(int i = 0; i < loc; i++) {
//            temp[i] = list[i];
//        }
//        temp[loc] = val;
//        for(int i = (loc+1); i < length; i++) {
//            temp[i] = list[i-1];
//        }
//        delete[] list;
//        list = temp;
//        delete[] temp;


        //counter++;
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

//        T* temp = new T[holder];
//        for(int i = 0; i < loc; i++) {
//            temp[i] = list[i];
//        }
//        for(int i = (loc+1); i < length; i++) {
//            temp[i-1] = list[i];
//        }
//        delete[] list;
//        list = temp;
//        delete[] temp;

        //counter--;
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
    //I could just do this with tail and basically just merge this and its private-overloaded version, but I wanted to try this
}
template <typename T>
int LinkedList<T>::search(T val) {
    ListNode<T>* curr = head;
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
    if(isEmpty())
        return;
    ListNode<T>* curr = head;
    while(curr->next != nullptr) {
        delete curr;
        curr = curr->next;
    }
    //delete[] list;

    head = nullptr;
    tail = nullptr;
    //list = nullptr;
    //counter = 0;
    length = 0;
    delete curr;
}
//template <typename T>
//void LinkedList<T>::organizerFix() {
//    if(length >= (holder-5)) {
//        holder *= 2;
//        T* temp = new T[holder];
//        for(int i = 0; i < length; i++) {
//            temp[i] = list[i];
//        }
//        delete[] list;
//        list = temp;
//        delete[] temp;
//        return;
//    } else {
//        return;
//    }
//}

template <typename T>
void LinkedList<T>::resetIterator() {
    c_iter = head;
}

template <typename T>
T& LinkedList<T>::next() {
    if(c_iter == nullptr) {
        throw out_of_range("Iterator has not been reset yet.\n");
    } else if (c_iter == tail) {
        return tail->data;
    }
    c_iter = c_iter->next;
    return c_iter->prev->data;

}


template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

#endif // LINKEDLIST_H
