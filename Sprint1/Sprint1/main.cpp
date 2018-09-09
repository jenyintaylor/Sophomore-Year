#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tweet.h"
#include "profile.h"


using namespace std;

vector<Tweet> feed;
vector<Profile> tweeters;
int tweetCounter = 0;
int posCounter = 0;
int negCounter = 0;

void tweetScanner(long a, string b, string c, int d) {
    Tweet info(a, b, c, d);
    feed.push_back(info);
    tweetCounter++;

    if(d != 0)
        posCounter++;
    else
        negCounter++;


}


int main() {
    string skippedLine; //Top line doesn't have a use
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
            }
            p[2] = line.substr(starter);

            id = stol(p[0]);
            user = p[1];
            text = p[2];
            target = (int)line.back();

            tweetScanner(id, user, text, target);


        }

    }
    cout << tweetCounter << endl;
    tweetfile.close();
    return 0;
}
