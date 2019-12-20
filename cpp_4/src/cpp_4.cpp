//============================================================================
// Name        : cpp_4.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
using namespace std;

int x = 0;

class mem {
public:
	mem(int i):no(i) { cout << "(MEM"<< no <<"++)"; }
	~mem() { cout << "(mem" << no << "--)"; }
private:
	int no;
};
class A {
public:
	A(int i):no(i) {
		cout << "A";
		temp = new mem(no);
		if(x++ == 0)
			throw exception();
	}
	~A() {
		delete temp;
		cout << "a";
	}
private:
	int no;
	mem *temp;
};
class B {
public:
	B(int i):a(i) { cout << "B"; }
	~B() { cout << "b"; }
	A a;
};



void foo(int i) { static B b(i); }

int main() {
	//This code creates a memory leak
	//Allocated memory was never freed
	{
		try {
			foo(1);
		}
		catch (exception &e)
		{
			cout << "c";
			foo(2);
		}
	}
	cout << endl;
	return 0;
}
// AcABba

