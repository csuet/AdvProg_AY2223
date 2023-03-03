/*
	bài này mục đích là dùng thuật toán đơn giản(ko tối ưu) để tự động đoán từ trong hangman thay vì tự đoán như xưa
	máy 1 sẽ cho biết độ dài xâu kết quả , máy 2 lọc ra danh sách các từ tiềm năng có thể làm kết quả
	sau đó máy 2 sẽ đếm số lần xuất hiện các kí tự trong danh sách tiềm năng đó và chọn ra thằng xuất hiện nhiều nhất để đoán
	sau khi đoán và nhận về xâu kết quả (xâu mã hóa đc upd nếu đúng) của máy 1 , máy 2 sẽ lọc dần danh sách các từ tiềm năng
	cứ lọc dần dần như thế cho đến khi đúng hoặc thua khi vượt quá số lượt cho phép
*/
#include "simpleai.h"
#include<bits/stdc++.h>
using namespace std;
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
	for(string i : vocabulary) if(int(i.size()) == wordLen) answer.push_back(i);
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
    /// mex ( set<char> )
	/// chọn ra kí tự nhỏ nhất không xuất hiện trong tập kí tự đã chọn
    char answer;
    //Write your code here
	for(char i = 'a';i  <= 'z'; i ++ ) if(selectedChars.find(i) == selectedChars.end()) {
        answer = i ;
        break;
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
	/// đếm số lần xuất hiện các kí tự trong vector<string>
    map<char, int> answer;
    //Write your code here
    for(string i : candidateWords) for(char j : i) answer[j] ++ ;
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
	/// chọn ra kí tự xuất hiện nhiều nhất trong map mà nằm ngoài tập kí tự đã chọn
    char answer;
    //Write your code here
    int d = 0  ;
    for(char i = 'a';i <= 'z';i ++) if(selectedChars.find(i) == selectedChars.end()) {
        auto it = occurrences.find(i);
        if(it->second > d) {
            d = it->second;
            answer = i;
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
	/// dùng các hàm trên để tìm kí tự tiếp theo để đoán , ko tối ưu nhma dùng tạm thuật này
    char answer;
    //Write your code here
    map<char, int> m = countOccurrences(candidateWords);
    answer = findMostFrequentChar(m, selectedChars);
    return answer;
}

string getWordMask(char nextChar)
{
	/// đoán rồi nhận lại string của máy , string sau khi update mỗi lần đoán kí tự trong hangman
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
	/// kí tự đúng nếu xuất hiện trong mask , bởi vì nếu kí tự đúng thì máy sẽ update nó ( tương tự trong hangman )
    bool answer = 0;
    //Write your code here
    for(char i : mask) if(i == ch) answer = 1;
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
	/// kiểm tra xem xâu đã update hết chưa , để xem còn có thể chơi tiếp ko
     bool answer = 1;
    //Write your code here
    for(char i : mask) answer &= ((i >= 'a') && (i <= 'z'));
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
	///kiểm tra xem xâu này có thể là xâu kết quả ko
    bool answer = 1;
    //Write your code here
    for(int i = 0;i < int(word.size());i ++)
        if((mask[i] >= 'a')  && (mask[i] <= 'z') && (mask[i] != word[i]))
            answer = 0 , i = int(word.size()) ;
    return answer;
}

/***
    Args:
        mask (string): The response mask by the player
        words (vector<string>): The candidate words
        ch (char): The predicted character by the AI
    Returns:
        answer (bool) : a list of word which satisfy the mask and the predicted character
        Examples: input words: (good,boot,hood,...)
                  input mask: -ood
                  predicted char: d
                  Return: good,hood
***/
vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch)
{
	///lọc ra danh sách từ tiềm năng có thể là xâu kết quả
    vector<string> answer;
    //Write your code here
    for(string i : words) if(wordConformToMask(i , mask, ch))
        answer.push_back(i);
    return answer;
}

