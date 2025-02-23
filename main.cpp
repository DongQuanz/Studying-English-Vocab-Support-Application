// Vocab Quiz
// Copyright (C) 2025 by Ngo Nguyen Dong Quan. All rights reserved.
// Version: 1.0.0
// Date: 2025-02-24
//
// This program is a vocabulary quiz game that helps users learn English words.
// It loads words from "VOCAB.TXT" and tracks user progress in "USER.BIN".
// Users can start the game by entering "/play" and exit using "/exit".
//
// Unauthorized copying of this file, via any medium, is strictly prohibited.
// Proprietary and confidential.

#include "function.h"
#include "instruction.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<Vocab> words;
    User user;
    
    loadVocab(words);
    loadUser(user);
    
    showInstructions();
    
    string command;
    while(true) {
        cout << "Enter '/play' to start or '/exit' to quit: ";
        getline(cin, command);
        if(command == "/play") {
            playGame(words, user);
        } else if(command == "/exit") {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid command! Please enter '/play' or '/exit'.\n";
        }
    }
    
    return 0;
}