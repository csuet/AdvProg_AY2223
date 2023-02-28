#include <iostream>
#include "simpleai.h"

using namespace std;

void test(string &mask, vector <string> &filtered) {
	cout << "Testing with mask " << mask << endl;
	cout << "Filtered: ";
	for (auto word : filtered) {
		cout << word << ' ';
	}
	cout << endl << endl;

	// Testing filterWordsByMask function
	cout << "Testing filterWordsByMask function with char o" << endl;
	vector <string> oo = filterWordsByMask(filtered, mask, 'o');
	for (auto x : oo) {
		cout << x << ' ';
	}
	cout << endl << endl;

	// Testing is correct char
	cout << "Testing is correct char function with char o" << endl;
	cout << isCorrectChar('o', mask) << endl << endl;

	// Testing is wholeWord function
	cout << "Testing isWholeWord function" << endl;
	cout << isWholeWord(mask) << endl;
}

int main() {
	cout << "Hello test" << endl;

	// Testing filterWordsByLen function
	cout << "Testing filterWordsByLen function" << endl;
	vector <string> vocabulary = {"potato", "tomato", "ice", "scream", "cream", "power", "rainbow", "orange", "purple", "travel", "effect", "bottle"};
	vector <string> filtered = filterWordsByLen(6, vocabulary);
	for (auto x : filtered) {
		cout << x << ' ';
	}
	cout << endl;

	
	// Testing with different mask
	string mask1 = "-o----", mask2 = "-o---o", mask3 = "pruple";
	test(mask1, filtered);
	test(mask2, filtered);
	test(mask3, filtered);

	// Testing find next char function
	set <char> guessed;
	string emptyMask = "------";
	cout << "I am a tomato" << endl;
	cout << findBestChar(filtered, guessed) << endl;
}
