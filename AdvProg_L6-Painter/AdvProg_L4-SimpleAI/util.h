#ifndef GUARD_util
#define GUARD_util

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>


int generateRandomNumber(const int min, const int max);
bool isCharInWord(const char ch, const std::string& word);
std::vector<std::string> readWordListFromFile(const std::string& filePath);

#endif