#include <iostream>
#include "hangman.h"
using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

/***
    Args:
        min (int): lề trái của một phạm vi
        max (int): biênĐộBênPhảiCủaMộtPhạmVi
    Returns:
        number (int) : số ngẫu nhiên trong phạm vi [tối thiểu;Tối đa]
***/
int generateRandomNumber(const int min, const int max)
{
    // TODO: 
    int n;
    srand(time(NULL));
    n=rand()%(max-min+1)+min;
    return n;
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
        ch (char): Một nhân vật
        word (string): một từ
    Returns:
        result (bool) : Nhân vật Ch có trong từ hay không.
***/
bool isCharInWord(const char ch, const string& word)
{
    // TODO: trả về true nếu ch ở trong từ khác trả về false
    int i=0;
    while (word[i]!='\0')
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (ch==word[j])
        {
            return true;
        }
        
    }
    
    return false;
}

/***
    Args:
        wordList (vector<string>):Một danh sách các từ
        index (int): một số nguyên
    Returns:
        answer (string) :từ viết thường nằm trong chỉ số vị trí của danh sách từ
***/
string chooseWordFromList(const vector<string>& wordList, int index) 
{
    string answer = wordList[index];
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    return answer;
}


/***
    Args:
        answerWord (string): a word that player needs to guess
    Returns:
        secretWord (string): answerWord in hidden form (form of ---)
***/
string generateHiddenCharacters(string answerWord){
    string secretWord = "";
    for (int i = 0; i < answerWord.length(); i++) {
        secretWord += "-";
    }
    return secretWord;
}


char getInputCharacter() {
    char ch;
    cin >> ch;
    return tolower(ch); 
}

/***
    Args:
        secretWord (string): từ bí mật ở dạng ẩn
        ch (char): một nhân vật
        word (string): từ câu trả lời
    Returns:
        void
***/
void updateSecretWord(string& secretWord, const char ch, const string& word) {  
    for (size_t i = 0; i < word.length(); ++i) { 
        if (word[i] == ch) { 
        secretWord[i] = ch; 
        } 
    }
}
// } 

// void updateSecretWord(string& secretWord, const char ch, const string& word)
// {
//     for (int i = 0; i < word.size(); i++)
//     {
//         if (word[i]==ch)
//         {
//             Word[i]=ch;
//         }
        
    // }
    
    // TODO:Cập nhật từ bí mật nếu ký tự ch trong từ trả lời.
     //Update the secret word if the character ch is in the answer word.


/***
    Args:
        ch (char): một nhân vật
        chars (string): Một mảng các ký tự
    Returns:
        void
***/
void updateEnteredChars(const char ch, string& chars){
    // TODO: nối các ký tự ch là cuối của ký tự
    chars+=ch;
}

/***
    Args:
        incorrectGuess (int): một số lưu trữ số lượng phỏng đoán sai của người chơi
    Returns:
        void
***/
void updateIncorrectGuess(int& incorrectGuess){
    // TODO: Tăng giá trị không chính xác lên 1
    incorrectGuess++;
}

/***
    Args:
        ch (char): một nhân vật mà người chơi nhập vào bảng điều khiển
        word (string): Trả lời từ mà chơi cần phải đoán
        secretWord (string): Trả lời từ ở dạng ẩn
        correctChars (string): một chuỗi lưu trữ các đầu vào chính xác của người chơi
        incorrectGuess (int): một số lưu trữ số lượng phỏng đoán sai của người chơi
        incorrectChars (string): một chuỗi lưu trữ các đầu vào không chính xác của người chơi
    Returns:
        void
***/
void processData(const char ch, const string& word, 
                string& secretWord, 
                string& correctChars, 
                int& incorrectGuess, string& incorrectChars)
{
    for (int i = 0; i < word.size(); i++)
    {
        //if (word[i]==ch)
        if(isCharInWord(ch,word))
        {
            updateSecretWord(secretWord,ch,word);
            updateEnteredChars(ch,correctChars);
        }
        else
        {
            updateIncorrectGuess(incorrectGuess);
            updateEnteredChars(ch,incorrectChars);
        }
        
    }
        
    }        
    /*** TODO
        If ch in word:
            update secretWord: call updateSecretWord() function
            update correctChars: call updateEnteredChars() function
        else:
            update incorrectGuess: call updateIncorrectGuess() function
            update incorrectChars: call updateEnteredChars() function
    ***/


