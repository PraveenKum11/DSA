#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int val)
	{
		data = val;
		next = nullptr;
	}
};

class QueueUsingLL
{
	Node *head, *tail;
	int size;

public:
	QueueUsingLL()
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return head == nullptr;
	}

	void enqueue(int val)
	{
		Node *newNode = new Node(val);
		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
			size = 1;
			return;
		}
		tail->next = newNode;
		tail = newNode;
		size++;
	}

	int dequeue()
	{
		if (isEmpty())
		{
			cout << "Empty Queue " << endl;
			return 0;
		}
		Node *temp = head;
		head = head->next;
		int val = temp->data;
		delete temp;
		size--;
		return val;
	}

	int front()
	{
		if (isEmpty())
		{
			cout << "Empty Queue " << endl;
			return 0;
		}
		return head->data;
	}
};