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
    cout << s << endl;

    string holder;
    stringstream sol;
    sol.str(s);


    if(s.front() == '<') {
        sol.get(holder, 80, '>');
    }



    sol.close();
}
