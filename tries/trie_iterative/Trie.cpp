#include "TrieNode.hpp"

class Trie
{
	TrieNode* root;

public:
	Trie() : root(new TrieNode)
	{}

	TrieNode* insertKey(std::string key)
	{
		TrieNode* currentNode = root;
		int n = key.size();

		for (int i = 0; i < n; i++)
		{
			if (currentNode->childNode[key[i] - 'a'] == nullptr)
			{
				TrieNode* newNode = new TrieNode();
				currentNode->childNode[key[i] - 'a'] = newNode;
			}
			currentNode = currentNode->childNode[key[i] - 'a'];
		}
		currentNode->wordEndCnt++;
		return root;
	}

	bool searchKey(std::string key)
	{
		TrieNode* currentNode = root;
		int n = key.size();

		for (int i = 0; i < n; i++)
		{
			if (currentNode->childNode[key[i] - 'a'] == nullptr)
			{
				return false;
			}
			currentNode = currentNode->childNode[key[i] - 'a'];
		}
		return currentNode != nullptr && currentNode->wordEndCnt > 0;
	}

	bool deleteKey(std::string key)
	{
		TrieNode* currentNode = root;
		int n = key.size();

		for (int i = 0; i < n; i++)
		{
			if (currentNode->childNode[key[i] - 'a'] == nullptr)
			{
				return false;
			}
			currentNode = currentNode->childNode[key[i] - 'a'];
		}

		if (currentNode != nullptr && currentNode->wordEndCnt > 0)
		{
			currentNode->wordEndCnt--;
			return true;
		}
		return false;
	}
};

