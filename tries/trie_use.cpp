#include "Trie.hpp"

int main()
{
	Trie t;
	t.insertWord("hot");
	t.insertWord("pot");
	t.insertWord("and");
	t.insertWord("answer");
	t.insertWord("hotter");

	cout << "find - answer : " << boolalpha << t.searchWord("answer") << endl;
	t.removeWord("answer");
	cout << "find - answer : " << boolalpha << t.searchWord("answer") << endl;
	cout << "find - hot: " << boolalpha << t.searchWord("hot") << endl;
	t.removeWord("hot");
	cout << "find - hot: " << boolalpha << t.searchWord("hot") << endl;
}