#include "SelectionSort.h"

/*

L’algoritmo selection sort è anche conosciuto come algoritmo per minimi successivi.
L’algoritmo ha una complessità esponenziale θ(n^2) sia nel caso peggiore sia nel caso migliore, quindi risulta essere poco efficiente.

*/

SelectionSort::SelectionSort(std::vector<int>& items) : Sorter(items)
{
	this->name = "Selection sort";
}

SelectionSort::~SelectionSort()
{
}

void SelectionSort::sort()
{
	std::vector<int>& a = this->getItems();
	int size = a.size();

	int i, j, min;

	//per ogni elemento fino al penultimo
	for (i = 0; i < size-2; i++) 
	{
		//salvo l'indice del primo ciclo
		min = i;

		//per ogni elemento
		for (j = i + 1; j < size-1; j++)
		{
			//se l'elemento è minore del valore dato dall'indice precedentemente salvato
			if (a[j] < a[min])
				//allora vuol dire che j ha un valore ancora minore
				min = j;
		}

		//ora che j avrà sicuramente un valore più piccolo, 
		//scambio con il precedente all'indice min
		int t = a[min];
		a[min] = a[i];
		a[i] = t;
	}
}
