#include "MergeSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "BubbleSort.h"
#include "PriorityQueue.h"

#include <vector>
#include <iostream>

void sort(Sorter& s);

int main()
{
	std::vector<int> items {0, 2, 5, 6, 1, 3};
	
	MergeSort ms(items);
	InsertionSort is(items);
	SelectionSort ss(items);
	QuickSort qs(items);
	BubbleSort bs(items);
	HeapSort hs(items);
	PriorityQueue pq(items);

	std::vector<Sorter*> sorters {&ms, &is, &ss, &qs, &hs, &bs, &pq};

	std::cout << "Vettore originale:" << std::endl;
	ms.printItems(items);
	std::cout << std::endl;

	for (Sorter* s : sorters)
		sort(*s);
}

void sort(Sorter& s)
{
	s.printDescription();
	s.sort();
	s.printItems();

	std::cout << std::endl;
}