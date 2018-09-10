#include "tweet.h"
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

Tweet::Tweet(long x, string n, string t, int i)
    :id(x), user(n), text(t), target(i) {
}
long Tweet::getID() {
    return id;
}
void Tweet::setID(long x) {
    id = x;
}
string Tweet::getUser() {
    return user;
}
void Tweet::setUser(string a) {
    user = a;
}
string Tweet::getText() {

    return text;
}
void Tweet::setText(string a) {
    text = a;
}
int Tweet::getTarget() {
    return target;
}
void Tweet::setTarget(int x) {
    target = x;
}

bool Tweet::status() { //Target determines sentiment, with 4 being positive and 0 negative
    int sentiment;
    sentiment = target;
    if(sentiment > 0)
        return 1;
    else
        return 0;

}
Tweet::~Tweet() {}

