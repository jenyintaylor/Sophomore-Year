#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "vect.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

void runner(char* input);
void fileReader(string s);

int main(int argc, char* argv[]) {

    if(strcmp(argv[1], "-t") == 0) {
        Catch::Session().run();
    } else if(strcmp(argv[1], "-r") == 0) {
        runner(argv[2]);
    }

    return (0);
}

void runner(char* input) {
    ifstream f;
    string lines;
    f.open(input);
    while(f.good()) {
        while(getline(f, lines)) {
            fileReader(lines); //chkpnt
        }
    }

    f.close();
}

void fileReader(string s) {

    string holder;
    int pstart, pend;
    istringstream sol;
    sol.str(s);

    if(s.front() == '<') {
        sol.ignore(1);
        getline(sol, holder, '>');

    } else {
        pstart = s.find('[') + 1;
        pend = s.find(']');

        //basically just the copy function of string
        for(int i = pstart; i < pend; i++) {
            holder += s[i];
        }
    }
    if(holder == "")
        cout << "Useless line" << endl;
    else
        cout << holder << endl;

}
