//============================================================================
// Name        : cpp_2.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

using namespace std;

void print(int &i)
{
	cout << i;
}

int main()
{
	{
		class B { };
		class D: public B {};

		B *b = new D;
		D* d = NULL;
		// *d = dynamic_cast<D*>(b); // error: 'B' is not polymorphic
		if(d != NULL)
			cout<<"works" << endl;
		else
			cout<<"cannot cast B* to D*" << endl;
	}

	{
		class E { public: virtual void a() { cout << "E.a()" << endl; } };
		class F: public E {};

		E* e = new E;
		F* f = static_cast<F*>(e);
		if(f != NULL) {
			cout<<"works" << endl;
			f->a();
		}
		else
			cout<<"cannot cast E* to F*" << endl;
	}

	{
		class E { public: virtual void a() { cout << "E.a()" << endl; } };
		class F: public E {};

		E* e = new E;
		F* f = dynamic_cast<F*>(e);
		if(f != NULL)
			cout<<"works E* to F*" << endl;
		else
			cout<<"cannot cast E* to F*" << endl;
	}

	{
		class G { public: virtual void a() { cout << "G.a()" << endl; } };
		class H: public G {};

		H* h = new H;
		G* g = dynamic_cast<G*>(h);
		if(g != NULL) {
			cout<<"works H* to G*" << endl;
			g->a();
		}
		else
			cout<<"cannot cast H* to G*" << endl;
	}

	{
		class Base {
		private:
		    virtual void fun() { cout << "Base Fun"; }
		    friend int ::main();
		};

		class Derived: public Base {
		public:
		    void fun() { cout << "Derived Fun"; }
		};

		Base *ptr = new Derived;
		ptr->fun();
	}

    const int i = 1;
	print(i);

	return 0;
}


