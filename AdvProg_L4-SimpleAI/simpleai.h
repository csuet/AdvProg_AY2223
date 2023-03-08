#ifndef SIMPLEAI_H
#define SIMPLEAI_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
 
#include "util.h"

using namespace std;

int readMaxGuess();
int readWordLen();
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary);
char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars);
string getWordMask(char nextChar);
bool isCorrectChar(char ch, const string& mask);
bool isWholeWord(const string& mask);
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch);

const char MASK_CHAR = '-';
#endif