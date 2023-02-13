#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	int data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}

	~BinaryTreeNode()
	{
		delete left;
		delete right;
	}
};


class BST
{
	BinaryTreeNode<int> *root;

public:
	BST()
	{
		root = nullptr;
	}

	~BST()
	{
		delete root;
	}

	bool search(int target)
	{
		cout << "SEARCHING " << target << endl;
		BinaryTreeNode<int> *tmp = root;
		while (tmp != nullptr)
		{
			if (target == tmp->data)
				return true;
			else if (target < tmp->data)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		return false;
	}

private:
	BinaryTreeNode<int> *insert(int val, BinaryTreeNode<int> *node)
	{
		if (node == nullptr)
		{
			BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(val);
			return newNode;
		}
		BinaryTreeNode<int> *smallAns;
		if (node->data >= val)
		{
			smallAns = insert(val, node->left);
			node->left = smallAns;
		}
		else
		{
			smallAns = insert(val, node->right);
			node->right = smallAns;
		}
		return node;
	}

public:
	void insert(int val)
	{
		root = insert(val, root);
	}

private:
	void print(BinaryTreeNode<int> *root)
	{
		if (root == nullptr) return;
		cout << root->data << " : ";
		if (root->left) cout << "L" << root->left->data << " ";
		if (root->right) cout << "R" << root->right->data << " ";
		cout << endl;
		print(root->left);
		print(root->right);
	}

public:
	void print()
	{
		cout << "PRINTING BST" << endl;
		print(root);
	}

private:
	int getMin(BinaryTreeNode<int> *node)
	{
		while (node->left != nullptr)
			node = node->left;
		return node->data;
	}

	BinaryTreeNode<int> *deleteNode(int val, BinaryTreeNode<int> *node)
	{
		if (node == nullptr) return nullptr;
		if (node->data == val)
		{
			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				return nullptr;
			}
			else if (node->left == nullptr || node->right == nullptr)
			{
				BinaryTreeNode<int> *child;
				child = (node->left != nullptr ? node->left : node->right);
				node->left = nullptr;
				node->right = nullptr;
				delete node;
				return child;
			}
			else
			{
				int rightMin = getMin(node->right);
				node->data = rightMin;
				BinaryTreeNode<int> *rightAns = deleteNode(rightMin, node->right);
				node->right = rightAns;
				return node;
			}
		}
		else if (node->data > val)
		{
			BinaryTreeNode<int> *smallAns = deleteNode(val, node->left);
			node->left = smallAns;
		}
		else
		{
			BinaryTreeNode<int> *smallAns = deleteNode(val, node->right);
			node->right = smallAns;
		}
		return node;
	}

public:
	void deleteNode(int val)
	{
		root = deleteNode(val, root);
	}
};