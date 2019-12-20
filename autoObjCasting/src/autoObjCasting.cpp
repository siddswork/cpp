//============================================================================
// Name        : autoObjCasting.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class StringType
{
public:
	StringType(): value("") {}
	StringType(const StringType& aStringType): value(aStringType.toString()) {}
	StringType(const char* aCharArray): value(aCharArray) {}

	string toString() const
	{
		return value;
	}
private:
	string value;
};


int main() {
	char str[] = "!!!Hello World!!!";
	StringType hello1("!!!Hello World!!!");
	StringType hello2(hello1);
	StringType hello3(str);
	cout << hello1.toString() << endl;
	cout << hello2.toString() << endl;
	cout << hello3.toString() << endl;
	return 0;
}
