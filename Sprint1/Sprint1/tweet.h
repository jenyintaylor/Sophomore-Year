#ifndef TWEET_H
#define TWEET_H
#include <string>

//Make class specifically for tweets.  Will make counting and sorting easier.
class Tweet {
public:
    Tweet(long x, std::string n, std::string t, int i);
    ~Tweet();

    //ID is set to be of type long due to the pattern of 10 digits.
    //In theory an unsigned int could work, but based on the nature
    //of the internet, that number could be overtaken and forcibly
    //reset fairly quickly.
    void setID(long x);
    long getID();

    void setUser(std::string a);
    std::string getUser();

    void setText(std::string a);
    std::string getText();

    void setTarget(int x);
    int getTarget();


private:
    long id;
    std::string user;
    std::string text;
    int target;

};

#endif // TWEET_H
