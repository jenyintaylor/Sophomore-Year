//Jeffrey Taylor, 47400760, Sprint2


//def
#define CATCH_CONFIG_RUNNER

//inc
#include "catch.hpp"
#include "vect.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;


//prototypes
void runner(char* input);
void fileReader(string s);
void organizer();
void directory(string s);

//global variables
Vect<string> pholds;
Vect<string> real;
Vect<char> indie;
Vect<char> categ;
int pagecounter = 0;
int phrasecounter = 0;


//functions
int main(int argc, char* argv[]) {

    if(strcmp(argv[1], "-t") == 0) {
        Catch::Session().run();
    } else if(strcmp(argv[1], "-r") == 0) {
        runner(argv[2]);
    }

    return (0);
} //main is just command line args and what they do

void runner(char* input) {
    ifstream f;
    string lines;
    f.open(input);
    while(f.good()) {
        while(getline(f, lines)) {
            fileReader(lines);
        }
    }
    f.close();

    organizer();
} //what happens when -r is the argument

void fileReader(string s) {

    string holder;
    int pstart, pend;
    istringstream sol;
    sol.str(s);

    if(s.front() == '<') {
        getline(sol, holder);
        pagecounter++;

    } else {
        pstart = s.find('[') + 1;
        pend = s.find(']');

        //basically just the copy function of string
        for(int i = pstart; i < pend; i++) {
            holder += s[i];
        }
        if(pstart > 0)
            phrasecounter++;

    }

    if(holder != "")
        pholds.push(holder);
}

void organizer() {
    string ss;
    for(int i = 0; i < pholds.tot(); i++) {
        if(pholds[i].front() != '<') {
            char t = toupper(pholds[i].front());
            categ.push(t);
        }
        ss += pholds[i];
    }

    directory(ss);

    int l = categ.tot();
    char* d = new char[l];
    for(int i = 0; i < l; i++) {
        d[i] = categ[i];
    }
    sort(d, d+l);
    for(int i = 0; i < l; i++) {
        categ[i] = d[i];
    }
    delete[] d;
    //Now I have the little header things

}

void directory(string s) {

    cout << s << endl;
    string bit;
    int ender = s.find("<-1>");
    int seeker1 = s.find_first_of("<");
    int seeker2 = s.find_first_of(">");

    while(seeker2 != ender) {
        seeker2 = s.find_first_of("<", seeker2+1);

        int dist = seeker2 - seeker1;
        bit = s.substr(seeker1, dist);
        seeker1 = s.find_first_of("<", seeker1+1);
        cout << bit << endl;
    }


}


