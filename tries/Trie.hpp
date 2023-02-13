#include "TrieNode.hpp"
#include <string>

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
};