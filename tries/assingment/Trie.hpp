#include "TrieNode.hpp"
#include <string>

class Trie
{
	TrieNode *root;

public:
	Trie()
	{
		root = new TrieNode('\0');
	}

private:
	void insertWord(TrieNode* root, string word)
	{
		if (word.empty()) return;
		int wordIdx = word[0] - 'a';
		if (root->children[wordIdx] == nullptr)
		{
			TrieNode *newNode = new TrieNode(word[0]);
			root->children[wordIdx] = newNode;
		}
		insertWord(root->children[wordIdx], word.substr(1));
	}

public:
	void insertWord(string word)
	{
		while (!word.empty())
		{
			insertWord(root, word);
			word = word.substr(1);
		}
	}

private:
	bool searchWord(TrieNode *root, string word)
	{
		if (word.empty()) return true;
		int wordIdx = word[0] - 'a';
		if (root->children[wordIdx] == nullptr)
			return false;
		return searchWord(root->children[wordIdx], word.substr(1));
	}

public:
	bool searchWord(string word)
	{
		return searchWord(root, word);
	}
};