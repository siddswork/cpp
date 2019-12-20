//============================================================================
// Name        : interval_map.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : 
// Description : Interval Map in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <map>
#include <limits>
#include <vector>

void createBin(long long N, vector<char> &ret)
{
	int quo = N, rem = -1;
	while(quo != 0)
	{
		rem = quo % 2;
		quo = quo / 2;
		if(rem) ret.push_back('1');
		else ret.push_back('0');
	}
}

void print(vector<char> &ret)
{
	for (auto i : ret)
	{
		cout << i << ".";
	}
	cout << endl;
}

template<typename K, typename V>
class interval_map {
	std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }


    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
    	cout << keyBegin <<", "<<keyEnd << " << " << val << endl;
    	// INSERT YOUR SOLUTION HERE
    	if( !(keyBegin < keyEnd)) {
    		return;
    	}
    	// Case of single value
    	auto it = m_map.find(std::numeric_limits<K>::lowest());
		if (it != m_map.end() && m_map.size() == 1) {
			// If all values are same no need to change anything
			// else add begin and end with new value
			// below is the else case
			if(!(it->second == val))
			{ // Note: on value only allowed operator is ==
				V singleVals = it->second;
				m_map.emplace(keyBegin,val);
				m_map.emplace(keyEnd,singleVals);
			}
			return;
		}

		// Case when pre-populated with different values
		K key = keyBegin;
		//bool hasStart = false;

		//When value at keyEnd is different from input value
		//We can directly set the keyEnd with its previous value
		V valAtKeyEnd = this->operator [](keyEnd);
		if(!(valAtKeyEnd == val))
		{
			//cout << "Setting end" << endl;
			auto it = m_map.find(keyEnd);
			if(it == m_map.end()) // not found
			{
				m_map.emplace(keyEnd,valAtKeyEnd);
			}
			else // found
			{
				it->second = valAtKeyEnd;
			}
		}
		// Now that keyEnd has been taken care of, we need to check from
		// (keyBegin) to (keyEnd -1)

		auto dnIt = --m_map.upper_bound(key);
		if(dnIt->first < keyEnd && !(dnIt->second == val))
		{
			m_map.emplace(key,val);
		}

		auto itEnd = m_map.find(keyEnd);
		if(itEnd != m_map.end()) {
			// Do nothing
		} else {
			itEnd = --m_map.upper_bound(keyEnd);
		}
		auto itStart = m_map.find(key);
		if(itStart != m_map.end()) {
			// Do nothing
    	} else {
			itStart = --m_map.upper_bound(key);
		}
		//cout << itStart->first << ":" << itEnd->first << endl;
		for (typename map<K,V>::iterator itr=m_map.begin(); itr!=m_map.end(); ++itr)
		{
			if(itr->first > itStart->first && itr->first < itEnd->first)
			{
				if(itr != m_map.end())
				{
					//cout << itr->first << endl;
					m_map.erase(itr->first);
					itr= m_map.begin();
				}
			}
		}
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }

    void print()
    {
    	//cout << "Size: " << m_map.size() << endl;
    	for (auto i : m_map)
    	{
    		cout << i.first << "->" << i.second << endl;
    	}
    }
};



int main() {
	cout << std::numeric_limits<int>::lowest() << endl; // prints
	interval_map<int, char> imA('A');
	interval_map<int, char> imB('A');

	vector<char> revBin;
	//createBin(12345678, revBin);
	//print(revBin);

	//imB.crete(revBin);
	//imB.print();

	imA.print();
	cout << "--" << endl;

	imA.assign(13, 15, 'B');
	imA.print();
	cout << "--" << endl;

	imA.assign(20, 26, 'C');
	imA.print();
	cout << "--" << endl;

	imA.assign(30, 36, 'D');
	imA.print();
	cout << "--" << endl;

	imA.assign(12, 16, 'E');
	imA.print();
	cout << "--" << endl;

	imA.assign(-5, 3, 'F');
	imA.print();
	cout << "--" << endl;

	imA.assign(-6, 40, 'A');
	imA.print();
	cout << "--" << endl;

	imA.assign(0, 4, '0');
	imA.print();
	cout << "--" << endl;
	imA.assign(4, 7, '1');
	imA.print();
	cout << "--" << endl;
	imA.assign(2, 5, '1');
	imA.print();
	cout << "--" << endl;

	return 0;
}
