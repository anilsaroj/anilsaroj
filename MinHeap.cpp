#include<iostream>
using namespace std;

class MinHeap
{
	int* harr;
	int hsize;
public:
	MinHeap(int a[], int size)
	{
		harr = a;
		hsize = size;
	}

	void buildHeap()
	{
		int i = (hsize - 1) / 2;
		while (i >= 0)
		{
			minHeapify(i);
			i--;
		}
	}

	int left(int i)
	{
		return 2 * i + 1;
	}

	int right(int i)
	{
		return 2 * i + 2;
	}

	void minHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < hsize && harr[l] < harr[i])
			smallest = l;
		if (r < hsize && harr[r] < harr[smallest])
			smallest = r;
		if (smallest != i)
		{
			swap(harr[i], harr[smallest]);
			minHeapify(smallest);
		}
	}
};