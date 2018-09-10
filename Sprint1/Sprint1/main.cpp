// Jeffrey Taylor, Sprint 1, 47400760
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <time.h>
#include "tweet.h"
#include "profile.h"


using namespace std; //Made the mistake of not taking the extension, hit roadblock.
//Did not finish as cleanly as I had hoped, and after taking a nap and making edits, the output file
// is mostly blank.  The tweet statistics show up but the madlibs do not.

void profileCreator();
void tweetScanner(long a, string b, string c, int d);
void fileReading(string l);
void outer();
float average(bool b);
void madlibs();
void madmagic(string s);

vector<Tweet> feed;
vector<Profile> people;
int tweetCounter = 0;
int posCounter = 0;
int negCounter = 0;
ofstream output;



int main(int argc, char* argv[]) {

    string skippedLine;
    string line;
    ifstream tweetfile(argv[1]);
    ifstream maddlibs(argv[2]);
    output.open(argv[3]);


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

    outer();
    string mline;
    if(!maddlibs.is_open()) {
        cerr << "Could not find file." << endl;
        exit(1);
    } else if(maddlibs.good()) {
        while(getline(maddlibs, mline)) {
            output << "Madd-Libs" << endl;
            madmagic(line);
    }
    }


    maddlibs.close();
    tweetfile.close();

    output.close();

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
    delete[]p;
}

void outer() {
    output << "Maddlibs\n" << endl;

    output << "Statistics:\n" << endl;
    output << "Total Tweets: " << tweetCounter << endl;
    output << "Total Positive Tweets: " << posCounter << endl;
    output << "Total Negative Tweets: " << negCounter << endl << endl;
    output << "Average Number of Words for Positive Tweets: " << average(1) << endl;
    output << "Average Number of Words for Negative Tweets: " << average(0) << endl;


}
float average(bool b) {
    float participants = 0;
    int pot = 0;
    for(unsigned int i = 0; i < feed.size(); i++) {

        if(feed.at(i).status() == b) {
            participants++;
            pot += feed.at(i).wc();
        } else { continue; }
    }
    float avg = pot/participants;
    return avg;
}


void madmagic(string s) {
    stringstream ms, ls, ss;
    ls.str(s);
    srand(time(NULL));
    int rng;

    string z;
    string mcopy;
    vector<string> msl;
    vector<string> choice;
    vector<string> wtype;
    vector<string> ans;

    ms.str(s);
    while(ms.good()) {
        getline(ms, mcopy);
        msl.push_back(mcopy);
    }
    while(ls.good()) {
        string guy;
        getline(ls, guy, ' ');
        choice.push_back(guy);
    }
    ss.str(s);
    while(ss.good()) {
        string partof;
        ss.ignore(3000, '[');
        getline(ss, partof, ']');
        wtype.push_back(partof);
    }

    for(unsigned int i = 0; i < choice.size(); i++) {
        for(unsigned int j = 0; j < people.size(); j++) {
            if(choice[i] == people[j].getUser()) {
                int r = people[j].totalTweets();
                rng = rand()% r;
                z = people[j].timeline[rng].filler(wtype[i]);
                ans.push_back(z);
            }

        }

    }

    for(unsigned int i = 0; i < msl.size(); i++) {
        int kk = msl[i].find('[');
        int jj = msl[i].find(']');
        int zz = jj-kk;

        msl[i].replace(kk, zz, ans[i]);
        output << msl[i] << endl;
    }
}

