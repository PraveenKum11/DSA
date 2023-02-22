#include "QueueUsingLL.cpp"

int main()
{
	QueueUsingLL q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << "---" << endl;
	cout << q.front() << endl;
	cout << q.getSize() << endl;
	cout << boolalpha << q.isEmpty() << endl;
}