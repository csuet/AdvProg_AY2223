#include "simpleai.h"

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
    //Write your code here
    for (const auto& word : vocabulary) {
        if (word.size() == wordLen) {
            answer.push_back(word);
        }
    }
    return answer;
}

/***
    Args:
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The next character given the provided word is not in the vocabulary
***/

char nextCharWhenWordIsNotInDictionary(const set<char>& selectedChars)
{
    char answer = 'a';
    while (selectedChars.count(answer) > 0) {
        answer++;
    }
    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string 
    Returns:
        answer (map) : The map which count the occurences of character in the set of candidate words
***/

map<char, int> countOccurrences(const vector<string>& candidateWords)
{
    map<char, int> answer;
    //Write your code here
    for (const auto& word : candidateWords) {
        for (char ch : word) {
            if (answer.find(ch) == answer.end()) {
                answer[ch] = 1;
            } else {
                answer[ch]++;
            }
        }
    }
    return answer;
}

/***
    Args:
        occurrences (map<char, int>): The map which count the occurences of character in the set of candidate words
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The most frequent character
***/

char findMostFrequentChar(const map<char, int>& occurrences, const set<char>& selectedChars)
{
    char answer;
    //Write your code here
    int maxx = 0;
    for( char x:selectedChars ){
        if( occurrences.at(x) > maxx ){
            maxx = occurrences.at(x);
            answer = x;
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
    //Write your code here
    char answer;
    vector<int> check(26, 0);
    for( char x:selectedChars ){
        check[x-'a'] = -1;
    }
    for( int i=0 ; i<candidateWords.size() ; i++){
        for( int j=0 ; j<candidateWords[i].size() ; j++){
            if( check[candidateWords[i][j]-'a'] >= 0 ) check[candidateWords[i][j]-'a']++;
        }
    }
    int maxi = 0;
    for( int i=0 ; i<26 ; i++){
        if( check[i]>maxi ){
            maxi = check[i];
            answer = i+ 'a';
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
    bool answer = false;
    //Write your code here
    for( int i=0 ; i<mask.size() ; i++){
        if( mask[i] == ch ) return true;
    }
    return answer;
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
    bool answer = true;
   //Write your code here
   for( int i=0 ; i<mask.size() ; i++){
       if( mask[i] == '_' || mask[i] == '-' ) return false;
   }
   return answer;
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
                 - True: mask(-ood), char 'd'  vs word(good)

***/
bool wordConformToMask(const string& word, const string& mask, char ch) 
{
    bool answer = true;
    //Write your code here
    for( int i=0 ; i<mask.size() ; i++){
        if( mask[i]=='-' || mask[i]=='_' ){
            if( word[i] == ch ) return false;
        }
        else if( mask[i] != word[i] ) return false;
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
    //Write your code here
    
    for( int i=0 ; i<words.size() ; i++){
        if( wordConformToMask( words[i], mask, ch) ) answer.push_back( words[i] );
    }
    return answer;
}
