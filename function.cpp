#include "function.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

void loadVocab(vector<Vocab>& words) {
    ifstream file("VOCAB.TXT");
    if(!file) {
        cerr << "Cannot open file VOCAB.TXT!" << endl;
        exit(1);
    }
    
    string eng, type, viet;
    while(getline(file, eng) && getline(file, type) && getline(file, viet)) {
        words.push_back({eng, type, viet});
    }
    file.close();
}

void loadUser(User& user) {
    ifstream file("USER.BIN", ios::binary);
    if(file.read(reinterpret_cast<char*>(&user), sizeof(User))) {
        file.close();
    } else {
        user.score = 0;
        user.experience = 0;
    }
}

void saveUser(const User& user) {
    ofstream file("USER.BIN", ios::binary);
    file.write(reinterpret_cast<const char*>(&user), sizeof(User));
    file.close();
}

void playGame(vector<Vocab>& words, User& user) {
    srand(time(0));
    int correct = 0, total = 0;
    
    while(true) {
        int idx = rand() % words.size();
        bool askEnglish = rand() % 2;
        string answer;
        
        if(askEnglish) {
            cout << "Vietnamese meaning: " << words[idx].vietnamese << "\nEnter the English word: ";
        } else {
            cout << "English word: " << words[idx].english << "\nEnter the Vietnamese meaning: ";
        }
        
        getline(cin, answer);
        if(answer == "/exit") {
            cout << "Exiting game...\n";
            break;
        }
        
        if((askEnglish && stricmp(answer.c_str(), words[idx].english.c_str()) == 0) ||
           (!askEnglish && stricmp(answer.c_str(), words[idx].vietnamese.c_str()) == 0)) {
            cout << "Correct! +10 points\n";
            correct++;
            user.score += 10;
        } else {
            cout << "Wrong! The correct answer is: " << (askEnglish ? words[idx].english : words[idx].vietnamese) << "\n";
        }
        total++;
        user.experience += 5;
        saveUser(user);
    }
}