#ifndef PROFILE_H
#define PROFILE_H


#include <string>
#include <vector>
#include "tweet.h"

class Profile {
public:
    Profile(std::string n);
    ~Profile();

    void addTweet(Tweet t);
    std::string getUser();
    int totalTweets();
    int posTweets();
    int negTweets();

private:
    std::string name;
    std::vector<Tweet> timeline;


};

#endif // PROFILE_H
