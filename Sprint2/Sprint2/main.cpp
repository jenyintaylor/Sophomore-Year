#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "vect.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    Vect<int> leedle;
    for(int i = 0; i < 5; i++) {
        int j =(i*10)+5;
        leedle.push(j);
        cout << leedle[i] << endl;
    }

    return (0);
}
