#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include "tweet.h"
#include "profile.h"


using namespace std;

void profileCreator();
void tweetScanner(long a, string b, string c, int d);
void fileReading(string l);

vector<Tweet> feed;
vector<Profile> people;
int tweetCounter = 0;
int posCounter = 0;
int negCounter = 0;


int main(int argc, char* argv[]) {
    string skippedLine;
    string line;
    fstream tweetfile(argv[1]);

    if(!tweetfile.is_open()) {
        cerr << "Could not find file." << endl;
        exit(1);
    } else if(tweetfile.good()) {
        getline(tweetfile, skippedLine); //Skipped first line

        while(getline(tweetfile, line)) { //Loop through other function.
            fileReading(line);
        }
    }
    profileCreator();

    tweetfile.close();
    return 0;
}

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

    for(unsigned int i = 0; i < people.size(); i++) { //Adds the specific tweets to each profile.
        for(unsigned int j = 0; j < feed.size(); j++) {
            string person = people[i].getUser();
            string tweetp = feed[j].getUser();
            if(person.compare(tweetp) == 0)
                people[i].addTweet(feed[j]);
        }
    }
    for(unsigned int i = 0; i < people.size(); i++) {
        cout << people[i].getUser() << endl;
    }
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

void fileReading(string l) {
    long id;
    string user, text;
    int target;
    string*p = new string[3];


    int location = 0;
    int starter = 0;
    for(int i = 0; i < 2; i++) {
        location = l.find(",",starter);
        int dist = location - starter;
        p[i] = l.substr(starter,dist);
        starter = location + 1;
    }
    p[2] = l.substr(starter);

    id = stol(p[0]);
    user = p[1];
    text = p[2];
    char w = p[2].back();
    target = w - '0';

    tweetScanner(id, user, text, target);
}
