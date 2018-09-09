#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tweet.h"


using namespace std;

int main() {
    string skippedLine;
    string line;
    fstream tweetfile("/home/student/Desktop/CSE2341-18F-Jeffrey-Taylor/Sprint1/Sprint1/5-user-tweets.csv");

    if(!tweetfile.is_open()) {
        cerr << "Whoops" << endl;
        exit(1);
    }

    if(tweetfile.good()) {
        getline(tweetfile, skippedLine);

        while(getline(tweetfile, line)) {
            long id;
            string user, text;
            int target;
            string*p = new string[3];


            int location = 0;
            int starter = 0;
            for(int i = 0; i < 2; i++) {
                location = line.find(",",starter);
                int dist = location - starter;
                p[i] = line.substr(starter,dist);
                starter = location + 1;
                cout << p[i] << endl;
            }
            p[2] = line.substr(starter);
            cout << p[2] << endl;

            id = stol(p[0]);
            target = (int)line.back();



        }

    }
    tweetfile.close();
    return 0;
}
