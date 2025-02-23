#ifndef STRUCT_H
#define STRUCT_H

#include <string>
using namespace std;

struct Vocab {
    string english;
    string type;
    string vietnamese;
};

struct User {
    int score;
    int experience;
};

#endif