#ifndef VECT_H
#define VECT_H

//inc

template <typename t>


// Header Part
class Vect {
private:
    int size;
    int capacity;
    t* data;


public:
    Vect(const Vect<t>&);
    Vect(int initSize = 10);
    Vect& operator=(const Vect ct);
    ~Vect();

    t operator[](int location);
    t elementAt(int location);
    void setElementAt(int location, t);

    void push(t);
    void pop();
    void popAt(int location);
};





#endif // VECT_H
