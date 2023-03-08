#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <fstream>
#include "simpleai.h"
#include "util.h"
#include <string>

using std::string, std::ifstream;
using namespace std;



struct TestStruct
{
    std::string testName;
    bool result;
    bool expected;
    std::string errorMsg;
};

bool verifyGenerateRandomNumber(const int min, const int max) {
    int myAnswer = generateRandomNumber(min, max);
    return (myAnswer >= min && myAnswer <= max);
}

bool verifyIsCharInWord(const char ch, const string& word){
    return isCharInWord(ch, word);
}


bool verifyFilterWordsByLen(int wordLen, const vector<string>& vocabulary, vector<string> answer){
    vector<string> myAnswer = filterWordsByLen(wordLen, vocabulary);
    return myAnswer == answer;
}

bool verifyFilterWordsByMask(const vector<string>& words, const string& mask, char ch, vector<string> answer){
    vector<string> myAnswer  = filterWordsByMask(words,mask,ch);
    return myAnswer == answer;
}

bool verifyFindBestChar(const vector<string>& candidateWords, const set<char>& selectedChars, char answer){
    char myAnswer = findBestChar(candidateWords, selectedChars);
    return myAnswer == answer;
}
bool GetWordMask(char nextChar, string answer){
    //myAnswer = getWordMask(nextChar);
    //return myAnswer == answer;
    return true;
}
bool verifyIsCorrectChar(char ch, const string& mask, bool answer){
    bool myAnswer = isCorrectChar(ch,mask);
    return myAnswer == answer;
}

bool verifyIsWholeWord(const string& mask, bool answer){
    bool myAnswer = isWholeWord(mask);
    return myAnswer == answer;
}


void runTestLoop(TestStruct testCases[], int testSize){
    for (int i = 0; i< testSize; i++){
        std::cout << testCases[i].testName + ": ";
        if (testCases[i].result == testCases[i].expected)
        {
            std::cout << "PASSED!";
        }
        else
        {
            std::cout << "FAILED!\n";
            std::cout << testCases[i].errorMsg;
            exit(1);
        }
    }
}

class Test : public CPPUNIT_NS::TestCase
{
    CPPUNIT_TEST_SUITE(Test);
    CPPUNIT_TEST(testGenerateRandomNumber);
    CPPUNIT_TEST(testIsCharInWord);
    CPPUNIT_TEST(testFindBestChar);
    CPPUNIT_TEST(testIsWholeWord);
    CPPUNIT_TEST(testVerifyIsCorrectChar);
    CPPUNIT_TEST(testFilterWordsByLen);
    CPPUNIT_TEST(testFilterWordsByMask);
    CPPUNIT_TEST_SUITE_END();

    public:
      void setUp(void) {}
      void tearDown(void) {}

