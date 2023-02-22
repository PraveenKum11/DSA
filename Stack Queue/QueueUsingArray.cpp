#include <bits/stdc++.h>
using namespace std;

template <typename T>
class QueueUsingArray
{
	T *data;
	int capacity, size;
	int firstIndex, nextIndex;

public:
	QueueUsingArray(int cap)
	{
		data = new T[cap];
		capacity = cap;
		size = 0;
		firstIndex = -1;
		nextIndex = 0;
	}

	int getSize()
	{
		return size;
	}

	bool isEmpty()
	{
		return size == 0;
	}

	void enqueue(T val)
	{
		if (firstIndex == nextIndex)
		{
			cout << "Queue is Full " << endl;
			return;
		}
		if (firstIndex == -1)
			firstIndex = 0;
		data[nextIndex] = val;
		size++;
		nextIndex = (nextIndex + 1) % capacity;
	}

	T dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty " << endl;
			return 0;
		}
		T val = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		if (firstIndex == nextIndex)
			firstIndex = -1, nextIndex = 0;
		size--;
		return val;
	}

	T front()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty " << endl;
			return 0;
		}
		return data[firstIndex];
	}
};