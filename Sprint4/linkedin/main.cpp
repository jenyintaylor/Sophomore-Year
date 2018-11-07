#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "linkedlist.h"
#include "adjlist.h"
#include "stack.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

AdjList<string> lister;
ofstream fileprint;
int maxval = 0;

void actualMain(char *input);
void minDistance(char *distance);
void adder(string s, int l);
void distCheck(string s, int l);
void backTrack(string s1, string s2);
void printer(string s1, string s2 = "", int e = 0);

int main(int argc, char* argv[]) {
    if(strcmp(argv[1], "-t") == 0) {
        Catch::Session().run();

    } else if(strcmp(argv[1], "-r") == 0) {
        fileprint.open(argv[4]);

        actualMain(argv[2]); //basically ripped from my Sprint 2
        minDistance(argv[3]);

        fileprint.close();
    }
    exit(0);
}

//what is in here TBD
void actualMain(char* input) {
    ifstream reader;
    reader.open(input);


    int linenum;
    string line, dummy;
    reader >> linenum;
    maxval = linenum;

    getline(reader, dummy);

    for(int i = 0; i < linenum; i++) {
        getline(reader, line);
        unsigned int loc = line.find('|');

        adder(line, loc);
    }

    reader.close();
}

void minDistance(char *distance) {
    ifstream reader;
    reader.open(distance);


    int linenum;
    string line, dummy;
    reader >> linenum;

    getline(reader, dummy);

    for(int i = 0; i < linenum; i++) {
        getline(reader, line);
        unsigned int loc = line.find('|');

        distCheck(line, loc);
    }
    reader.close();
}

void adder(string s, int l) { //makes the adjacency list
    string w1 = "";
    string w2 = "";

    for(int i = 0; i < l; i++) {
        w1 += s[i];
    }
    for(unsigned int i = l+1; i < s.size(); i++) {
        w2 += s[i];
    }
    lister.insertFor(w1, w2);
}

void distCheck(string s, int l) { //for the distance file
    string w1 = "";
    string w2 = "";

    for(int i = 0; i < l; i++) {
        w1 += s[i];
    }
    for(unsigned int i = l+1; i < s.size(); i++) {
        w2 += s[i];
    }
    backTrack(w1, w2);
}

void backTrack(string s1, string s2) {
    Stack<string> jenga; //Amazing name

    //note: s1 is the active user, s2 is the target user.

    jenga.push(s1);
    int dist = 0;
    string* topiter = nullptr;
    topiter = &s1;

    while(!jenga.isEmpty()) {
        if(jenga.peek() == s2) {
            dist = jenga.size()-1;
            if(dist <= maxval)
                maxval = dist;

            jenga.pop();
        } else {
            *topiter = lister.stepIteratorFor(*topiter);
            while(topiter != nullptr && jenga.contains(*topiter)) {
                *topiter = lister.stepIteratorFor(*topiter);
            }
            if(topiter != nullptr)
                jenga.push(*topiter);
            else {
                topiter = &s1;
                jenga.pop();
            }
        }

    }
    printer(s1, s2, maxval);

}

void printer(string s1, string s2, int e) {

    if(s2 != "") {
        fileprint << s1 << " to " << s2 << ": " << e << " degrees of separation" << endl;
    } else {
        fileprint << s1 << " is connected (directly or indirectly) to " << e << " people" << endl;
    }
}



/*Lab notes:
    They also want to see how many people a certain person is connected to (both directly and indirectly with a max distance of 2)
    Really, follow rules and ask help again later if needed

    -r has three files.  What the graph is, the paths wanted, and the output
    -t is exactly what it already is

    So in the adjacency list, make sure that you have name 1 and name 2 connected to each other

    ---------------------------------------------------------
    6
    Carol | Bob
    Carol | Ellen
    Bob | Dave
    Dave | Ellen
    Dave | Frances
    Ellen | Frances
    ----------------------------------------------------------

    So you start with Carol(see phone, Oct 25).  She is connected to Bob.
    In your list, there is no row for Bob, thus you make it.
    Bob, we already know has a Carol.  [1][1] is thus, Carol.
    Back to row 0.  Next name is Ellen.
    She is not in your list of rows, so add her under Bob. [2][1] is now Carol.  And continue

    Next part is why you have a stack.
    You are given Carol, and you need to find how close she is to Frances.

    Iterative Backtracking:
        Make Stack
        Reset all iterators
        Push your start person (Carol).

        while(!stack.isEmpty())
            So then you peek to see if the top person on the stack is the target name.
            No?
            Next name: push Bob.
                Frances?
                If yes: Save path and pop it off the stack
                If no: search from top

            while(top iterator is not on stack)
                stepIter
            if(top.iterator exists)
                push(top.iterator)

        Eventually you'll reach frances.  That's when you backtrack. Basically, it'll loop through again.

        First time: Carol - Bob - Dave - Ellen - Frances
        Then:       Carol - Bob - Dave - Frances
                    Carol - Ellen - Dave - Frances
                    Carol - Ellen - Frances

                    Then Stack is empty.  You have all your paths.  Save and all that and you're good




Next lab
You wanna get the number of people within two hops.

    6
    Tom | Bob
    Tom | Jon
    Tom | Sam
    Sam | Bob
    Sam | Sal
    Bob | Sal

    So lets say you're choosing Bob as your starter
    Bob 4
    Jon 3
    Sal 3
    Sam 4
    Tom 4

    Now you have the stack part.

    initial:
        push start person
        reset iterators
        while(!stack isempty)
            if
                top == target
                save path length (stack size -1)
                pop
            else
                top-iter-step
                while(top-iter exists && stack contains top.iter)
                    top.iter.step
            if top.iter.exists
                push(top.iter)
            else
                top.iter.reset
                pop



*/
