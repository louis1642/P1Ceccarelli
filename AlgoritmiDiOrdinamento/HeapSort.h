#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

#include "Sorter.h"

class HeapSort : public Sorter
{
private:
	void heapify(std::vector<int>& items, int size, int i) const;
	void buildHeap(std::vector<int>& a) const;
public:
	explicit HeapSort(std::vector<int>& items);
	virtual ~HeapSort();

	void sortPriorityQueue();
	virtual void sort();
};

#endif