//============================================================================
// Name        : towerOfHanoi.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        //cout<<"\t Move disk 1 from peg "<<frompeg<<" to peg "<<topeg << endl;
    	//cout << ".";
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    //cout<<"\t Move disk "<<num<<" from peg "<<frompeg<<" to peg "<<topeg << endl;
    towers(num - 1, auxpeg, topeg, frompeg);
}


int main()
{
    int num = 25;

    cout<<"Enter the number of disks : " << num << endl;

    cout<<"The sequence of moves involved in the Tower of Hanoi are :" << endl;
    towers(num, 'A', 'C', 'B');
    return 0;
}