    protected:
      void testGenerateRandomNumber(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkGenerateRandomNumber test] ";
        TestStruct checkGenerateRandomNumber[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyGenerateRandomNumber(0, 10), 
                true,
                "Should return an integer number between 0 and 10\n"
            },
            {
                sharedName + "test normal 2", 
                verifyGenerateRandomNumber(15, 50), 
                true,
                "Should return an integer number between 15 and 50\n"
            },
            {
                sharedName + "test normal 3", 
                verifyGenerateRandomNumber(1, 100), 
                true,
                "Should return an integer number between 1 and 100\n"
            },
            {
                sharedName + "test normal 4", 
                verifyGenerateRandomNumber(1003, 2022), 
                true,
                "Should return an integer number between 1003 and 2022\n"
            },
            {
                sharedName + "test normal 5", 
                verifyGenerateRandomNumber(10, 10), 
                true,
                "Should return an integer number between 10 and 10\n"
            },
        };
        runTestLoop(checkGenerateRandomNumber, testSize);
      }

      void testIsCharInWord(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkIsCharInWord test] ";
        TestStruct checkIsCharInWord[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyIsCharInWord('a', "dad"), 
                true,
                "Character 'a' exists in word dad. Should return true\n"
            },
            {
                sharedName + "test normal 2", 
                verifyIsCharInWord('a', "mom"), 
                false,
                "Character 'a' doesn't exist in word mom. Should return false\n"
            },
            {
                sharedName + "test normal 3", 
                verifyIsCharInWord('g', "strange"), 
                true,
                "Character 'g' exists in word strange. Should return true\n"
            },
            {
                sharedName + "test normal 4", 
                verifyIsCharInWord('m', "mommy"), 
                true,
                "Character 'm' exists in word mommy. Should return true\n"
            },
            {
                sharedName + "test normal 5", 
                verifyIsCharInWord('b', "animal"), 
                false,
                "Character 'b' doesn't exist in word animal. Should return false\n"
            },
        };
        runTestLoop(checkIsCharInWord, testSize);
      }

      
    void testFilterWordsByLen(void) {
        string wordFilePath = "data/hangman_dictionary.txt";
        vector<string> vocabulary = readWordListFromFile(wordFilePath);
        const int testSize = 5;
        int wordLen_arr[testSize];
        std::string sharedName = "\n[checkFilterWordsByLen test] ";
        vector<vector<string>>  candidateWords_arr;
        for(int i=1;i <= testSize;i++){
            vector<string> newWords;
            string myText;
            int wordLen = 0;
            // Read from the text file
            ifstream MyReadFile("/test_data/test_filter_len"+std::to_string(i)+".txt");
            bool is_len = true;
            while (getline (MyReadFile, myText)) {
              // Output the text from the file
                if(is_len){
                    wordLen = std::stoi(myText);
                    is_len = false;
                }
                else{
                    newWords.push_back(myText);
                }
            }
            MyReadFile.close();
            wordLen_arr[i-1] = wordLen;
            candidateWords_arr.push_back(newWords);
        }
        TestStruct checkFilterWordsByLen[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyFilterWordsByLen(wordLen_arr[0], vocabulary, candidateWords_arr[0]), 
                true,
                "Test case failed, Please check the candidate words with respect to word length\n"
            },
            {
                sharedName + "test normal 2", 
                verifyFilterWordsByLen(wordLen_arr[1], vocabulary, candidateWords_arr[1]), 
                true,
                "Test case failed, Please check the candidate words with respect to word length\n"
            },
            {
                sharedName + "test normal 3", 
                verifyFilterWordsByLen(wordLen_arr[2], vocabulary, candidateWords_arr[2]), 
                true,
                "Test case failed, Please check the candidate words with respect to word length\n"
            },
            {
                sharedName + "test normal 4", 
                verifyFilterWordsByLen(wordLen_arr[3], vocabulary, candidateWords_arr[3]), 
                true,
                "Test case failed, Please check the candidate words with respect to word length\n"
            },
            {
                sharedName + "test normal 5", 
                verifyFilterWordsByLen(wordLen_arr[4], vocabulary, candidateWords_arr[4]), 
                true,
                "Test case failed, Please check the candidate words with respect to word length\n"
            },
            
        };
        runTestLoop(checkFilterWordsByLen, testSize);
      }

    void testFilterWordsByMask(void) {
        const int testSize = 5;
        std::string sharedName = "\n[checkFilterWordsByMask test] ";
        vector<vector<string>>  candidateWords_arr;
        vector<vector<string>>  outWords_arr;
        for(int i=1;i <= testSize;i++){
            vector<string> inpWords;
            vector<string> outWords;
            string myText;
            // Read from the text file
            ifstream MyReadFile("/test_data/filterbymask/input_filter_mask"+std::to_string(i)+".txt");
            ifstream OutReadFile("/test_data/filterbymask/output_filter_mask"+std::to_string(i)+".txt");
            bool is_len = true;
            while (getline (MyReadFile, myText)) {
                inpWords.push_back(myText);
            }
            while (getline (OutReadFile, myText)) {
                outWords.push_back(myText);
            }
            MyReadFile.close();
            candidateWords_arr.push_back(inpWords);
            outWords_arr.push_back(outWords);
        }
        TestStruct checkFilterWordsByMask[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyFilterWordsByMask(candidateWords_arr[0], "-a-", 'a', outWords_arr[0]), 
                true,
                "Test case failed, Please check the input candidate words with respect to output\n"
            },
            {
                sharedName + "test normal 2", 
                verifyFilterWordsByMask(candidateWords_arr[1], "pa-", 'p', outWords_arr[1]), 
                true,
                "Test case failed, Please check the input candidate words with respect to output\n"
            },
            {
                sharedName + "test normal 3", 
                verifyFilterWordsByMask(candidateWords_arr[2], "-ee-", 'e', outWords_arr[2]), 
                true,
                "Test case failed, Please check the input candidate words with respect to output\n"
            },
            {
                sharedName + "test normal 4", 
                verifyFilterWordsByMask(candidateWords_arr[3], "dee-", 'd', outWords_arr[3]), 
                true,
                "Test case failed, Please check the input candidate words with respect to output\n"
            },
            {
                sharedName + "test normal 5", 
                verifyFilterWordsByMask(candidateWords_arr[4], "-ear", 'r', outWords_arr[4]), 
                true,
                "Test case failed, Please check the input candidate words with respect to output\n"
            },
            
        };
        runTestLoop(checkFilterWordsByMask, testSize);
      }

    void testVerifyIsCorrectChar(void) {
        const int testSize = 5;
        std::string sharedName = "\n[testVerifyIsCorrectChar test] ";
        TestStruct checkVerifyIsCorrectChar[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyIsCorrectChar('o', "-o--", true), 
                true,
                "Character 'o' exists in string \"-o--\"\n"
            },
            {
                sharedName + "test normal 2", 
                verifyIsCorrectChar('w', "wo--", true), 
                true,
                "Character 'w' exists in string \"wo--\"\n"
            },
            {
                sharedName + "test normal 3", 
                verifyIsCorrectChar('r', "--r-", true), 
                true,
                "Character 'r' exists in string \"--r-\"\n"
            },
            {
                sharedName + "test normal 4", 
                verifyIsCorrectChar('t', "--rd", false), 
                true,
                "Character 't' not exists in string \"--rd\""
            },
            {
                sharedName + "test normal 5", 
                verifyIsCorrectChar('w', "---d", false), 
                true,
                "Character 'w' exists in string \"---d\"\n"
            },
        };
        runTestLoop(checkVerifyIsCorrectChar, testSize);
      } 

    void testIsWholeWord(void) {
        const int testSize = 5;
        std::string sharedName = "\n[testIsWholeWord test] ";
        TestStruct checkIsWholeWord[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyIsWholeWord("dad", true), 
                true,
                "dad is whold word\n"
            },
            {
                sharedName + "test normal 2", 
                verifyIsWholeWord("mo-", false), 
                true,
                "mo- is not whole word\n"
            },
            {
                sharedName + "test normal 3", 
                verifyIsWholeWord("strange", true), 
                true,
                "strange is whole word\n"
            },
            {
                sharedName + "test normal 4", 
                verifyIsWholeWord("mommy", true), 
                true,
                "mommy is whole word\n"
            },
            {
                sharedName + "test normal 5", 
                verifyIsWholeWord("anim--", false), 
                true,
                "aim-- is not whold word"
            },
        };
        runTestLoop(checkIsWholeWord, testSize);
    }

    void testFindBestChar(void){
        const int testSize = 11;
        vector<vector<string>> totalCandidateWords; 
        vector<set<char>> totalSelectedChars;
        vector<char> totalNextchar;

        string fileNameCandidateWords, fileNameSelectedChars, fileNameNextChar;

        for (int i = 1; i <= testSize; i++){

            fileNameCandidateWords = "test_data/find_best_char/candidate_words/" + to_string(i) + ".txt";
            fileNameSelectedChars = "test_data/find_best_char/selected_chars/" + to_string(i) + ".txt";
            fileNameNextChar = "test_data/find_best_char/next_char/" + to_string(i) + ".txt";


            ifstream fileCandidateWords(fileNameCandidateWords);
            ifstream fileSelectedChars(fileNameSelectedChars);
            ifstream fileNextChar(fileNameNextChar);
            vector<string> candidateWords;
            set<char> selectedChars;
            char nextChar;

            string tmpWord;
            char tmpChar;

            while(getline(fileCandidateWords, tmpWord)){
                candidateWords.push_back(tmpWord);
            }

            while(fileSelectedChars >> tmpChar){
                selectedChars.insert(tmpChar);
            }

            fileNextChar >> nextChar;

            fileCandidateWords.close();
            fileSelectedChars.close();
            fileNextChar.close();

            totalCandidateWords.push_back(candidateWords);
            totalSelectedChars.push_back(selectedChars);
            totalNextchar.push_back(nextChar);
        }
        
        std::string sharedName = "\n[testFindBestChar test] ";

		TestStruct checkFindBestChar[testSize]  = 
        {
            {
                sharedName + "test normal 1", 
                verifyFindBestChar(totalCandidateWords[0], totalSelectedChars[0], totalNextchar[0]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 2", 
                verifyFindBestChar(totalCandidateWords[1], totalSelectedChars[1], totalNextchar[1]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 3", 
                verifyFindBestChar(totalCandidateWords[2], totalSelectedChars[2], totalNextchar[2]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 4", 
                verifyFindBestChar(totalCandidateWords[3], totalSelectedChars[3], totalNextchar[3]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 5", 
                verifyFindBestChar(totalCandidateWords[4], totalSelectedChars[4], totalNextchar[4]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 6", 
                verifyFindBestChar(totalCandidateWords[5], totalSelectedChars[5], totalNextchar[5]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 7", 
                verifyFindBestChar(totalCandidateWords[6], totalSelectedChars[6], totalNextchar[6]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 8", 
                verifyFindBestChar(totalCandidateWords[7], totalSelectedChars[7], totalNextchar[7]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 9", 
                verifyFindBestChar(totalCandidateWords[8], totalSelectedChars[8], totalNextchar[8]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 10", 
                verifyFindBestChar(totalCandidateWords[9], totalSelectedChars[9], totalNextchar[9]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
            {
                sharedName + "test normal 11", 
                verifyFindBestChar(totalCandidateWords[10], totalSelectedChars[10], totalNextchar[10]), 
                true,
                "Please check the next char with respect to candidate words and selected chars\n"
            },
        };
        runTestLoop(checkFindBestChar, testSize);
    }

    void successTestExit(void) {
        std::cout << "all tests passed! \n";
        exit(0);
    }   
};  


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()
{
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}
