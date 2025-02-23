#ifndef FUNCTION_H
#define FUNCTION_H

#include "struct.h"
#include <vector>

void loadVocab(vector<Vocab>& words);
void loadUser(User& user);
void saveUser(const User& user);
void playGame(vector<Vocab>& words, User& user);

#endif