#include "tweet.h"
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>
#include <algorithm>


using namespace std;

Tweet::Tweet(long x, string n, string t, int i)
    :id(x), user(n), text(t), target(i) {

    Tweet::organizer();
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

void Tweet::organizer() { //this is how I actually got the text to be readable
                          // With that being said, there was likely a better way to do it.
                          // This was a lot of repeating.

    stringstream s, ss, sss, ssss, sssss;
    s.str(text);
    vector<string> words;
    string shrinker;
    s.ignore(5, '[');


    while(s.good()) {
        string pieces;
        getline(s, pieces, ']');
        words.push_back(pieces);
    }
    words.pop_back();
    for(unsigned int i = 0; i < words.size(); i++) {
        shrinker = words[i];
    }
    words.clear();
    ss.str(shrinker);

    while(ss.good()) {
        string pieces;
        getline(ss, pieces, ')');
        words.push_back(pieces);
    }
    shrinker = "";
    for(unsigned int i = 0; i < words.size(); i++) {
        shrinker = shrinker + words[i];
    }

    words.clear();
    sss.str(shrinker);

    while(sss.good()) {
        string pieces;
        getline(sss, pieces, '(');
        words.push_back(pieces);
    }
    shrinker = "";
    for(unsigned int i = 0; i < words.size(); i++) {
        shrinker = shrinker + words[i];
    }
    words.clear();
    ssss.str(shrinker);

    while(ssss.good()) {
        string pieces;
        getline(ssss, pieces, '(');
        words.push_back(pieces);
    }
    shrinker = "";
    for(unsigned int i = 0; i < words.size(); i++) {
        shrinker = shrinker + words[i];
    }
    words.clear();
    sssss.str(shrinker);

    while(sssss.good()) {
        string pieces;
        getline(sssss, pieces, ',');
        words.push_back(pieces);
    }
    shrinker = "";
    for(unsigned int i = 0; i < words.size(); i++) {
        shrinker = shrinker + words[i];
    }

    for(unsigned int i = 0; i < words.size(); i+=2) {
        text += words[i];
    }


    tuple<string, string> wpos;
    for(unsigned int i = 1; i < words.size(); i+=2) {
        wpos = make_tuple(words[i], words[i-1]);
        vocab.push_back(wpos);
    }


}

int Tweet::wc() {
    return vocab.size();
}
// this is where the filled in response to the madlib would go.
string Tweet::filler(string s) {

    string ans;
    for(unsigned int i = 0; i < vocab.size(); i++) {
        if(s == get<0>(vocab[i])) {
            ans = get<1>(vocab[i]);
        }
    }
    return ans;
}
Tweet::~Tweet() {}

