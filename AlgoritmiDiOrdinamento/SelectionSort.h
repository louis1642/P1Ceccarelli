#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_

#include "Sorter.h"

class SelectionSort : public Sorter
{
public:
	explicit SelectionSort(std::vector<int>& items);
	virtual ~SelectionSort();

	virtual void sort();
};

#endif // !_SELECTIONSORT_H_