/*
 * RandomSubstitutionCipher.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: sidd
 */
#ifndef RANDOMSUBSTITUTIONCIPHER_H_
	#include "RandomSubstitutionCipher.h"
#endif
#include <string>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>

RandomSubstitutionCipher::RandomSubstitutionCipher()
{
	cout << "RandomSubstitutionCipher" << endl;
	pair<map<char,char>::iterator, bool> ret;
	int usedChar[26] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6};
	int i;
	char key, value;
	srand (time(NULL));
	for(i = 0; i < (26/2); i++)
	{
		int n = 0;
		key = (char)('a'+i);
		do
		{
			value = (char)('a' + (int)(rand() % 26));
			ret = decodingTable.insert(pair<char,char> (value,key));
			n++;
		} while(ret.second != true);
		encodingTable.insert(pair<char,char> (key,value));
		usedChar[(int)(value-'a')] = 0;
		//cout << "[ " << key << " : " << value << " ] in " << n << " attempts" << endl;
		/*
		for(int j = 0; j < 26; j++)
			cout << ((usedChar[j]>0)?1:0) << " ";
		cout << endl;
		for(int j = 0; j < 26; j++)
			cout << (char)('a'+j) << " ";
		cout << endl;
		*/
	}
	for(int j = 26-1; i < 26; i++, j--)
	{
		key = (char)('a'+i);
		while(usedChar[j] == 0)
			j--;
		value = (char)('a' + j);
		decodingTable.insert(pair<char,char> (value,key));
		encodingTable.insert(pair<char,char> (key,value));
		//cout << "[ " << key << " : " << value << "]" << endl;
	}
	//cout << "encodingTable size: " << encodingTable.size() << endl;
	//cout << "decodingTable size: " << decodingTable.size() << endl;
}

void RandomSubstitutionCipher::encode(string &sInput, string &sOutput)
{
	for (auto it = sInput.begin(); it != sInput.end(); ++it)
		if('a' <= *it && *it <= 'z')
			sOutput += encodingTable[*it];
		else
			sOutput += *it;
}

void RandomSubstitutionCipher::decode(string &sInput, string &sOutput)
{
	for (auto it = sInput.begin(); it != sInput.end(); ++it)
		if('a' <= *it && *it <= 'z')
			sOutput += decodingTable[*it];
		else
			sOutput += *it;
}

