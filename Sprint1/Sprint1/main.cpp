#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int main() {
    string line;
    ifstream tweetfile("/home/student/Desktop/CSE2341-18F-Jeffrey-Taylor/Sprint1/Sprint1/5-user-tweets.csv");

    if(!tweetfile.is_open()) {
        cerr << "Whoops" << endl;
        exit(1);
    }
    if(tweetfile.good()) {
        while(getline(tweetfile, line)) {
            cout << line << '\n';
        }

    }
    tweetfile.close();
    return 0;
}
