#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
	char data;
	TrieNode** children;
	bool isTerminal;

	TrieNode(char data)
	{
		this->data = data;
		children = new TrieNode*[26];
		isTerminal = false;
		
		// intializing the children
		for (int i = 0; i < 26; i++)
			children[i] = nullptr;
	}
};

class Trie
{
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode('\0');
	}

private:
	void insertWord(TrieNode* root, string word)
	{
		if (word.empty())
		{
			root->isTerminal = true;
			return;
		}
		int idx = word[0] - 'a';
		if (root->children[idx] == nullptr)
		{
			TrieNode* newNode = new TrieNode(word[0]);
			root->children[idx] = newNode;
		}
		insertWord(root->children[idx], word.substr(1));
	}

public:
	void insertWord(string word)
	{
		insertWord(root, word);
	}

private:
	bool searchWord(TrieNode* root, string word)
	{
		if (word.empty()) return root->isTerminal;
		int idx = word[0] - 'a';
		if (root->children[idx] == nullptr) return false;
		return searchWord(root->children[idx], word.substr(1));
	}

public:
	bool searchWord(string word)
	{
		return searchWord(root, word);
	}

private:
	void removeWord(TrieNode* root, string word)
	{
		if (word.empty()) root->isTerminal = false;
		int idx = word[0] - 'a';
		if (root->children[idx] == nullptr) return;
		removeWord(root->children[idx], word.substr(1));

		// if the child is useless remove it.
		if (root->children[idx]->isTerminal == false)
		{
			for (int i = 0; i < 26; i++)
				if (root->children[idx]->children[i] != nullptr)
					return;

			// If we reach here means the child is not a terminal
			// and does not have a child either therefore useless.
			delete root->children[idx];
			root->children[idx] = nullptr;
		}
	}

public:
	void removeWord(string word)
	{
		removeWord(root, word);
	}
/* -----------------------------------------------PREVIOUS-----------------------------------------*/

private:
	TrieNode* findTrieNode(TrieNode *root, string word)
	{
		if (word.empty()) return root;
		int wordIdx = word[0] - 'a';
		return findTrieNode(root->children[wordIdx], word.substr(1));
	}

	void printPossible(TrieNode* root, string completeWord)
	{
		if (root == nullptr) return;
		if (root->isTerminal) cout << completeWord << endl;
		for (int i = 0; i < 26; i++)
			if (root->children[i] != nullptr)
				printPossible(root->children[i], completeWord + root->children[i]->data);
	}

public:
	void autoComplete(string word)
	{
		TrieNode* finalNode = findTrieNode(root, word);
		printPossible(finalNode, word);
	}
};

int main()
{
	Trie t;
	int n; cin >> n;
	while (n--)
	{
		string tmp; cin >> tmp;
		t.insertWord(tmp);
	}
	string inWord; cin >> inWord;
	cout << endl;
	t.autoComplete(inWord);
}
