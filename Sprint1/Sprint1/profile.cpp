#include "profile.h"
#include <string>
#include <vector>

using namespace std;

Profile::Profile(Tweet t)
    :thisTweet(t) {
    timeline.push_back(t);
}
string Profile::getID() {
    name = thisTweet.getID();
    return name;
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

Profile::~Profile() {}
