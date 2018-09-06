#ifndef TWEET_H
#define TWEET_H
#include <string>

class Tweet
{
public:
    Tweet(long id, std::string user, std::string text, int target);
    ~Tweet();

    void setID(long x);
    int getID();

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
