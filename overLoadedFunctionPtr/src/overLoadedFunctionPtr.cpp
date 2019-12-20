//============================================================================
// Name        : overLoadedFunctionPtr.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int f(int i) { return 1; }
int f(char c) { return 2; }

int main() {
	cout << "!!!overLoadedFunctionPtr!!!" << endl;

	int (*pf1)(char) = &f; // selects int f(double)
	int (*pf2)(int) = &f; // selects int f(int)

	cout << pf1('A') << endl;
	cout << pf2(1) << endl;

	cout << static_cast<int(*)(char)>(&f)('B');
	return 0;
}
