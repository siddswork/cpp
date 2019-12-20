//============================================================================
// Name        : DestructorTest.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Basics in C++
//============================================================================

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

//------------PART 1 START------------------
class A
{
public:
	virtual void f() { cout << "A"; }
};

class B: public A
{
public:
	void f() { cout << "B"; }
};

class Base {
public:
	void f(int) { cout << "i"; }
};
class Derived: public Base {
public:
	void f(double) { cout << "d"; }
};

void g(A a) { a.f(); }
void h(A& a) { a.f(); }


void part1()
{
	B b;
	g(b); // A gets printed because of slicing, we did pass by value
	cout << endl;
	h(b); // B gets printed as we did a pass by reference
	cout << endl;
	Derived d;
	int i = 0;
	d.f(i);
	d.Base::f(i);
	// prints: di
	// Because the method f() is not virtual, method f() of Derived
	// overrides the method from Base. Call to f() using derived
	// will always invoke Derived class's method f(). To call Base
	// class's method f() we need to use d.Base::f(i) i.e. we need
	// to tell compiler explicitly.
	cout << endl;
}
//-------------PART 1 END--------------------

//------------PART 2 START------------------
class AA {
public:
    AA() { cout<< "AA|"; }
    AA(const AA& a) {
        cout << "AAcc|"; //'AA' copy constructor
    }
    virtual void run() const { cout << "I am an 'A'" << endl; }
};

// Derived class
class BB: public AA {
public:
    BB():AA() {cout<< "BB|"; }
    BB(const BB& a):AA(a) {
        cout << "BBcc|"; //'BB' copy constructor"
    }
    virtual void run() const { cout << "I am a 'B'" << endl; }
};
void i(const AA & a) {
    a.run();
}
void j(const AA a) {
    a.run();
}
void part2()
{
    // Call by reference
    i(BB());
    // prints: AA|BB|I am a 'B'
    // AA|BB comes out of the constructor when BB() is called
    // copy constructor is not called as it is pass by reference
    // Next output is from BB's run() method
    // Call by copy
    j(BB());
    // prints: AA|BB|AAcc|I am an 'A'
    // AA|BB comes out of the constructor
    // AA's copy constructor is called as it is pass by value
    //    and it need to create a new object AA from object of BB
    // the last output comes out of AA's run() method. Reason slicing.
    BB c; // print: AA|BB [out of constructor]
    cout << endl;
    BB d = c;
    // print: AAcc|BBcc| [BB's copy constructor]
    // copy constructor is being used as object d is getting constructed
    cout << endl;
    BB e( (BB()) );
    // print: AA|BB [BB's copy constructor].
    // C++ optimizes & constructs only 1 object instead of 2
    cout << endl;
    e = c;
    // no output as copy constructor is not being used
    // its not a construction of object but initialization
}
//-------------PART 2 END--------------------
//-------------PART 3 start------------------
int k()
{
	cout << "k"; return 1;
}
int l()
{
	cout << "l"; return 2;
}
int foo(int a, int b)
{
	cout << a << b;
	return b;
}
void bar(vector<int> v) { }

void part3()
{
	int i = 5;
	foo(k(), l());
	// prints: kl12
	// meaning the evaluation of function happens from left to right
	cout << endl;
	bar({k(), l()});
	// prints: kl
	// used of {} during initialization is a C++11 feature
	cout << endl;
	foo(++i, i++);
	//prints: 66
	cout << endl;
	i = 5;
	foo(i++, foo(++i, i++));
	//   5        7    7
	// prints: 7757
	// outer foo's i++ is evaluated 5 is passed to the function
	// and i become 6. Next inner foo's ++i is evaluated, i become 7
	// and 7 is passed. Lastly inner foo's i++ is evaluated, 7 is
	// passed to the function and i changes to 8. Inner foo() prints
	// 77 and returns 7. Outer foo() prints 57.
	cout << endl;
}
//-------------PART 3 END--------------------
//-------------PART 4 start------------------
class DA {
public:
	DA() { cout << "DA|"; }
	~DA() { cout << "da|"; }
};
class DB {
public:
	DB() { cout << "DB|"; }
	~DB() { cout << "db|"; }
};
class DC {
public:
	DC() { cout << "DC|"; }
	~DC() { cout << "dc|"; }
};

