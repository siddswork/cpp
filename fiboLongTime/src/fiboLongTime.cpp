/*
 * fiboLongTime.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: sidd
 */
#include <iostream>
using namespace std;

long fiboLongTime(long i)
{
	if(i == 0) return 0;
	if(i == 1) return 1;
	return fiboLongTime(i-1) + fiboLongTime(i-2);
}

long fiboFast(long i, long* memo)
{
	if(i == 0 || i == 1) return i;
	cout << "memo:"<< *(memo+i) << endl;
	long retVal = *(memo+i);
	return retVal;
}

long fiboQuick(long i)
{
	long *memo = new long[i+1];
    long retVal = fiboFast(i, memo);
    return retVal;
}

int main()
{
	cout << "Print Fibonaci Series till 5 iteration:" << endl;
	cout << 1 << ":" << fiboLongTime(0) << endl;
	cout << 2 << ":" << fiboLongTime(1) << endl;
	cout << 3 << ":" << fiboLongTime(2) << endl;
	cout << 4 << ":" << fiboLongTime(3) << endl;
	cout << 5 << ":" << fiboLongTime(4) << endl;
	cout << "Print Fibonaci 40th Number:" << fiboLongTime(40) << endl;

	cout << "Print Fibonaci 40th Number:" << fiboQuick(40) << endl;
}

