//============================================================================
// Name        : move.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class HasPtr
{
public:
	// Default constructor
	HasPtr() { ptr = nullptr; cout << "HasPtr()" << endl; }
	//Copy constructor
	HasPtr(const HasPtr& rhs) { ptr = new string(*(rhs.ptr)); cout << "HasPtr(HasPtr&)" << endl; }
	//Custom constructor
	HasPtr(string* pVal):ptr(pVal) { cout << "HasPtr(string*)" << endl; }
	// Move constructor
	HasPtr(HasPtr&& rhs) noexcept { ptr = rhs.ptr; rhs.ptr = nullptr; cout << "HasPtr(HasPtr&&)" << endl; }

	HasPtr& operator=(HasPtr& rhs) {
		if(ptr != nullptr) delete ptr;
		ptr = new string(*(rhs.ptr));
		cout << "operator=(HasPtr&)" << endl;
		return (*this);
	}
	HasPtr& operator=(HasPtr&& rhs) {
		if(ptr != nullptr) delete ptr;
		ptr = rhs.ptr;
		rhs.ptr = nullptr;
		cout << "operator=(HasPtr&&)" << endl;
		return (*this);
	}

	~HasPtr() { if(ptr != nullptr) delete ptr; cout << "~HasPtr()" << endl; }
	void set(string* p) { if (ptr != nullptr) delete ptr; ptr=p; }
private:
	string* ptr;
};

HasPtr foo(string s) {
	return HasPtr(new string(s));
}


int main() {
	int i = 4;
	int &r = i;
	i++;
	int &&rval = i + 4;

	cout << "i = " << i << endl;
	cout << "r = " << r << endl;
	cout << "rval = " << ++rval << endl;

	HasPtr a; a.set(new string("1st Elem"));
	HasPtr b(a);
	HasPtr c = b;
	HasPtr d(new string("2nd Elem"));
	c = d;
	cout << "<--->" << endl;
	d = foo("3rd Elem");
	cout << "<--->" << endl;
	HasPtr e(foo("4th Elem"));

	cout << "<----Vector Test--->" << endl;
	vector<HasPtr> vec;
	vec.push_back(a);
	cout << "<------->" << endl;
	vec.push_back(b);
	cout << "<------->" << endl;
	vec.push_back(c);
	cout << "<------->" << endl;
	vec.push_back(d);
	cout << "<------->" << endl;
	return 0;
}
