//============================================================================
// Name        : cpp_1.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int getOne()
{
	return 1;
}

int main() {
	// PART 1
	const int buffSize = 512;  // ok: initialized at compile time
	// buffSize = 2;           // error: cannot assign to variable 'buffSize' with const-qualified type 'const int'
	const int i = getOne();    // ok: initialized at run time
	// const int j;            // error: default initialization of an object of const type 'const int'
	const int k = buffSize;    // ok: initialized at run time

	//Using references to constant
	const int ci = 1024;
	const int &r1 = ci;        // ok: both reference and underlying object are const
	// r1 = 42;                // error: r1 is a reference to const
	// int &r2 = ci;           // error: trying to drop constantness

	// Initialization and References to const
	int l = 42;
	const int &r3 = l; // we can bind a const int& to a plain int object
	const int &r4 = 42; // ok: r1 is a reference to const
	const int &r5 = r1 * 2; // ok: r3 is a reference to const
	// int &r6 = 2;        // error: r6 is a plain, non const reference
	l = 6;    // ok: l is not constant so l can be changed. This changes r3 as it is a reference
	//r3 = 7; // error: cannot assign as 'r3' is having const-qualified type 'const int &'

	// strange use of const reference
	double dval = 3.14;
	const int &ri = dval; // this is allowed, C++ internally binds it with temp variable,
						  // like 'const int temp = dval' and ri is reference of temp
	// int &rj = dval;    // but this is not allowed; non-const lvalue reference to type 'int'
						  // cannot bind to a value of unrelated type 'double'

	cout << "buffSize = " << buffSize << endl;
	cout << "i = " << i << endl;
	cout << "k = " << k << endl;
	cout << "r1 = " << r1 << endl;
	cout << "r3, r4, r5 = " << r3 << ", " << r4 << ", " << r5 << endl;
	cout << "dval, ri = " << dval << ", " << ri << endl;

	// PART 2
	// Pointers and const: pointers to constants
	{
		double pi = 3.14;
		const double cpi = 3.14;
		double *ptr = &pi;
		// double *ptr1 = &cpi;    // error: ptr1 is a plain pointer, cannot keep address of const variable
		const double *ptr2 = &cpi; // ok: const pointer to const varable
		const double *ptr3 = &pi;  // ok: address of regular variable can be stored in const pointer
		// *ptr3 = 3.0;            // error: cannot change value using const pointer "read-only variable is not assignable"
		ptr3 = &cpi;               // ok: Using const pointers one cannot change the data at address
								   //     but one can make it point to another address
		const int *p;              // ok: We can have uninitialized pointers to constant
		// int *p2 = ptr3;		   // error: not allowed as it is an attempt to remove constness
	}
	// const Pointers
	{
		int errNumb = 0;
		int *const curErr = &errNumb; // ok: curErr will always point to errNumb
		// curErr = &errNumb;         // error: It thinks that we are trying to change the address curErr is holding
		*curErr = 5;				  // ok: using curErr you can change the value at address
		const double pi = 3.14159;
		const double *const pip = &pi;// pip is a const pointer to a const object; nothing can be changed
		cout << "*curErr = " << *curErr << endl;
		// double *const p;			  // We cannot have uninitialized const pointers
	}

	/* NOTE:
	 * The term "top-level const" is used to indicate that the pointer itself is a const.
	 * 		eg.: int *const curErr = &errNumb
	 * The term "low-level const" is used to indicate that the pointer point to a const object
	 * 		eg.: const double *ptr2 = &cpi
	 */

	// String
	{
		string s1("ABCD"), word;
		cout << "sizeof(s1[0]) = " << sizeof(s1[0]) << " bytes" << endl;
		cout << "s1[0] = " << s1[0] << endl;
		for (auto &c : s1)    // this is called "Range-Based for" OR "Range for" statement
		{
			c = tolower(c);
			cout << c << " ";
		}
		cout << s1 << endl;
		while (cin >> word)
			cout << word << endl;
	}
	return 0;
}
