/*
 + B0: Nạp danh sách từ vựng (vocabulary)
 + B1: Nhận vào số lần đoán tối đa N và độ dài từ phải đoán K. 
    Lọc danh sách từ vựng để chỉ chọn xem xét các từ có độ dài K.
    Danh sách các kí tự đã chọn ban đầu là rỗng.
 + B2: 
    Trong các từ đang xét, tìm kí tự xuất hiện nhiều nhất và không nằm trong các 
    kí tự đã chọn. Chọn kí tự này.
    Nhận vào kết quả trả đoán.
 + B3: 
    Nếu kết quả đoán đúng kí tự:
        Nếu đoán hết cả tử, sang B4 (thắng).
        Nếu chưa hết, lọc để giữ chỉ giữ lại xem xét từ vựng 
            với các từ có cả kí tự vừa đoán được tại vị trí được biêt; 
            Rồi quay lại B2. 
    Nếu đoán sai kí tự:
        Nếu hết số lần đoán, sang B4 (thua)
        Nếu chưa hết, tiếp tục đoán bằng cách quay lại B2
 + B4: Kết thúc
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "simpleai.h"
 
#include "util.h"

using namespace std;

void save_filter(int id, const vector<string>& words, const string& mask, char ch){
    string myText;
    if(id == 1){
        ofstream MyReadFile("input_filter_mask.txt");
        cout << ch << endl << mask << endl;
        for(auto i:words)
            MyReadFile << i << endl;
        MyReadFile.close();
    }
    else{
        ofstream MyReadFile("output_filter_mask.txt");
        for(auto i:words)
            MyReadFile << i << endl;
        MyReadFile.close();
    }
}

int main()
{
    // B0
    //string wordFilePath = "data/hangman_wordlist.txt";
    string wordFilePath = "data/hangman_dictionary.txt";
    vector<string> vocabulary = readWordListFromFile(wordFilePath);
    /*
    vector<string> vocabulary;
    vocabulary.push_back("hello");
    vocabulary.push_back("good");
    vocabulary.push_back("bad");
    vocabulary.push_back("world");
    vocabulary.push_back("nice");
    */
    
    // B1
    int maxGuess = readMaxGuess();
    int wordLen = readWordLen();

    vector<string> candidateWords = filterWordsByLen(wordLen, vocabulary);
    //save_filter(1, wordLen, candidateWords, "-", '-');
    set<char> selectedChars;
    int incorrectGuess = 0;
    string finalMessage = "";
    string mask(wordLen, MASK_CHAR);
    cout << "So your secret word looks like: " << mask << endl;

    //cout << "Max guess: " << incorrectGuess << " Word-len: " << wordLen << " Word num: " << candidateWords.size() << endl;
    
    while (true) {
        // B2

        char nextChar = findBestChar(candidateWords, selectedChars);

        if (nextChar == 0) {
            finalMessage =  "There is something wrong. I quit :|";
            break;
        }
        selectedChars.insert(nextChar);
        string responsedMask = getWordMask(nextChar);

        // B3
        cout << "nextChar: " << nextChar << endl;
        cout << "responsedMask: " << responsedMask << endl;
        cout << isCorrectChar(nextChar, responsedMask) << endl;
        if (isCorrectChar(nextChar, responsedMask)) {
            if (isWholeWord(responsedMask)) {
                finalMessage =  "It is easy :)";
                break;
            } else {
                cout << "out" <<endl;
                save_filter(1,candidateWords, responsedMask, nextChar);
                candidateWords = filterWordsByMask(candidateWords, responsedMask, nextChar);
                save_filter(0,candidateWords, responsedMask, nextChar);
            }
        } else {
            incorrectGuess += 1;        
            cout << "Incorrect guess count: " << incorrectGuess << endl;
        
            if (maxGuess <= incorrectGuess) {
                finalMessage = "Maybe, you should give me more times to guess :(";
                break;
            } else {
                // continue;
            }
        }
    }

    // B4
    cout << finalMessage << endl;
    return 0;
}
