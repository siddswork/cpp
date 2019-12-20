/*
 * RandomSubstitutionCipher.h
 *
 *  Created on: Sep 13, 2017
 *      Author: sidd
 */

#ifndef RANDOMSUBSTITUTIONCIPHER_H_
#define RANDOMSUBSTITUTIONCIPHER_H_

#include <map>
using namespace std;

class RandomSubstitutionCipher
{
public:
	RandomSubstitutionCipher();
	void encode(std::string &sInput, std::string &sOutput);
	void decode(std::string &sInput, std::string &sOutput);
protected:
	map<char,char> encodingTable;
	map<char,char> decodingTable;
};

#endif /* RANDOMCIPHER_H_ */
