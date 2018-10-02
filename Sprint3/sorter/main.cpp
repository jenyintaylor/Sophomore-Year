//Jeffrey Taylor, 47400760


//incs
#include <iostream>
#include "vect.h"
#include <fstream>

using namespace std;

//globs
Vect<string> thing;


//prots
void reader(char *file);
void sorter();
void printer(int d);

//functs
int main(int argc, char* argv[])
{
    reader(argv[1]);
    return 0;
}

void reader(char* file) {
    ifstream f(file);


    //the magic happens here
        int* imps = new int[2];
        int l, p;

        //resizing
        for(int i = 0; i < 2; i++) {
        string s;
        int d;
        getline(f, s);
        d = stoi(s);
        imps[i] = d;

        }
        l = imps[0];
        p = imps[1];

        thing.resize(l);

        //adding words
        for(int i = 0; i < l; i++) {
            string s;
            getline(f,s);
            thing.push(s);
            cout << s << endl;
        }
        sorter();
        printer(p);

        delete[] imps;
    f.close();
}

void sorter() {
    //Here, the program "elegantly" sorts whatever is in the vector
    int t = thing.tot();
    string* s = new string[t];

    for(int i = 0; i < t; i++) {
        s[i] = thing[i];
    }

    string slongest;
    int snul = 0;

    for(int i = 0; i < t; i++) {
        int sf;
        sf = thing[i].length();
        if(sf > snul) {
            snul = sf;
            slongest = thing[i];
        }
        //cout << slongest << endl;
    }
    delete[] s;
}

void printer(int d) {
    //nothing for now
}














/*
 * Stuff said in lab:
 *
 * Valgrind has another thing called Valgrind Function Profiler
 * If possible, take things from O(n^2) to O(n)
 * Amdal's Law: The speedup gained from making an adjustment to a single block of execution/hardware is bounded by the impact it had to begin with.
 *              (The thing that has 95% of your runtime can only boost speed by that much...kinda)
 *              Eliminate cout and cin for optimal speed
 *
 *              From the core, reading from cache is fastest.
 *              takes 10ns to read from cache, 100ns from RAM, 10ms from storage. 10 seconds of cache is like 12 days of storage.
 *
 *              Eliminate unnecessary file-reads.  Those come from storage.
 *              Find way to put things into memory.  Also allocate your memory beforehand.
 *
 *              time ./sorter command args
 *
 *
 *              Don't push these to github.  Add datafiles to git-ignore
 *                  Navigate to the sprint file, do the
 *                  ll
 *
 */
