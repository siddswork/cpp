//============================================================================
// Name        : MultiInheritance.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
using namespace std;

class A
{
  int x;
public:
  void setX(int i) {x = i;}
  void print() { cout << x << endl; }
};

class B:  public A
{
public:
  B()  { setX(10); }
};

class C:  public A
{
public:
  C()  { setX(20); }
};

class D: public B, public C {
};


class BB: virtual public A
{
public:
  BB()  { setX(10); }
};

class CC: virtual public A
{
public:
  CC()  { setX(20); }
};

class DD: public BB, public CC {
};

int main()
{
    D example1;
    example1.B::print();
    example1.C::print();

    cout << "----------------" << endl;
    DD example2;
	example2.BB::print();
	example2.CC::print();
	example2.print();
    return 0;
}
