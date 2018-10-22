#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
    LinkedList<int> joker;
    for(int i = 0; i < 50; i++) {
        joker.push((i*50)+1);
    }
    joker.popBack();
    joker.printForward();
}
