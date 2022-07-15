#include "Sorter.h"
#include <vector>

#ifndef _MERGESORT_H_
#define _MERGESORT_H_

class MergeSort : public Sorter
{
private:
	void merge(std::vector<int> &a, int p, int r, int q) const;

public:
	explicit MergeSort(std::vector<int> items);

	virtual void sort() override;
	void sort(std::vector<int> &a, int p, int r) const;
};

#endif // !_MERGESORT_H_