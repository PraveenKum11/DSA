#include "Trie.hpp"

int main()
{
	Trie t;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp; cin >> tmp;
		t.insertWord(tmp);
	}
	string toFind; cin >> toFind;
	cout << boolalpha << t.searchWord(toFind) << endl;
}