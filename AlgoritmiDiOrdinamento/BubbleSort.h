#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include "Sorter.h"

class BubbleSort : public Sorter
{
public:
	explicit BubbleSort(std::vector<int>& items);
	virtual ~BubbleSort();

	virtual void sort();
};

#endif // !_BUBBLESORT_H_