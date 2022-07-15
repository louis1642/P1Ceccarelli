#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_

#include"Sorter.h"

class InsertionSort : public Sorter
{
public:
	explicit InsertionSort(std::vector<int>& items);
	virtual ~InsertionSort();

	virtual void sort();
};

#endif // !_INSERTIONSORT_H_