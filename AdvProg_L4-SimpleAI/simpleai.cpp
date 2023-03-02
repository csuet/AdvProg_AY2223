#include "simpleai.h"

int readMaxGuess()
{
    int maxGuess;
    cout << endl
         << "Enter the number of incorrect guesses: ";
    cin >> maxGuess;
    return maxGuess;
}

int readWordLen()
{
    int wordLen;
    cout << endl
         << "Enter the number characters of your secret word: ";
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
vector<string> filterWordsByLen(int wordLen, const vector<string> &vocabulary)
{
    vector<string> answer;
    for (auto &s : vocabulary)
        if (s.size() == wordLen)
            answer.push_back(s);
    return answer;
}

/***
    Args:
        selectedChars (set<char>): The predicted characters
    Returns:
        answer (char) : The next character given the provided word is not in the vocabulary
***/

char nextCharWhenWordIsNotInDictionary(const set<char> &selectedChars)
{
    char answer;
    // Write your code here
    return answer;
}

/***
    Args:
        candidateWords (vector<string>): The candidate words for the current given string
    Returns:
        answer (map) : The map which count the occurences of character in the set of candidate words
***/

map<char, int> countOccurrences(const vector<string> &candidateWords)
{
    map<char, int> answer;
    for (string s : candidateWords)
        for (char c : s)
        {
            if (answer.find(c) == answer.end())
                answer[c] = 0;
            ++answer[c];
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

char findMostFrequentChar(const map<char, int> &occurrences, const set<char> &selectedChars)
{
    char answer;
    int m = 0;

    for (char s : selectedChars)
    {
        auto it = occurrences.find(s);
        if (it != occurrences.end())
        {
            int cnt = it->second;
            if (cnt > m)
            {
                answer = s;
                m = cnt;
            }
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

char findBestChar(const vector<string> &candidateWords, const set<char> &selectedChars)
{
    char answer;
    set<char> outside;

    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (selectedChars.find(c) == selectedChars.end())
            outside.insert(c);
    }
    answer = findMostFrequentChar(countOccurrences(candidateWords), outside);
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

bool isCorrectChar(char ch, const string &mask)
{
    for (char c : mask)
        if (c == ch)
            return true;
    return false;
}

/***
    Args:
        mask (string): The response mask by the player
    Returns:
        answer (bool) : return False if the provided mask is not a whole word, True otherwise
        (Example: -False: g__d
                  -True:  good)
***/
bool isWholeWord(const string &mask)
{
    for (char c : mask)
    {
        if (c == '-')
            return false;
    }
    return true;
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
bool wordConformToMask(const string &word, const string &mask, char ch)
{
    for (int i = 0; i < word.length(); ++i)
    {
        if (mask[i] != '_' && mask[i] != word[i])
            return false;
    }
    set<char> s;
    for (char c : word)
        s.insert(c);

    return s.find(ch) != s.end();
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
vector<string> filterWordsByMask(const vector<string> &words, const string &mask, char ch)
{
    vector<string> answer;
    for (string i : words)
    {
        if (wordConformToMask(i, mask, ch))
        {
            answer.push_back(i);
        }
    }
    return answer;
}