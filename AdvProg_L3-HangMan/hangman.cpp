#include <iostream>
#include "hangman.h"

#include <cctype>

using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;
using std::cout;

/***
    Args:
        min (int): left margin of a range
        max (int): right margin of a range
    Returns:
        number (int) : random number in range [min; max]
***/
int generateRandomNumber(const int min, const int max)
{
    // TODO: Return a random integer number between min and max
    return (rand() % (max - min + 1)+ min);
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

/***
    Args:
        ch (char): A character
        word (string): a word
    Returns:
        result (bool) : the character ch is in the word or not.
***/
bool isCharInWord(const char ch, const string& word)
{
    // TODO: return true if ch is in word else return false

    //Linear Search
    int lgnth = word.length();
    int count = 0;
    for (int i = 0; i < lgnth; i++)
        if (tolower(word[i]) == towlower(ch))
        {
            count++;
        }

    if (count == 0) return false;
    return true;
}

/***
    Args:
        wordList (vector<string>): A list of words
        index (int): an integer number
    Returns:
        answer (string) : the lowercase word is in the position index of wordList
***/
string chooseWordFromList(const vector<string>& wordList, int index) 
{
    // TODO: Return a lowercase word in the index position of the vector wordList.
    string answer;
    
    string temp = wordList[index];
    int lgnth = temp.length();

    for (int i = 0; i < lgnth; i++)
    {
        if (temp[i] >= 'A' && temp[i] <= 'Z') 
            answer += temp[i] + int('a' - 'A');
        if (temp[i] >= 'a' && temp[i] <= 'z') 
                answer += temp[i];
    }
    return answer;
}

/***
    Args:
        answerWord (string): a word that player needs to guess
    Returns:
        secretWord (string): answerWord in hidden form (form of ---)
***/
string generateHiddenCharacters(string answerWord){
    // TODO: Based on answerWord's length, generate hidden characters in form of "---"
    string secretWord;
    
    int lgnth = answerWord.length();

    for (int i=0; i < lgnth; i++)
        secretWord[i] = '-';

    return secretWord;
}

char getInputCharacter() {
    char ch;
    cin >> ch;
    return tolower(ch); 
}

/***
    Args:
        secretWord (string): secret word in hidden form
        ch (char): a charater
        word (string): the answer word
    Returns:
        void
***/
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    // TODO: Update the secret word if the character ch is in the answer word.
    //Loop to find the ch in secretWord
    //Size
    int legnth = secretWord.length();

    //loop
    for (int i = 0; i < legnth; i++)
        if (ch == word[i])
        {
            //If ch in secretWord, update secret word
            secretWord[i] = ch;
        }
        else
        {
            //No word not show up
            secretWord[i] = '-';
        }
}

/***
    Args:
        ch (char): a character
        chars (string): an array of characters
    Returns:
        void
***/
void updateEnteredChars(const char ch, string& chars){
    // TODO: append the character ch is in end of the text chars
    //Remember the space as the testcase
    chars += ch + ' ';
}

/***
    Args:
        incorrectGuess (int): a number that store the number of player's wrong guess
    Returns:
        void
***/
void updateIncorrectGuess(int& incorrectGuess){
    // TODO: increase the value of incorrectGuess by 1
    incorrectGuess++;
}

/***
    Args:
        ch (char): a character that player enter to console
        word (string): answer word that play needs to guess
        secretWord (string): answer word in hidden form
        correctChars (string): a string that stores correct inputs of player
        incorrectGuess (int): a number that stores the number of player's wrong guess
        incorrectChars (string): a string that stores incorrect inputs of player
    Returns:
        void
***/
void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars)
{
    /*** TODO
        If ch in word:
            update secretWord: call updateSecretWord() function
            update correctChars: call updateEnteredChars() function
        else:
            update incorrectGuess: call updateIncorrectGuess() function
            update incorrectChars: call updateEnteredChars() function
    ***/
   
   //If ch in word
   if (isCharInWord(ch, word))
   {
        //update secretWord
        updateSecretWord(secretWord, ch, word);

        //update correctChars
        updateEnteredChars(ch, correctChars);
   }
   else
   {
        //update incorrectGuess:
        updateIncorrectGuess(incorrectGuess);

        //update incorrectChars
        updateEnteredChars(ch, incorrectChars);
   }
}

