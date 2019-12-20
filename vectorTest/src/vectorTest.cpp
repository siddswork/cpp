/*
 * vectorTest.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: sidd
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVector(vector<int>& vi)
{
	cout << "[";
	for(vector<int>::iterator it = vi.begin(); it != vi.end(); ++it)
	{
		cout << " " << *it;
		if(it+1 != vi.end())
		{
			cout << ",";
		}
	}
	cout << " ] <= size:" << vi.size() <<"; capacity:" << vi.capacity() << endl;
}

void basicTest()
{
	vector<int> v0;
	printVector(v0);

	vector<int> v1 (2, 100);
		vector<int>::iterator it = v1.begin();

		printVector(v1);

		it = v1.insert ( it , 200 );
		printVector(v1);

		v1.push_back(300);
		v1.push_back(300);
		printVector(v1);

		v1.pop_back();
		printVector(v1);

		v1.push_back(-400);
		v1.push_back(-500);
		printVector(v1);

		v1.erase(v1.end() - 1);
		v1.erase(v1.begin()+(v1.size()-1));
		printVector(v1);

		cout << "Front element of v1 = " << v1.front() << endl;
		cout << "Element v1[1] = " << v1[1] << endl;
		cout << "Element at v1's 2 = " << v1.at(2) << endl;
		cout << "Back element of v1 = " << v1.back() << endl;
}

class t
{
public:
	t();
	t(int n) { value = n; }
	~t() { cout << "Deleting instance of t object with value " << value << endl; }
	int get() { return value; }
	void set(int n) { value = n; }
protected:
	int value;
};

void printVector(vector<t*>& vpt)
{
	cout << "Using iterator: [";
	for(vector<t*>::iterator it = vpt.begin(); it != vpt.end(); ++it)
	{
		cout << " " << (*it)->get();
		if(it+1 != vpt.end())
		{
			cout << ",";
		}
	}
	cout << " ] <= size:" << vpt.size() << endl;

	cout << "Using size: [";
	for(int i = 0; i < vpt.size(); i++)
	{
		cout << " " << vpt.at(i)->get();
		if(i+1 != vpt.size())
		{
			cout << ",";
		}
	}
	cout << " ] <= size:" << vpt.size() << endl;

	cout << "No other iterating technique is availabel in C++ 98" << endl;

}

void basicPlus()
{
	t* pt = new t(100);
	cout << "New object of t with value " << pt->get() << endl;
	pt->set(101);
	cout << "Changed the value in object of t to " <<  pt->get() << endl;
	cout << "Deleting object of t" << endl;
	delete pt;
}

void basicPlusPlus()
{
	vector<t*> vpt;
	vector<t*>::iterator it;
	printVector(vpt);

	vpt.push_back(new t(10));
	vpt.push_back(new t(20));
	printVector(vpt);

	vpt.pop_back(); // But the object is never deleted. Leads to memory leak
	printVector(vpt);

	it = vpt.begin();
	vpt.erase(it); // But the object is never deleted. Leads to memory leak
	printVector(vpt);

	// This is how we can ensure memory gets freed
	vpt.push_back(new t(30));
	vpt.push_back(new t(40));
	printVector(vpt);

	int n = 1;
	it = vpt.begin();
	delete vpt[n];
	vpt.erase(it + n);
	printVector(vpt);
}

class dummy
{
public:
	dummy() { data_=0; std::cout << "dummy(): constructor ["<< data_ << "]" << std::endl;}
	dummy(int i):data_(i) { std::cout << "dummy(int ): constructor ["<< data_ << "]" << std::endl;}
	dummy(const dummy &copyFrom) {
		data_ = copyFrom.getData();
		std::cout << "dummy(dummy &): constructor ["<< data_ << "]" << std::endl;
	}
	~dummy() { std::cout << "~dummy(): destructor ["<< data_ << "]"  << std::endl;}
	int getData() const { return data_; }
	void printPointer() const { cout << this; }
	void setData(int i) { data_ = i; }
private:
	int data_;
};

void testingUseOfObjConst()
{
	vector<dummy> dummyVector;
	std::cout << "Size:" <<dummyVector.size() << " capacity:" << dummyVector.capacity() << std::endl;

	dummy dummyObj1, dummyObj2, dummyObj3(3);
	dummyObj2.setData(2);
	dummy dummyObj4(4);
	dummy dummyObj5(5);

	cout << "-----Starting to use vector" << endl;
	dummyVector.push_back(dummyObj1);
	std::cout << "Size:" <<dummyVector.size() << " capacity:" << dummyVector.capacity() << std::endl;
	cout << "----------Pushing 2nd object" << endl;
	dummyVector.push_back(dummyObj2);
	std::cout << "Size:" <<dummyVector.size() << " capacity:" << dummyVector.capacity() << std::endl;
	cout << "----------Pushing 3rd object" << endl;
	dummyVector.push_back(dummyObj3);
	std::cout << "Size:" <<dummyVector.size() << " capacity:" << dummyVector.capacity() << std::endl;
	cout << "----------Pushing 4th object" << endl;
	dummyVector.push_back(dummyObj4);
	std::cout << "Size:" <<dummyVector.size() << " capacity:" << dummyVector.capacity() << std::endl;
	cout << "----------Pushing 5th object" << endl;
	dummyVector.push_back(dummyObj5);
	std::cout << "Size:" <<dummyVector.size() << " capacity:" << dummyVector.capacity() << std::endl;
	cout << "----------Vector operation end" << endl;
	/*dummyVector.push_back(dummyObj2);
	std::cout << "Size:" <<dummyVector.size() << " capacity:" << dummyVector.capacity() << std::endl;
*/
}



int main()
{
	//basicTest();
	cout << "-----" << endl;
	//basicPlus();
	cout << "-----" << endl;
	//basicPlusPlus();
	cout << "-----" << endl;
	//unique_ptr<int> pInt;
	//pInt.reset(NULL);
	//testingUseOfObjConst();
	//int i = 1;
	//(((((cout << i) << i++) << ++i) << --i) << i++) << i;
	{
		cout << "--------"<< endl;
		dummy dummyObject1;
		dummy& dummyRef0 = dummyObject1;

		const dummy& dummyRef1 = dummy();
		//dummy& dummyRef3 = dummy(); // ERROR: non-const lvalue reference to type 'dummy' cannot bind to a temporary of type 'dummy'

		dummy&& dummyRef2 = dummy();
		cout << dummyRef2.getData() << endl;
	}

	cout << "--------"<< endl;
  vector< int > ivec;
  cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;

  for ( int ix = 0; ix < 24; ++ix ) {
	  ivec.push_back( ix );
	  cout << "ivec: size: " << ivec.size() << " capacity: "  << ivec.capacity() << endl;
  }
  cout << "--------"<< endl;
  cout << ivec[5] << " " << ivec[12] << " size:" << ivec.size() <<  " " << ivec[-5] << " size:" << ivec.size() << endl;
}



