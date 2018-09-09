#ifndef PROFILE_H
#define PROFILE_H


#include <string>
#include <vector>
#include "tweet.h"

class Profile {
public:
    Profile(Tweet t);
    ~Profile();

    std::string getID();
    int totalTweets();
    int posTweets();
    int negTweets();

private:
    std::string name;
    std::vector<Tweet> timeline;
    Tweet thisTweet;


};

#endif // PROFILE_H