void part4()
{
	DA a;
	{
		DB b;
		DC c;
	}
	// prints: DA|DB|DC|dc|db|da
	// it maintains the sequence of creation,
	// as the objects are placed in stacks
	// in case object a was a global object, then too a
}
//-------------PART 4 END--------------------
//-------------PART 5 start------------------
int foobar(int& a, int &b)
{
	a = 3;
	b = 4;
	return a + b;
}
void part5()
{
	int a = 1;
	int b = 2;
	int c = foobar(a, a);
	cout << a << b << c << endl;
	// print: 428
}
//-------------PART 5 END--------------------
//-------------PART 6 start------------------
class EA {
public:
	EA() { cout << "ea"; }
	~EA() { cout << "EA"; }
};
class EB {
public:
	EB() { cout << "eb"; }
	~EB() { cout << "EB"; }
};
class EC {
public:
	EC() { cout << "ec"; }
	~EC() { cout << "EC"; }
	EB b;
	EA a;
};
void part6()
{
	{
		EC ec;
	}
	// print: ebeaecECEAEB
	cout << endl;
}
//-------------PART 6 END--------------------
//-------------PART 7 start------------------
int x = 0;
class FA {
public:
	FA() {
		cout<<'a';
		if(x++ == 0) {
			throw exception();
		}
	}
	~FA() {
		cout<<'A' << endl;
	}
};
class FB {
public:
	FB() { cout << 'b'; }
	~FB() { cout << 'B'; }
	FA a;
};
void fn() { static FB b; }
void part7()
{
	try {
		fn();
	}
	catch (exception &) {
		cout << 'c';
		fn();
	}
	// print: acabBA
}
//-------------PART 7 END--------------------
//-------------PART 8 start------------------
void part8()
{
    vector<int> ivec;
    cout << "Just after vector creation" << endl;
    cout<< "vector size: " << ivec.size() <<", vector capacity:" << ivec.capacity() << endl;
    ivec.push_back(1);
    cout << "After adding 1 element in vector" << endl;
    cout<< "vector size: " << ivec.size() <<", vector capacity:" << ivec.capacity() << endl;
    ivec.push_back(1); ivec.push_back(1); ivec.push_back(1);
    cout << "After adding 3 more elements in vector" << endl;
    cout<< "vector size: " << ivec.size() <<", vector capacity:" << ivec.capacity() << endl;
    cout << "Calling reserve(6)" << endl;
    ivec.reserve(6);
    cout<< "vector size: " << ivec.size() <<", vector capacity:" << ivec.capacity() << endl;
    ivec.push_back(1); ivec.push_back(1);
    cout << "After adding 2 more elements in vector" << endl;
    cout<< "vector size: " << ivec.size() <<", vector capacity:" << ivec.capacity() << endl;
    cout << "After adding 1 more elements in vector" << endl;
    ivec.push_back(1);
    cout<< "vector size: " << ivec.size() <<", vector capacity:" << ivec.capacity() << endl;

}
//-------------PART 8 END--------------------


int main() {
	cout << "!!!Part 1 Slicing!!!" << endl;
	part1();

	cout << "!!!Part 2 Slicing!!!" << endl;
	part2();

	cout << "!!!Part 3 Function Evaluation!!!" << endl;
	part3();

	cout << "!!!Part 4 Destructor sequence!!!" << endl;
	part4(); cout << endl;

	cout << "!!!Part 5 reference trick!!!" << endl;
	part5();

	cout << "!!!Part 6 Constructor/Destructor!!!" << endl;
	part6();

	cout << "!!!Part 7 Constructor/Destructor with exception!!!" << endl;
	part7();

	cout << "!!!Part 7 Vector Test!!!" << endl;
	part8();
	return 0;
}
