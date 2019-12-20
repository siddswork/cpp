//============================================================================
// Name        : maximaize.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * A company has employed N developers (numbered from 0 to N−1) and wants to divide
 * them into two teams. The first is a front-end team with F developers. The second
 * is a back-end team with N−F developers. If the K-th developer is assigned to the
 * front-end team then their contribution is A[K], and if they are assigned to the
 * back-end team then their contribution is B[K]. What is the maximum sum of
 * contributions the company can achieve?
 * Write a function:
 * class Solution { public int solution(int[] A, int[] B, int F); }
 * that, given two arrays A, B (consisting of N integers each) and the integer F,
 * returns the maximum sum of contributions the company can achieve.
 * Examples:
 * 1. Given A = [4, 2, 1], B = [2, 5, 3] and F = 2, the function should return 10.
 * There should be two front-end developers and one back-end developer. The 0th and 2nd
 * developers should be assigned to the front-end team (with contributions 4 and 1) and
 * the 1st developer should be assigned to the back-end team (with contribution 5).
 * 2. Given A = [7, 1, 4, 4], B = [5, 3, 4, 3] and F = 2, the function should return 18.
 * The 0th and 3rd developers should be assigned to the front-end team and the 1st and
 * 2nd developers should be assigned to the back-end team.
 * 3. Given A = [5, 5, 5], B = [5, 5, 5] and F = 1, the function should return 15.
 * The 0th developer can be assigned to the front-end team and the 1st and 2nd developers
 * can be assigned to the back-end team.
 * Write an efficient algorithm for the following assumptions:
	•	N is an integer within the range [1..200,000];
	•	arrays A and B have equal lengths;
	•	each element of array A is an integer within the range [0..1,000];
	•	F is an integer within the range [0..N].
 *
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct resource {
    int val;
    char type;
    int pos;
};

bool desc(resource* a, resource* b)
{
    if (a->val > b->val)
    {
        return true;
    }
    return false;
}

void concat(vector<int> &team, char type, vector<resource*> &all,
            map<int, vector<resource*>* > &mapLoc,
            map<int, vector<resource*>* > &mapVal)
{
    int pos = 0;
    map<int, vector<resource*>* >::iterator it;
    for (auto val: team)
    {
        resource* newRes = new resource();
        newRes->val = val;
        newRes->type = type;
        newRes->pos = pos++;
        all.push_back(newRes);
        it = mapLoc.find(newRes->pos);
        if(it != mapLoc.end()) // found
        {
            it->second->push_back(newRes);
        }
        else // not found
        {
            vector<resource*> *resVec = new vector<resource*>();
            resVec->push_back(newRes);
            mapLoc.emplace(newRes->pos, resVec);
        }
        it = mapVal.find(newRes->val);
        if(it != mapVal.end()) // found
        {
            it->second->push_back(newRes);
        }
        else // not found
        {
            vector<resource*> *resVec = new vector<resource*>();
            resVec->push_back(newRes);
            mapVal.emplace(newRes->val, resVec);
        }
    }
}

void print(vector<resource*> &all)
{
    for (resource* i : all)
    {
        cout<<"["<<i->type<<"]";
    }
    cout  << endl;
    for (resource* i : all)
    {
        cout<<"["<<i->val<<"]";
    }
    cout  << endl;

    for (resource* i : all)
    {
        cout<<"["<<i->pos<<"]";
    }
    cout  << endl;
}

void print(map<int, vector<resource*>* > &mapLoc)
{
    map<int, vector<resource*>* >::iterator it;
    for (it = mapLoc.begin(); it != mapLoc.end(); it++)
    {
        cout << it->first <<":"<< endl;
        for (resource* i: *(it->second))
        {
            cout<<" ["<<i->type<<"|"<<i->val<<"|"<<i->pos <<"]" <<endl;
        }
    }
}


