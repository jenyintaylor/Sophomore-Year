#include "tweet.h"
#include <iostream>
#include <string>

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
Tweet::~Tweet() {}

