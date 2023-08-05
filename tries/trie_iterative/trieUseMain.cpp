#include <iostream>

#include "Trie.cpp"

int main()
{
	Trie T;
	T.insertKey("app");
	T.insertKey("apple");
	T.insertKey("application");
	T.insertKey("allocation");
	T.insertKey("dull");
	T.insertKey("dance");
	T.insertKey("bar");

	std::cout << T.searchKey("application") << "\n";
	std::cout << T.searchKey("dude") << "\n";
	std::cout << T.searchKey("bar") << "\n";

	std::cout << T.deleteKey("dull") << "\n";
	std::cout << T.searchKey("dull") << "\n";
}