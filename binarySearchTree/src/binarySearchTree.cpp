/*
 * binarySearchTree.cpp
 *
 *  Created on: Mar 8, 2017
 *      Author: sidd
 */
#include <iostream>

using namespace std;

class TreeNode
{
public:
	TreeNode(): pData(NULL), size(1) , left(NULL), right(NULL) { }
	TreeNode(int d): pData(new int(d)), size(1), left(NULL), right(NULL) { }
	~TreeNode()
	{
		if(left) delete left;
		if(pData)
		{
			cout << "Deleting node with data: "<< *pData << endl;
			delete pData;
		}
		if(right) delete right;
	}
	void addElement(int d)
	{
		if(!pData)
		{
			pData = new int(d);
			size++;
		}
		else if(d <= *pData)
		{
			if(left)
			{
				left->addElement(d);
			}
			else
			{
				left = new TreeNode(d);
			}
			size ++;
		}
		else// if (*pData < d)
		{
			if(right)
			{
				right->addElement(d);
			}
			else
			{
				right = new TreeNode(d);
			}
			size ++;
		}
	}
	void printTree()
	{
		if(pData) cout << "<" << *pData << ">:Size[" << size << "]" << endl;
		if(left) left->printTree();
		if(right) right->printTree();
	}
	int getMaxDepth()
	{
		return findMaxDepth();
	}
	int getMinDepth()
	{
		return findMinDepth();
	}
private:
	int*      pData;
	int       size;
	TreeNode* left;
	TreeNode* right;

	int findMaxDepth(int i=0)
	{
		int leftDepth  = 0;
		int rightDepth = 0;
		if(left) leftDepth = left->findMaxDepth(i+1);
		if(right) rightDepth = right->findMaxDepth(i+1);
		if(leftDepth || rightDepth)
		{
			return leftDepth>rightDepth?leftDepth:rightDepth;
		}
		else
		{
			return i;
		}
	}
	int findMinDepth(int i=0)
	{
		int leftDepth  = 0;
		int rightDepth = 0;
		if(left) leftDepth = left->findMaxDepth(i+1);
		if(right) rightDepth = right->findMaxDepth(i+1);
		if(leftDepth || rightDepth)
		{
			return leftDepth<rightDepth?leftDepth:rightDepth;
		}
		else
		{
			return i;
		}
	}
};


int main()
{
	TreeNode BST(10);
	BST.printTree();

// Left
	BST.addElement(5);
	BST.addElement(3);
	BST.addElement(7);
	BST.addElement(2);
	BST.addElement(4);
// Right
	BST.addElement(15);
	BST.addElement(15);
	BST.addElement(13);
	BST.addElement(18);

	cout << "=========" << endl;

	BST.printTree();
	cout << "Max Depth = " << BST.getMaxDepth() << endl;
	cout << "Min Depth = " << BST.getMinDepth() << endl;

	cout << "=========" << endl;
}