int maxOutput(vector<int> &A, vector<int> &B,
		vector<resource*> &all,
		map<int, vector<resource*>* > &mapLoc,
		map<int, vector<resource*>* > &mapVal,
		int F, int sizeOfB)
{
    int sumA=0, sumB=0;
    int canTakeA = F;
    int canTakeB = sizeOfB - F;
    //cout << ">>>" <<canTakeA <<"," << canTakeB<< endl;
    map<int, vector<resource*>* >::iterator it;

    for (resource* i : all)
    {
    	if(canTakeA || canTakeB) {
			//cout << "<" << i->type<<i->val;
			//if(i->pos == -1) cout << " Skip" << endl;

			if(i->type=='A' && canTakeA && i->pos != -1) //For A
			{

				int valA = i->val;
				it=mapVal.find(valA);

				if(it!=mapVal.end() && it->second->size() > 1)
				{
					//cout<<" Multi" << endl;
					int pos = -1;
					int valOther = numeric_limits<int>::max();
					for( resource* j : *(it->second) )
					{
						if( j->type == 'A'  && j->pos != -1)
						{
							if(valOther > B[j->pos])
							{
								valOther = B[j->pos];
								pos = j->pos;
							}
						}
					}
					sumA += valA;
					//cout << "A:"<< valA << " + ";
					for(resource* j: *(mapLoc.find(pos)->second))
					{
						j->pos = -1;
					}
				}
				else
				{
					//cout<<" Single" << endl;
					sumA += valA;
					//cout << "A:"<< valA << " + ";
					for(resource* i : *(mapLoc.find(i->pos)->second) )
					{
						i->pos = -1;
					}
				}

				canTakeA--;
			}
			else if(i->type=='B' && canTakeB && i->pos != -1)//For B
			{
				int valB = i->val;
				it=mapVal.find(valB);

				if(it!=mapVal.end() && it->second->size() > 1)
				{
					//cout<<" Multi" << endl;
					int pos = -1;
					int valOther = numeric_limits<int>::max();
					for( resource* j : *(it->second) )
					{
						if( j->type == 'B'  && j->pos != -1)
						{
							if(valOther > A[j->pos])
							{
								valOther = A[j->pos];
								pos = j->pos;
							}
						}
					}
					//cout <<"valOther" << valOther <<endl;
					sumB += valB;
					//cout << "B:"<< valB << " + ";
					for(resource* j: *(mapLoc.find(pos)->second))
					{
						j->pos = -1;
					}
				}
				else
				{
					//cout<<" Single" << endl;
					sumB += valB;
					//cout << "B:"<<valB<< " + ";
					for(resource* i : *(mapLoc.find(i->pos)->second) )
					{
						i->pos = -1;
					}
				}
				canTakeB--;
			}
			//cout << ">>>" <<canTakeA <<"," << canTakeB<< endl;
		}
    }
    //cout << endl;

    return sumA + sumB;
}
int solution(vector<int> &A, vector<int> &B, int F) {
    // write your code in C++14 (g++ 6.2.0)
    //cout << endl;
    vector<resource*> allResource;
    map<int, vector<resource*>* > mapLoc;
    map<int, vector<resource*>* > mapVal;
    concat(A, 'A', allResource, mapLoc, mapVal);
    concat(B, 'B', allResource, mapLoc, mapVal);

    sort(allResource.begin(), allResource.end(), &desc );
    //print(allResource);
    //print(mapLoc);
    //cout << "----" << endl;
    //print(mapVal);


    //print(mapVal);

    return maxOutput(A, B, allResource, mapLoc, mapVal, F, B.size());
}



int main() {
	cout << "!!!Maximize!!!" << endl;
	{
		vector<int> A{4, 2, 1};
		vector<int> B{2, 5, 3};
		cout << "Output:" << solution(A, B, 2) << " Expected:" << 10 << endl;
	}
	{
		vector<int> A{5, 5, 5};
		vector<int> B{5, 5, 5, 5};
		cout << "Output:" << solution(A, B, 2) << " Expected:" << 15 << endl;
	}
	{
		vector<int> A{7, 1, 4, 4};
		vector<int> B{5, 3, 4, 3};
		cout << "Output:" << solution(A, B, 2) << " Expected:" << 18 << endl;
	}



	return 0;
}
