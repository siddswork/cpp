//============================================================================
// Name        : combination.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

long long factorial(long long n)
{
	long long ret = n;

	if (n == 1 || n == 0)
		return 1l;
	while(n > 1)
	{
		ret = ret * --n;
	}
	if (n < 0)
		return 0l;
	return ret;
}
void printSubStr(vector<int> &substrpos, string str, int count)
{
	cout << count << ". ";
	for (int i : substrpos)
	{
		cout << str[i];
	}
	cout << endl;
}
bool combinationOf(long long K, string str)
{
	// nCr in Combination
	// From N elements create different set of K elements
	// such that the order of selection does not matter
	// when K <= N, number of combination is N!/K!(N-K)!
	// and when K > N = 0
	int N = str.size();
	vector<int> substrpos;
	int count = 0;

	if (K <= N)
	{
		cout << "Number of combination: " << factorial(N)/(factorial(K)*factorial(N-K)) << endl;
		int popCount = 1, pop, prevEndTouched = -1, endTouched = 0;
		for (int i = 0; i < N; i++)
		{
			substrpos.push_back(i);
			if(substrpos.size() == K)
			{
				printSubStr(substrpos, str, ++count);
				if(i + 1 == N) { // touching the end
					++endTouched;
					if(prevEndTouched < endTouched)
						pop = ++popCount;
					else
						pop++;
				}
				else
				{
					if(endTouched)
						prevEndTouched = endTouched;
					endTouched = 0;
					pop = 1;
				}
				if( pop > K)
					break;
				for(int j = 0; j < pop; j++)
				{
					i = *(--substrpos.end());
					substrpos.pop_back();
				}
			}
			cout << "i:" << i << " +1:" << i+1 << " N:" << N << " pET:" <<  prevEndTouched << " ET:" << endTouched << " pop:"<< pop << endl ;
		}
		return true;
	}
	else
	{
		cout << "Number of combination: 0"<< endl;
		return false;
	}
}
int main() {
	string str("12345");
	combinationOf(5l, str);
	return 0;
}
