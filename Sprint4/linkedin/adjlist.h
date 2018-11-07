#ifndef ADJLIST_H
#define ADJLIST_H

#include "linkedlist.h"
#include "stack.h"

template <typename T>
class AdjList {
private:
    //members
    LinkedList<LinkedList<T>> data;
    T* iter; //
    int itercount;
    int previtercount = 0; //iterator and previous iterator so I can actually iterate

    //priv funct
    LinkedList<T>* findWhereFirstIs(T val) {
        for(int i = 0; i < data.size(); i++) {
            if(data[i][0] == val)  {
                return &data[i];
            }
        }
        return nullptr;
    }
public:
    AdjList();
    AdjList(const AdjList<T> &src);
    AdjList& operator=(const AdjList<T> &src);
    ~AdjList();
    void insertFor(T find, T val);
    T *stepIteratorFor(T val);
    int lazyCount(T info);

};
template <typename T>
AdjList<T>::AdjList()
    :iter(nullptr) {
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

            return;
        }
    }

    if(!inserted) {
        LinkedList<T> temp;
        data.push(temp);
        data[data.size()-1].push(find);
        data[data.size()-1].push(val);

        LinkedList<T>* checker = findWhereFirstIs(val);
        if(checker == nullptr) {
            LinkedList<T> temp2;
            data.push(temp2);
            data[data.size()-1].push(val);
            data[data.size()-1].push(find); //I did this because I realized that connected are mutual, and that is also the best way to shorten the degrees of separation
        }
        return;
    }
}

template <typename T>
T* AdjList<T>::stepIteratorFor(T val) {
    LinkedList<T>* l = findWhereFirstIs(val);

    if(l == nullptr) { //checks if l exists
        iter = nullptr;
        return iter;
    }


    l->resetIterator(); //good, it does.


    for(itercount = 0; itercount <= previtercount; itercount++) { //basically the same idea as the index operator
        if(previtercount >= l->size())
            previtercount = 0;

        iter = &l->next();
    }
    previtercount++;

    return iter;
}

template <typename T>
int AdjList<T>::lazyCount(T info) {
    int count = 0;
    LinkedList<T>* lazy = findWhereFirstIs(info);
    count = lazy->size()-1; //gets all the direct connections
    if(count >= data.size()-1)
        return count;

    int loc = data.search(*lazy);

    if(&data[loc] == &data.getTail()) {
        count = count + (data[data.size()-2].size() - 2); //2 is the overlap in names, and also the position before the tail
        return count;
    }
    if(&data[loc] == &data.getHead()) {
        count = count + (data[1].size()-2);
        return count;
    }
    else {

        count = (data[loc-1].size()-2) + count + (data[loc+1].size()-2);
        return count;
    }
}

template <typename T>
AdjList<T>::~AdjList() {
    data.~LinkedList();
}
#endif // ADJLIST_H
