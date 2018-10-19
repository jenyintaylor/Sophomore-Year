#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
    void printForward();
    void printBackward();
    bool isEmpty();
    int search(T val);
    int size();
    void clear();

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

}

template <typename T>
void LinkedList<T>::popAt(int loc) {

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
LinkedList<T>::~LinkedList() {}
#endif // LINKEDLIST_H
