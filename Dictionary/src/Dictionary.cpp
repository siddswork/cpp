/*
 * Dictionary.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: sidd
 */

#include <iostream>
#include <string>
//#include <vector>
#include <list>

#ifndef DICTIONARYWORDS_H_
	#include "DictionaryWords.h"
#endif
#ifndef RANDOMSUBSTITUTIONCIPHER_H_
	#include "RandomSubstitutionCipher.h"
#endif
#ifndef WORDSTATISTICS_H_
	#include "WordStatistics.h"
#endif

using namespace std;

void printStrings(list<string>& stringlist)
{
	int size = stringlist.size();
	cout << ">>" << size << " words [";
	for(list<string>::const_iterator it = stringlist.begin(); it !=  stringlist.end(); it++)
	{
		cout << " " << (*it);
	}
	cout << " ]" << endl;
}

void filterWordsByPosition(int pos, char ch, list<string>& input, list<string>& filterResult)
{
	for(list<string>::const_iterator it = input.begin();it != input.end(); it++)
	{
		if(pos <= (*it).size() && (*it).at(pos-1) == ch)
		{
			filterResult.push_back((*it));
		}
	}
}
// Wrong method looping over and erasing element is special
void filterWordsByPosition(int pos, char ch, list<string>& input)
{
	list<string>::const_iterator it;
	for(it = input.begin(); it != input.end(); ++it)
	{
		if(pos <= (*it).size() && (*it).at(pos-1) != ch)
		{
			input.erase(it);
		}
	}
}

int main()
{
	string inputText = "this is a white horse for testing";
	string outputText = "";
	RandomSubstitutionCipher RandomCipher;

	cout << "Encode:" << endl;
	cout << "Input Text:" << endl <<  "\t" << inputText << endl;
	RandomCipher.encode(inputText, outputText);
	cout << "Output Text:" << endl <<  "\t" << outputText << endl;

	WordStatistics cryptoWordStats(outputText);
	cout << "Tokenized crypto words:" << endl;
	for(auto it = cryptoWordStats.getTokenizedString().begin(); it != cryptoWordStats.getTokenizedString().end(); ++it)
	{
		cout << *it << endl;
	}
	inputText = outputText;
	outputText = "";
	cout << "Decode:" << endl;
	cout << "Input Text:" << endl <<  "\t" << inputText << endl;
	RandomCipher.decode(inputText, outputText);
	cout << "Output Text:" << endl <<  "\t" << outputText << endl;

	string filePath = "/Users/sidd/dev/cpp/workspace/Dictionary/Resources/words.txt";
	//string filePath = "/Users/sidd/dev/cpp/workspace/Dictionary/Resources/smallTest.txt";
	list<string> result, filterResult, result2;
	list<string>::iterator it;

	DictionaryWords myDictionary(filePath);
	myDictionary.load();
	//myDictionary.printAllWords();
	//return 0;
	cout << "Dictionary is ready for use? " << (myDictionary.getIsSet()?"TRUE":"FALSE") << endl;

	cout << "All 7 letter words starting with f:" << endl;
	myDictionary.findWordsOfSize(7, result);
	list<string> filter;
	filterWordsByPosition(1, 'f', result, filter);
	printStrings(filter);

	cout << "All 7 letter words having 4th and 6th char same:" << endl;
	for (char ch='a'; ch <= 'z'; ch++)
	{
		list<string> filter2;
		cout << "Having " << (char)ch << ":";
		filterWordsByPosition(4, ch, filter, filter2);
		filterWordsByPosition(6, ch, filter2);
		printStrings(filter2);
		it = filterResult.end();
		filterResult.insert(it, filter2.begin(), filter2.end());
	}

	printStrings(filterResult);
	filterWordsByPosition(7, 'r', filterResult);
	printStrings(filterResult);

	return 0;
	for (char ch='a'; ch <= 'z'; ch++)
	{
		list<string> filter;
		filterWordsByPosition(6, ch, filterResult, filter);
		filterWordsByPosition(7, ch, filter);
		cout << "Having double " << (char)ch << ":";
		printStrings(filter);
		it = result2.end();
		result2.insert(it, filter.begin(), filter.end());
	}
	printStrings(result2);

	{
		list<string> result, filter;
		myDictionary.findWordsOfSize(5, result);
		filterWordsByPosition(2, 'a', result, filter);
		filterWordsByPosition(4, 'a', filter);
		filterWordsByPosition(5, 'c', filter);
		printStrings(filter);
	}

	{
			list<string> result, filter;
			myDictionary.findWordsOfSize(5, result);
			filterWordsByPosition(3, 'n', result, filter);
			filterWordsByPosition(4, 'a', filter);
			filterWordsByPosition(5, 't', filter);
			printStrings(filter);
		}
	cout << "OR" << endl;
	{
			list<string> result, filter;
			myDictionary.findWordsOfSize(5, result);
			filterWordsByPosition(3, 'n', result, filter);
			filterWordsByPosition(4, 'a', filter);
			filterWordsByPosition(5, 'd', filter);
			printStrings(filter);
		}

	/*
	for (char ch='a'; ch <= 'z'; ch++)
	{
		list<string> filter;
		cout << "Having double " << (char)ch << ":";
		filterWordsByPosition(3, ch, result, filter);
		filterWordsByPosition(4, ch, filter);
		printStrings(filter);
	}*/
	/*printStrings(filterResult);
	cout << "Filtering above list where 1st char is k:" << endl;
	filterWordsByPosition(1, 'k', filterResult);
	printStrings(filterResult);
	cout << "Filtering above list where 3rd char is s:" << endl;
	filterWordsByPosition(3, 's', filterResult);
	printStrings(filterResult);*/
}


