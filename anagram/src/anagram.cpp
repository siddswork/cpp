//============================================================================
// Name        : anagram.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void printStringVector(const vector<string>& list, string prefix = "")
{
	bool printInfix = false;
	cout << prefix;
	for (const string& s : list)
	{
		if (printInfix)
			cout << ", ";
		cout << s;
		printInfix = true;
	}
	cout << endl;
}

void findAnagrams(const vector<string>& listOfWords)
{
	unordered_map<string, vector<string>> hashOfAnagrams;
	for (const string& s : listOfWords)
	{
		string sortedString(s);
		sort(sortedString.begin(), sortedString.end());
		hashOfAnagrams[sortedString].emplace_back(s);
	}
	//Print Analgrams
	for (const auto& p : hashOfAnagrams)
	{
		if(p.second.size() >= 2)
		{
			printStringVector(p.second, "Anagram: ");
		}
	}
}

int main() {
	std::vector<string> listOfWords;
	listOfWords.emplace_back("algorithm");
	listOfWords.emplace_back("logarithm");
	listOfWords.emplace_back("debitcard");
	listOfWords.emplace_back("badcredit");
	listOfWords.emplace_back("elvis");
	listOfWords.emplace_back("lives");
	listOfWords.emplace_back("money");

	printStringVector(listOfWords, "Input: ");

	findAnagrams(listOfWords);
	return 0;
}
