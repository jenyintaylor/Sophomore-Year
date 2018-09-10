#ifndef PROFILE_H
#define PROFILE_H


#include <string>
#include <vector>
#include "tweet.h"

class Profile {
public:

    Profile(std::string n);
    ~Profile();

    std::vector<Tweet> timeline; //Purposefully let this be public for access.


    void addTweet(Tweet t);
    std::string getUser();
    int totalTweets();
    int posTweets();
    int negTweets();
    std::vector<Tweet> history();

private:
    std::string name;




};

#endif // PROFILE_H
