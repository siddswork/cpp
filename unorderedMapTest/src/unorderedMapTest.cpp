/*
 * unorderedMapTest.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: sidd
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<int,int> m1;
	pair<unordered_map<int,int>::iterator, bool> ret;
	//Unique inserts
	m1.insert(pair<int,int> (1,2) );
	m1.insert(pair<int,int> (2,3) );
	m1.insert(pair<int,int> (3,6) );
	ret = m1.insert(make_pair(4,8));
	if(ret.second == true)
	{
		cout << "Element (" << ret.first->first << "," << ret.first->second << ") inserted" << endl;
	}
	else
	{
		cout << "Element " << ret.first->first << " already exist in map with value ";
		cout << ret.first->second << endl;
	}

	//Creating conflicts
	ret = m1.insert(pair<int,int> (4,10));
	if(ret.second == false)
	{
		cout << "Insert failed: Element " << ret.first->first << " already exist in map with value ";
		cout << ret.first->second << endl;
		m1.erase(ret.first);
		int isFound = m1.count(4);
		if(!isFound)
		{
			cout << "Erased: Element with key " << ret.first->first << endl;
		}
	}
	ret = m1.insert(pair<int,int> (4,10));
	if(ret.second == false)
	{
		cout << "Insert failed: Element " << ret.first->first << " already exist in map with value ";
		cout << ret.first->second << endl;
	}

	ret = m1.insert(pair<int,int> (4,12));
	if(ret.second == false)
	{
		cout << "Insert failed: Element " << ret.first->first << " already exist in map with value ";
		cout << ret.first->second << endl;
	}

	cout << "Contents of Map:\n";
	for (unordered_map<int,int>::iterator it=m1.begin(); it!=m1.end(); ++it)
	{
	    cout << "[" << it->first << " => " << it->second << "]"<< '\n';
	}
}



