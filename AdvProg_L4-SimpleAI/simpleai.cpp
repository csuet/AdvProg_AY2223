Skip to content
Search or jump to…
Pull requests
Issues
Codespaces
Marketplace
Explore
 
@vuniem131104 
GlowCheese
/
AdvProg_AY2223
Public
forked from csuet/AdvProg_AY2223
Fork your own copy of GlowCheese/AdvProg_AY2223
Code
Pull requests
Actions
Projects
Security
Insights
AdvProg_AY2223/AdvProg_L4-SimpleAI/simpleai.cpp

GlowCheese Bug fixed
…
Latest commit 670cfce 2 weeks ago
 History
 1 contributor
154 lines (133 sloc)  4 KB

#include "simpleai.h"
#include <algorithm>

using std::count;

int readMaxGuess()
{
    int maxGuess;
    cout << endl << "Enter the number of incorrect guesses: ";
    cin >> maxGuess;
    return maxGuess;
}

int readWordLen()
{
    int wordLen;
    cout << endl << "Enter the number characters of your secret word: ";
    cin >> wordLen;
    return wordLen;
    
}

/***
    Args:
        wordLen (int): The desired length of input word
        vocabulary (vector<string>): The vocabulary
    Returns:
        answer (vector<string>) : A set or word from the vocabulary where the number of character is equal to wordLen
***/
vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary)
{
    vector<string> answer;
    for (int i = 0; i < vocabulary.size(); i++) {
        if (vocabulary[i].size() == wordLen) {
            answer.push_back(vocabulary[i]);
        }
    }

    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most suitable character for prediction
***/

char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars)
{
    char answer = 0; int cnt_answer = -1;

    for (char current = 'a'; current <= 'z'; current++) {
        if (selectedChars.count(current)) continue;

        int cnt = 0;
        for (int i = 0; i < candidateWords.size(); i++) {
            cnt += count(candidateWords[i].begin(), candidateWords[i].end(), current);
        }

        if (cnt > cnt_answer) {
            cnt_answer = cnt;
            answer = current;
        }
    }

    return answer;
}

string getWordMask(char nextChar)
{
    string mask;
    cout << "The next char is: " << nextChar << endl;
    cout << "Please give me your answer: ";
    cin >> mask;
    return mask;
}

/***
    Args:
        ch (char): The predicted character by the AI
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the predicted character is the wrong one, True otherwise
***/

bool isCorrectChar(char ch, const string& mask)
{
    return mask.find(ch) != string::npos;
}

/***
    Args:
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the provided mask is not a whole word, True otherwise
        (Example: -False: g__d
                  -True:  good)
***/
bool isWholeWord(const string& mask)
{
    return mask.find('-') == string::npos;
}

/***
    This function should be used to support the filterWordsByMask function below
    Args:
        mask (string): The response mask by the player
        word (string): input word
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : return False if the provided mask and the given word is not in the same form.
        Example: - False: mask(-ood), char 'd' vs word(boot)
                 - True:  mask(-ood), char 'd' vs word(good)
***/
bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer = true;
    for (int i = 0; i < word.size(); i++) {
        if (mask[i] != '-') {
            answer &= mask[i] == word[i];
        } else {
            answer &= word[i] != ch;
        }
    }

    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
        words (vector<string>): The candidate words
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : a list of word which satisfiy the mask and the predicted character
        Examples: input words: (good,boot,hood,...)
                  input mask: -ood
                  predicted char: d
                  Return: good,hood
***/
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
    vector<string> answer;
    for (int i = 0; i < words.size(); i++) {
        if (wordConformToMask(words[i], mask, ch)) {
            answer.push_back(words[i]);
        }
    }

    return answer;
}
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
AdvProg_AY2223/simpleai.cpp at master · GlowCheese/AdvProg_AY2223