//Jeffrey Taylor, 47400760, Sprint2


//def
#define CATCH_CONFIG_RUNNER

//inc
#include "catch.hpp"
#include "vect.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;


//prototypes
void runner(char* input);
void fileReader(string s);
void organizer();

//global variables
Vect<string> pholds;


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

    } else {
        pstart = s.find('[') + 1;
        pend = s.find(']');

        //basically just the copy function of string
        for(int i = pstart; i < pend; i++) {
            holder += s[i];
        }
    }

    if(holder != "")
        pholds.push(holder);
}

void organizer() {
    int q = pholds.tot();

    //int* pages = new int[q];
    char* ind = new char[q];
    string ss, ns;
    for(int i = 0; i < q; i++) {
            if(pholds[i].front() != '<') {

            ind[i] = toupper(pholds[i].front());
            cout << ind[i] << endl;
            }

        ss += pholds[i];
    }
    cout << ss << endl;
    //delete[] pages;
    delete[] ind;
}
