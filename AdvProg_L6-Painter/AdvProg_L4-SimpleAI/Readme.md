# Lesson 4 - SimpleAI:
This is another lesson of the Advanced Programming course with the two following objectives: 

* i) Understand about a simple AI source code structure
* ii) Learn automated testing with Github Actions

You are required to implement several functions of HangMan game. They could be done via the instructions as follows:
* Step 1: Fork this repo to your own account
* Step 2: Clone the forked repo to your local via the command: git clone https://github.com/[YOUR_USERNAME]/AdvProg_L4-SimpleAI.git
* Step 3: Modify the following functions of the 'simpleai.cpp' file to complete the requirement.:
	* int generateRandomNumber(const int min, const int max);
	* bool isCharInWord(const char ch, const string& word);
	* vector<string> filterWordsByLen(int wordLen, const vector<string>& vocabulary);
	* char findBestChar(const vector<string>& candidateWords, const set<char>& selectedChars);
	* bool isCorrectChar(char ch, const string& mask);
	* bool isWholeWord(const string& mask);
	*  vector<string> filterWordsByMask(const vector<string>& words, const string& mask, char ch);
* Step 4: Commit & push the modified file using the command: *git commit -m "[Insert_your_own_message]" & git push origin main*
* Step 5: Create a pull request:
  - In the tab "Pull requests", click on "New pull request"
  - Set the pull request's title with the format as: [Your_student_ID]_[Your_full_name]
  - Click on "Create pull request" to submit
* Step 6: Check the automated testing workflow on your modified code using Github Actions. 

Hope you enjoy the lesson. 
