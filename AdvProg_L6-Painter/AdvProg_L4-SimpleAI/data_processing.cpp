#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

bool a2zWord(string word)
{
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] < 'a' || word[i] > 'z') return false;
    }
    return true;
}


/*
- Doc cac word
- Loai di nhung word chua cac ki tu khong phai tu a-z
- Ghi vao file moi
- Khong kiem tra loi chat che boi chi chay bang tay mot so lan
*/
void filterWords(string sourcePath, string targetPath)
{
    string word;
    ifstream sourceFile (sourcePath);
    if (!sourceFile.is_open()) {
        cout << "Error: Unable to open file " << sourcePath << endl;
        return;
    }

    ofstream targetFile (targetPath);
    if (!targetFile.is_open()) {
        sourceFile.close();    
        cout << "Error: Unable to open file " << targetPath << endl;
        return;
    }
    int cnt = 0, newCnt = 0;
    while ( sourceFile >> word ){
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (a2zWord(word)) {
            targetFile << word << '\n';
            ++newCnt;
        }
        if (++cnt % 1000 == 1) cout << "Count: " << cnt << endl;
    }
    cout << "Total: " << cnt << endl;
    cout << "Number of new words: " << newCnt << endl;
    sourceFile.close();    
    targetFile.close();
}


int main()
{
    string sourcePath = "data/words.txt";
    string targetPath = "data/hangman_wordlist.txt";
    filterWords(sourcePath, targetPath);
}