#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include "Sorter.h"

class QuickSort : public Sorter
{
private:
	void sort(std::vector<int>& a, int p, int q) const;
	int partition(std::vector<int>& a, int p, int r) const;
public:
	explicit QuickSort(std::vector<int>& items);
	virtual ~QuickSort();

	virtual void sort();
};

#endif // !_QUICKSORT_H_