#include "BubbleSort.h"

/*

Il bubble sort � l�algoritmo di ordinamento pi� semplice da implementare, ma � anche poco efficiente.
Consiste nel confrontare elementi vicini tra loro portando l�elemento maggiore in ultima posizione 
durante la prima �passata� (eseguendo n-1 confronti), poi il secondo massimo in penultima posizione e cos� via finch� l�array non � ordinato.

La complessit� � O(n^2), sia nel caso peggiore che nel caso migliore.

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
			//se l'elemento i-esimo � maggiore del successivo
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
