/*
 * WordStatistics.cpp
 *
 *  Created on: Sep 16, 2017
 *      Author: sidd
 */

#ifndef WORDSTATISTICS_H_
	#include "WordStatistics.h"
#endif

#include <cassert>
#include <sstream>
using namespace std;


WordStatistics::WordStatistics(string &line):aLine_(line)//, isInitialized_(false)
{
	istringstream stm(aLine_);
	char sep = ' ';
	string token;
	while( getline( stm, token, sep ) ) tokenizedString_.push_back(token);
}


vector<string>& WordStatistics::getTokenizedString()
{
	return tokenizedString_;
}
