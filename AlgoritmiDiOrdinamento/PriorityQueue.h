#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_

#include "Sorter.h"

class PriorityQueue : public Sorter
{
public: 
	explicit PriorityQueue(std::vector<int>&);
	virtual ~PriorityQueue();

	virtual void sort();
};

#endif // !_PRIORITY_QUEUE_