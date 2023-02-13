#include "BST.hpp"

int main()
{
	BST b1;
	b1.insert(50);
	b1.insert(20);
	b1.insert(10);
	b1.insert(30);
	b1.insert(70);
	b1.insert(60);
	b1.insert(80);
	b1.insert(40);
	b1.insert(55);
	b1.print();
	cout << "-------------------" << endl;

	// cout << boolalpha << b1.search(40) << endl;
	b1.deleteNode(40);
	b1.print();
	cout << "-------------------" << endl;
	b1.deleteNode(20);
	b1.print();
	cout << "-------------------" << endl;
	b1.deleteNode(50);
	b1.print();
	cout << "-------------------" << endl;
}