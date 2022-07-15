#include "PriorityQueue.h"

#include <queue>
#include <iostream>

PriorityQueue::PriorityQueue(std::vector<int>& items) : Sorter(items)
{
	this->name = "Priority Queue Sort";
}

PriorityQueue::~PriorityQueue()
{
}

void PriorityQueue::sort()
{
	//O(n log n)

	std::vector<int>& a = this->getItems();
	int size = this->getSize();

	//la particolarità è che mette a disposizione metodi per prelevare i valori con chiave maggiore 
	//Significa che potrò prelevare il valore più grande inserito con la semplice chiamata top()
	std::priority_queue<int> pq;

	//inserico gli elementi all'interno del queue
	for (int i = 0; i < size; i++)
		pq.push(a[i]);

	//fino a quando pq non è vuota o size è > 0
	while (size > 0)
	{
		//assegno all'ultimo elemento della lista il valore più grande di pq
		a[--size] = pq.top();

		//elimino da pq il valore
		pq.pop();
	}
}
