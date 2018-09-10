#include "profile.h"
#include <string>
#include <vector>

using namespace std; //Most of this is pretty simple.

Profile::Profile(string n)
    :name(n) {
}
string Profile::getUser() {
    return name;
}

void Profile::addTweet(Tweet t) {
    timeline.push_back(t);
}
int Profile::totalTweets() {
    return timeline.size();
}

int Profile::posTweets() {
    int posCount;
    for(unsigned int i = 0; i < timeline.size(); i++) {
        if(timeline[i].status())
            posCount++;
    }
    return posCount;
}

int Profile::negTweets() {
    int negCount;
    for(unsigned int i = 0; i < timeline.size(); i++) {
        if(!timeline[i].status())
            negCount++;
    }
    return negCount;
}

std::vector<Tweet> Profile::history() {
    return timeline;
}

Profile::~Profile() {}
