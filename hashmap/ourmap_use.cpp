#include "OurMap.hpp"

int main()
{
	OurMap<int> omp;
	for (int i = 0; i < 10; i++)
	{
		char c = i + '0';
		string key = "abc";
		key += c;
		int value = i + 1;
		omp.insert(key, value);
		// cout << omp.getLoadFactor() << endl;
	}

	cout << omp.size() << endl;
	omp.remove("abc4");
	omp.remove("abc7");
	cout << omp.size() << endl;

	for (int i = 0; i < 10; i++)
	{
		char c = i + '0';
		string key = "abc";
		key += c;
		cout << key << " : " << omp.getValue(key) << endl;
	}
}