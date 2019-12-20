//============================================================================
// Name        : roundNumTest.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	double dNum = 104.65;
	double delta = 0.000001
	long precision = pow10(6);

	for (int i = 0; i < 100; i ++)
	{
		double diff = dNum - 100;
		double roundNum = round(diff * precision) / precision;
		cout << "roundNum="<< setprecision(16) << roundNum << endl; // prints

		dNum += delta;
	}
	return 0;
}
