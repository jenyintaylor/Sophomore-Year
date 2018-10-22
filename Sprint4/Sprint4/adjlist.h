#ifndef ADJLIST_H
#define ADJLIST_H

#include "linkedlist.h"
#include "stack.h"

template <typename T>
class AdjList {
private:
    LinkedList<LinkedList<T>> data;

    LinkedList<T>* findWhereFirstIs(T val) {
        for(int i = 0; i < data.size(); i++) {
            if(data[i][0] == val)
                return &data[i];
        }
    }

public:
    void insertFor(T find, T val);
    T stepIteratorFor(T val);

};

template <typename T>
void AdjList<T>::insertFor(T find, T val) {
    bool inserted = false;
    for(int i = 0; i < data.size(); i++) {
        if(data[i][0] == find) {
            data[i].push(val);
            inserted = true;
        }
    }
    if(!inserted) {
        LinkedList<T> temp;
        temp.push(find);
        temp.push(val);
        data.push(temp);
    }
}

template <typename T>
T AdjList<T>::stepIteratorFor(T val) {
    LinkedList* l = findWhereFirstIs(val);
    return l->next();
}
#endif // ADJLIST_H
