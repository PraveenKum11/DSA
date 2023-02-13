#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

class StackUsingLL
{
	Node *data;
	int size;

public:
	StackUsingLL()
	{
		data = nullptr;
		size = 0;
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void push(int val)
	{
		Node *newNode = new Node(val);
		newNode->next = data;
		data = newNode;
		size++;
	}

	int pop()
	{
		if (data == nullptr)
		{
			cout << "Stack Is Empty " << endl;
			return 0;
		}
		Node *temp = data;
		data = data->next;
		int returnVal = temp->data;
		delete temp;
		size--;
		return returnVal;
	}

	int top()
	{
		if (data == nullptr)
		{
			cout << "Stack Is Empty " << endl;
			return 0;
		}
		int returnVal = data->data;
		return returnVal;
	}
};
