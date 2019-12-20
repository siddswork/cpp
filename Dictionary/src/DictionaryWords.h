/*
 * DictionaryWords.h
 *
 *  Created on: Sep 12, 2017
 *      Author: sidd
 */

#ifndef DICTIONARYWORDS_H_
#define DICTIONARYWORDS_H_

#include <list>
#include <string>
using namespace std;

#define MAX_WORD_LENGTH 50

class CharTrieNode;

class DictionaryWords
{
public:
	DictionaryWords(string filePath);
	~DictionaryWords();
	void load();
	bool getIsSet();
	void printAllWords();
	bool findWordsOfSize(int N, list<string>& wordsFound);
protected:
	bool addWord(char* word);

private:
	string filePath_;
	bool isSet_;
	CharTrieNode* root_;
	int lengthOfBiggestWord_;
	int noOfWords_;
	int noOfWordsOfLength_[MAX_WORD_LENGTH];
};

#endif /* DICTIONARYWORDS_H_ */
