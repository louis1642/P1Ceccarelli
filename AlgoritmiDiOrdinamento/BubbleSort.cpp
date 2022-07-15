#include "BubbleSort.h"

/*

Il bubble sort è l’algoritmo di ordinamento più semplice da implementare, ma è anche poco efficiente.
Consiste nel confrontare elementi vicini tra loro portando l’elemento maggiore in ultima posizione 
durante la prima “passata” (eseguendo n-1 confronti), poi il secondo massimo in penultima posizione e così via finché l’array non è ordinato.

La complessità è O(n^2), sia nel caso peggiore che nel caso migliore.

*/

BubbleSort::BubbleSort(std::vector<int>& items) : Sorter(items)
{
	this->name = "Bubble sort";
}

BubbleSort::~BubbleSort()
{
}

void BubbleSort::sort()
{
	std::vector<int>& a = this->getItems();
	int size = this->getSize();

	//per ogni elemento
	for (int j = 0; j < size - 1; j++)
	{
		//per ogni elemento
		for (int i = 0; i < size - 1; i++)
		{
			//se l'elemento i-esimo è maggiore del successivo
			if (a[i] > a[i + 1])
			{
				//scambio i valori
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
}
