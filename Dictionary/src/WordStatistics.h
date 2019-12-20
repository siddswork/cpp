/*
 * WordStatistics.h
 *
 *  Created on: Sep 16, 2017
 *      Author: sidd
 */

#ifndef WORDSTATISTICS_H_
#define WORDSTATISTICS_H_

#include <vector>
#include <string>
using namespace std;

class WordStatistics
{
public:
	WordStatistics(string&);
	vector<string>& getTokenizedString();
private:
	string aLine_;
	//bool isInitialized_;
	vector<string> tokenizedString_;
	vector<string>::const_iterator tokenizerIter_;
};



#endif /* WORDSTATISTICS_H_ */
