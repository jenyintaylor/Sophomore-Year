//Jeffrey Taylor, 47400760


//incs
#include <iostream>
#include "vect.h"
#include <fstream>

using namespace std;

//globs


//prots
void reader(char *file);
void sorter(string *w, int top, int bot);
void printer(int d);

//functs
int main(int argc, char* argv[])
{
    reader(argv[1]);
    return 0;
}

void reader(char* file) {
    ifstream f(file);


    //the magic happens here
    int* imps = new int[2];
    int l, p, o;
    o = 0;

    //resizing
    for(int i = 0; i < 2; i++) {
        string s;
        int d;
        getline(f, s);
        d = stoi(s);
        imps[i] = d;
    }

    l = imps[0];
    p = imps[1];

    string* words = new string[l];

        for(int i = 0; i < l; i++) {
            string s;
            getline(f, s);
            words[i] = s;
        }

//        thing.resize(l); //New idea, use array

//        //adding words
//        for(int i = 0; i < l; i++) {
//            string s;
//            getline(f,s);
//            thing.push(s);
//            cout << s << endl;
//        }
        sorter(words, l, o);
        printer(p);

        delete[] imps;
    f.close();
}

void sorter(string* w, int top, int bot) {
    //Here, the program "elegantly" sorts whatever is in the vector

    int pivnum = top/2;
    int pivnuml = pivnum-1;
    int pivnumh = pivnum+1;
    string pivl = w[pivnuml];
    string pivh = w[pivnumh];
    unsigned int pivlenl = pivl.length();
    unsigned int pivlenh = pivh.length();

    int i = bot;
    int j = (top - 1);
    while(i < j) {
        if(i < pivnuml) {
            if(w[i].length() < pivlenl) {
                i++;
            } else {
                swap(w[i], pivl);
                i++;
            }
        } i++;
        if(j > pivnumh) {
            if(w[j].length() > pivlenh) {
                j--;
            } else {
                swap(w[j], pivh);
                j--;
            }
        } j--;
    }
    if(top/2 != 1) {
        sorter(w, pivnuml, bot);
        sorter(w, top, pivnumh);
    }
    for(int k = 0; k < top; k++) {
        cout << w[k] << endl;
    }
}

void printer(int d) {
    //nothing for now
}














/*
 * Stuff said in lab:
 *
 * Valgrind has another thing called Valgrind Function Profiler
 * If possible, take things from O(n^2) to O(n)
 * Amdal's Law: The speedup gained from making an adjustment to a single block of execution/hardware is bounded by the impact it had to begin with.
 *              (The thing that has 95% of your runtime can only boost speed by that much...kinda)
 *              Eliminate cout and cin for optimal speed
 *
 *              From the core, reading from cache is fastest.
 *              takes 10ns to read from cache, 100ns from RAM, 10ms from storage. 10 seconds of cache is like 12 days of storage.
 *
 *              Eliminate unnecessary file-reads.  Those come from storage.
 *              Find way to put things into memory.  Also allocate your memory beforehand.
 *
 *              time ./sorter command args
 *
 *
 *              Don't push these to github.  Add datafiles to git-ignore
 *                  Navigate to the sprint file, do the
 *                  ll
 *
 *
 *10/4/2018
 *      Ways to speed things up
 *      Buckets:
 *          A bunch of subdivided parts of your dataset.
 *
 *              Think:
 *              A bunch of arrays pointing to other arrays (or like, one array of pointers that each point to an array of words which are the same length)
 *
 *      So have a bucket for each word length.
 *      Then since you have alphabetization, they should be alphabetizing.
 *      So you read the entire thing, then you bucket, then you sort by alphabetization
 *
 *
 *      Radix sort
 *          So let's say you are sorting with %10.  and you have a 48.  The 8 is the LSD (least significant index)
 *          Then you order them based on remainders.
 *          Then you do it again, but based on the element in the 10s position. (so %100)
 *
 *      It'll look something like:
 *
 *
 *  func radix(vect<string> &bucket, int size) {
 *
 *      int numchars = bucket[0].length();
 *      Vect<string> arr1(numchars);
 *      Vect<string> arr2(numchars);
 *
 *          //for char[size-1]
 *      for(i = 0; i < bucket.size(); i++) {
 *          arr2[idxForChar(bucket[i][numchars-1]).push(bucket[i];
 *      }
 *      Vect<string> *srcArr, *destArr;
 *      for(i = numchars - 1..0) {
 *          if(i%2 == 0) {
 *              srcArr = arr1;
 *              destArr = arr2;
 *          } else {
 *              srcArr = arr2;
 *              destArr = arr1;
 *          }
 *          for(j = 0; j < numchars; j++) {
 *              destArr[j].reset();
 *          }
 *          for(j = 0; j < numchars; j++) {
 *              for(k = 0; k < srcArr[j].size(); k++) {
 *                  destArr[&srcArr[j][k][i]].push(srcArr[j][k]);
 *              }
 *          }
 *      }
 *  }
 *  int idxForChar(char c) {
 *      if( 'A' < = c && c <= 'Z')
 *          return (c-'A');
 *      else if('a' <= c && c <= 'z')
 *          return (26 + c - 'a');
 *  }
 *
 *
 *
 * --------------------------------------
 * Ideas for the sorting alg that I can look back at later
 *
 * ..................................
 *     while(i < j) {
        if((j-i) <= 1) {
            break;
        } else if(i == pivnum) {
            sorter(w, i, bot);
        } else if(j == pivnum) {
            sorter(w, top, j);
        } else {
            if(w[i].length() < pivlenl) {
                i++;
            } else {
                swap(w[i], pivl);
                i++;
            }
            if(w[j].length() > pivlenh) {
                j--;
            } else {
                swap(w[j], pivh);
                j--;
            }
        }
    }
    ...............................................
 */
