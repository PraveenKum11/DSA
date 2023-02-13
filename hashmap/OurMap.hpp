#include <bits/stdc++.h>
using namespace std;

// HashMap implementation using closed hashing (ie separate chaining)

// keys will be of string type due to limitation of our hash function
// values can be different types.

template <typename V>
class MapNode
{
public:
	string key;
	V value;
	MapNode<V>* next;

	MapNode(string key, V value)
	{
		this->key = key;
		this->value = value;
		next = nullptr;
	}
	~MapNode()
	{
		delete next;
	}
};


template <typename V>
class OurMap
{
	MapNode<V>** buckets; // array pointers to LL heads.
	int count;
	int bucketSize;

public:
	OurMap()
	{
		count = 0;
		bucketSize = 5;
		buckets = new MapNode<V>*[bucketSize];

		for (int i = 0; i < bucketSize; i++)
			buckets[i] = nullptr;
	}
	~OurMap()
	{
		for (int i = 0; i < bucketSize; i++)
			delete buckets[i];
		delete [] buckets;
	}

	int size()
	{
		return count;
	}

private:
	int getBucketIndex(string key)
	{
		int hashCode = 0;
		int primeCoeff = 1; // we are using prime number as it gives a uniform distribution.
		for (int i = key.size() - 1; i >= 0; i--)
		{
			hashCode += (key[i] * primeCoeff);
			hashCode %= bucketSize;
			primeCoeff *= 37;
			primeCoeff %= bucketSize;
		}
		// compression function
		return hashCode % bucketSize;
	}

public:
	V getValue(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != nullptr)
		{
			if (head->key == key)
				return head->value;
			head = head->next;
		}
		return 0;
	}

private:
	void rehash()
	{
		MapNode<V>** temp = buckets;
		// MapNode<V>* temp[] = buckets; // above line same as this
		buckets = new MapNode<V>*[2 * bucketSize];
		for (int i = 0; i < 2 * bucketSize; i++)
			buckets[i] = nullptr;

		// reset the variable for the new bucket array
		int oldBucketSize = bucketSize;
		bucketSize *= 2;
		count = 0;

		for (int i = 0; i < oldBucketSize; i++)
		{
			MapNode<V>* head = temp[i];
			while (head != nullptr)
			{
				insert(head->key, head->value);
				head = head->next;
			}
		}

		for (int i = 0; i < oldBucketSize; i++)
			delete(temp[i]);
		delete [] temp;
	}

public:
	double getLoadFactor()
	{
		return (double)count / bucketSize;
	}

	void insert(string key, V value)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != nullptr)
		{
			if (head->key == key)
			{
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketIndex];
		MapNode<V>* newNode = new MapNode<V>(key, value);
		newNode->next = head;
		buckets[bucketIndex] = newNode;
		count++;

		double loadFactor = (double)count / bucketSize;
		if (loadFactor > 0.7) rehash();
	}

	V remove(string key)
	{
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V> *prev = nullptr;
		while (head != nullptr)
		{
			if (head->key == key)
			{
				if (prev == nullptr)
					buckets[bucketIndex] = head->next;
				else
					prev->next = head->next;

				V returnValue = head->value;
				head->next = nullptr;
				delete head;
				count--;
				return returnValue;
			}
			prev = head;
			head = head->next;
		}
		return 0;
	}
};