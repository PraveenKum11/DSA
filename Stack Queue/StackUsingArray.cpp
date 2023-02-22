#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class StackUsingArray
{
	T *data;
	int nextIndex;
	int capacity;

public:
	StackUsingArray()
	{
		data = new T[4];
		nextIndex = 0;
		capacity = 4;
	}

	int size()
	{
		return nextIndex;
	}

	bool isEmpty()
	{
		return nextIndex == 0;
	}

	void push(T val)
	{
		if (nextIndex == capacity)
		{
			T *newData = new T[capacity * 2];
			for (int i = 0; i < capacity; i++)
				newData[i] = data[i];
			delete [] data;
			data = newData;
		}
		data[nextIndex++] = val;
	}

	T pop()
	{
		if (isEmpty())
		{
			cout << "Stack Is Empty " << endl;
			return 0;
		}
		return data[--nextIndex];
	}

	T top()
	{
		if (isEmpty())
		{
			cout << "Stack Is Empty " << endl;
			return 0;
		}
		return data[nextIndex - 1];
	}
};