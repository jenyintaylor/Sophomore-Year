#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include "tweet.h"
#include "profile.h"


using namespace std;

vector<Tweet> feed;
vector<Profile> people;
int tweetCounter = 0;
int posCounter = 0;
int negCounter = 0;

void profileCreator() {
    set<string> usernames; //Create a set so names won't appear more than once

    for(unsigned int i = 0; i < feed.size(); i++) { //adds names to set
        usernames.insert(feed[i].getUser());
    }

    for(set<string>::iterator i = usernames.begin(); i != usernames.end(); i++) {
        string username; //Step by step.
        username = *i;
        Profile human(username);
        people.push_back(human); //Now the vector has the names
    }

    for(unsigned int i = 0; i < people.size(); i++) {
        for(unsigned int j = 0; j < feed.size(); j++) {
            string person = people[i].getUser();
            string tweetp = feed[j].getUser();
            if(person.compare(tweetp) == 0)
                people[i].addTweet(feed[j]);
        }
    }
    cout << people.size() << endl << people[0].totalTweets() << endl;

}

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
    string filename;
    cout << "Please enter the file name (minus the file-type): ";
    cin >> filename;
    fstream tweetfile(filename + ".csv");
    //fstream tweetfile("/home/student/Desktop/CSE2341-18F-Jeffrey-Taylor/Sprint1/Sprint1/.csv");

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
            char w = p[2].back();
            target = w - '0';

            tweetScanner(id, user, text, target);


        }

    }
    profileCreator();

    tweetfile.close();
    return 0;
}
