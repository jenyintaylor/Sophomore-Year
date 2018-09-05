#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    string line;
    ifstream tweetfile("5-user-tweets.csv");

    if(!tweetfile.is_open())
        cout << "Whoops" << endl;

    if(tweetfile.good()) {
        while(getline(tweetfile, line)) {
            cout << line << '\n';
        }

    }
    tweetfile.close();
    return 0;
}
