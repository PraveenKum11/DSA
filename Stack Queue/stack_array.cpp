#include "StackUsingArray.cpp"
using namespace std;

int main()
{
	StackUsingArray<double> s;

	s.push(10.101);
	s.push(20.101);
	s.push(30.101);
	s.push(40.101);
	s.push(50.101);
	s.push(60.101);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.top() << endl;
	cout << s.size() << endl;
	cout << boolalpha << s.isEmpty() << endl;
}