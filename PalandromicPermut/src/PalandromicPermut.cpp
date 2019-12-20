//============================================================================
// Name        : PalandromicPermut.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_set>
using namespace std;


void canFormPalindrome(const string& word)
{
	unordered_set<char> char_with_odd_frequency;
	for (char c : word)
	{
		if(char_with_odd_frequency.count(c))
		{
			char_with_odd_frequency.erase(c);
		}
		else
		{
			char_with_odd_frequency.insert(c);
		}
	}
	cout << word << ": ";
	cout << ((char_with_odd_frequency.size() <= 1)? "Can be Palindrome.": "Cannot be Palindrome.") << endl;
}

int main() {
	cout << "!!!PalandromicPermut!!!" << endl; // prints !!!PalandromicPermut!!!
	string word = "rotator";
	canFormPalindrome(word);
	word = "money";
	canFormPalindrome(word);
	word = "edified";
	canFormPalindrome(word);
	return 0;
}
