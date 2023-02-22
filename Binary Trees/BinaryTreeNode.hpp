#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(int data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}

	~BinaryTreeNode()
	{
		delete left;
		delete right;
		// NOTE : It's fine to delete nullptr
	}
};