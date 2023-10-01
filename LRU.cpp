
#include<iostream>
#include<list>
#include<unordered_map>
#include<algorithm>
using namespace std;

class LRUCache
{
	list<int> entries;
	unordered_map<int, list<int>::iterator> keyToPositionMap;
	int size;
public:
	LRUCache(int n) :size(n) {}
	void refer(int val)
	{
		if (keyToPositionMap.find(val) == keyToPositionMap.end())
		{
			if (entries.size() == size)
			{
				int last = entries.back();
				entries.pop_back();
				keyToPositionMap.erase(last);

			}

		}
		else
		{
			keyToPositionMap.erase(val);
		}

		entries.push_front(val);
		keyToPositionMap[val] = entries.begin();
	}

	void LRUDisplay()
	{
		for (auto it : entries)
		{
			cout << it;
		}
	}
};