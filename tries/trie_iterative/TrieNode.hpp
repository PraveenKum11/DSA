struct TrieNode
{
	int wordEndCnt;
	TrieNode* childNode[26];

	TrieNode()
	{
		wordEndCnt = 0;
		for (int i = 0; i < 26; i++)
		{
			childNode[i] = nullptr;
		}
	}
};