#include <iostream>
#include "hangman.h"

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

int generateRandomNumber(const int min, const int max)
{
    srand(time(NULL)) ;
    int randomNum = rand() % (max - min + 1) + min ;
    return randomNum ;
}

vector<string> readWordListFromFile(const string& filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile (filePath);
    if (!wordFile.is_open()) {
        throw domain_error("Unable to open file");
    }

    //while ( getline (wordFile, word) ){  // Thong thuong doc tung line. 
                                           // Chuong trinh nay cung chay.
    while (wordFile >> word) {  // Nhung voi chuong trinh nay, doc tung word cung duoc
                                // Tuc ca 2 cach doc deu chay.
        wordList.push_back(word);
        //cout << word << '\n';
    }
    wordFile.close();

    return wordList;
}

bool isCharInWord(const char ch, const string& word)
{
    for(int i=0 ; i<word.length() ; i++)
    {
        if(tolower(word[i]) == tolower(ch))
        {
            return true;
        }
    }
    return false ;
}

string chooseWordFromList(const vector<string>& wordList, int index) 
{
    string answer = wordList[index] ;
    
    for(int i=0 ; i<answer.length() ; i++)
    {
        answer[i] = tolower(answer[i]) ;
    }
    return answer ;
}

string generateHiddenCharacters(string answerWord){
    string secretWord(answerWord.length(), '-') ;
    return secretWord;
}

char getInputCharacter() {
    char ch;
    cin >> ch;
    return tolower(ch); 
}

void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    for(int i=0 ; i<word.length() ; i++)
    {
        if(word[i] == ch)
        {
            secretWord[i] = ch ;
        }
    }
}

void updateEnteredChars(const char ch, string& chars){
    chars += tolower(ch) ;
}

void updateIncorrectGuess(int& incorrectGuess){
    incorrectGuess += 1 ;
}

void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars)
{

   if(isCharInWord(ch,word))
   {
        updateSecretWord(secretWord , ch , word) ;
        updateEnteredChars(ch , correctChars) ;
   }
   else
   {
        updateIncorrectGuess(incorrectGuess) ;
        updateEnteredChars(ch , incorrectChars) ;
   }
}

