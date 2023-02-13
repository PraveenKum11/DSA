// #include "QueueUsingArray.cpp"
#include "DynamicQueue.hpp"

int main()
{
	// QueueUsingArray<int> q(5);
	DynamicQueue<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << "---" << endl;
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout << "---" << endl;
	cout << q.front() << endl;
	cout << q.getSize() << endl;
}