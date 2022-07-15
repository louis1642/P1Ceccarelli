#include "InsertionSort.h"

/*

si assume che i primi j-esimi elementi siano già ordinati e quindi il prossimo inserimento andrà nella posizione in modo da mantenere l'ordine 

caso migliore: Se l'array è già ordinato, il corpo del ciclo while non viene mai eseguito
	T(n)=an+b
		a = (c1, c2, c3, c4, c7)
		b = (c2, c3, c4, c7)

caso peggiore: Se l'array è ordinato in ordine inverso
	T(n) = an^2 + bn + c (a e b sono diversi dai precedenti)

caso medio: Il caso in cui mi trovo nel mezzo
	T(n) = an^2 + bn + c (a e b sono diversi dai precedenti)

*/

InsertionSort::InsertionSort(std::vector<int>& items) : Sorter(items)
{
	this->name = "Insertion sort";
}

InsertionSort::~InsertionSort()
{
}

void InsertionSort::sort()
{
	std::vector<int> &a = this->getItems();
	int size = this->getSize();

	//dalla seconda posizione fino all'ultima
	for (int j = 1; j < size; j++) 
	{
		//inizialmente il secondo elemento nella lista
		int key = a[j];
		//indice dell'elemento
		int i = j;

		//fino a quando non sono arrivato alla posizione iniziale
		//ed ho trovato la posizione dove poter inserire key
		while (i > 0 && a[i - 1] > key) 
		{
			//sposto di una posizione più a destra l'elemento
			a[i] = a[i - 1];
			//sottraggo
			i--;
		}

		//inserisco nella posizione i-esima l'elemento j-esimo
		a[i] = key;
	}
}
