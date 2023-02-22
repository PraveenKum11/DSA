#include "StackUsingLL.cpp"

int main()
{
	StackUsingLL s;

	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	s.push(500);
	s.push(600);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.top() << endl;
	cout << s.getSize() << endl;
	cout << s.isEmpty() << endl;
}