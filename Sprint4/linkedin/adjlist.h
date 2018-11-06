#ifndef ADJLIST_H
#define ADJLIST_H

#include "linkedlist.h"
#include "stack.h"

template <typename T>
class AdjList {
private:
    //members
    LinkedList<LinkedList<T>> data;

    //priv funct
    LinkedList<T>* findWhereFirstIs(T val) {
        for(int i = 0; i < data.size(); i++) {
            if(data[i][0] == val)
                return &data[i];
        }
    }
public:
    AdjList();
    AdjList(const AdjList<T> &src);
    AdjList& operator=(const AdjList<T> &src);
    ~AdjList();
    void insertFor(T find, T val);
    T stepIteratorFor(T val);

};
template <typename T>
AdjList<T>::AdjList() {
    LinkedList<T> filler;
    data.push(filler);
}

template <typename T>
AdjList<T>::AdjList(const AdjList<T> &src) {
    data = src.data;
}

template <typename T>
AdjList<T>& AdjList<T>::operator=(const AdjList<T> &src) {
    if(!data.isEmpty()) {
        data.clear();
    }
    int ij = 0;
    while(ij < data.size()) {
        int jj = 0;
        while(jj < data[ij].size()) {
            data[ij][jj] = src[ij][jj];
            //just goes through and matches
            jj++;
        }
        ij++;
    }
    return *this;
}

template <typename T>
void AdjList<T>::insertFor(T find, T val) {

    if(data[0].isEmpty()) {
        data[0].push(find);
        data[0].push(val);
        return;
    }

    bool inserted = false;

    for(int i = 0; i < data.size(); i++) {
        if(data[i][0] == find) {
            data[i].push(val);
            inserted = true;
        }
    }

    if(!inserted) {
        LinkedList<T> temp;
        data.push(temp);
        temp.push(find);
        temp.push(val);

    }
}

template <typename T>
T AdjList<T>::stepIteratorFor(T val) {
    LinkedList<T>* l = findWhereFirstIs(val);
    return l->next();
}

template <typename T>
AdjList<T>::~AdjList() {
    data.~LinkedList();
}
#endif // ADJLIST_H
