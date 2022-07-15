#include "HeapSort.h"

#include<queue>

/*

Sfrutta una struttura dati heap per migliorare il selection sort e rende il tempo di esecuzione ottimale
Si basa sull'interazione dei seguenti passi:
	- Trasforma il vettore in uno heap (build-heap con tempo di esecuzione O(n))
	- Scambia il primo elemento (che è il più grande sicuramente)
	- Riduce la dimensione dello heap di 1
	- Ripete dall'inizio

Il tempo di esecuzione è O(n log n), come per il merge sort
Non richiede memoria aggiuntava come per il mergesort  
Non è ricorsivo come il quickSort e mergesort, ma iterativo

Sfrutta operazioni di:
- push, inserimento
- top, restituisce l'elemento s con chiave maggiore
- pop, rimuove l'elemento con chiave maggiore

priority_queue è un template che sfrutta questi metodi.
Si deve includere "queue"

L'implementazione della priority_queue è basata sullo heap.
L'heap è un albero binario che può essere rappresentato senza lista a puntatori ma per array.
Ha la proprietà che il valore di ciascun nod è maggiore a quello dei suoi figli.
L'albero binario è un insieme di nodi definito ricorsivamente. la sua profondità sarà k=(log n+1)

la funzione heapify ci consente di avere un albero ordinato e assume che ci siano heap nel sottoalbero di destra e sinistra
e costruisce un heap unendo i due sottoalberi. 
T(n) = O(log n) perchè si basa sulla profondità dell'albero

Come si costruisce un heap? tramite un build-heap.
Parte da n/2, ovvero il primo nodo che può avere dei figli.
Tutto quello che si trova in n/2 + 1 è "vuoto" perchè non ha sicuramente figli
Il tempo di esecuzione è O(n)

Tempo migliore: nlog n
Tempo medio: n log n
Tempo peggiore: n log n

*/


HeapSort::HeapSort(std::vector<int>& items) : Sorter(items)
{
	this->name = "Heap sort";
}

HeapSort::~HeapSort()
{
}

void HeapSort::sortPriorityQueue()
{
	std::vector<int>& a = this->getItems();
	int size = this->getSize();

	//la particolarità è che mette a disposizione metodi per prelevare i valori con chiave maggiore 
	//Significa che potrò prelevare il valore più grande inserito con la semplice chiamata top()
	std::priority_queue<int> pq;

	//inserico gli elementi all'interno del queue
	for (int i = 0; i < size; i++)
		pq.push(a[i]);

	//riutilizzo la variabile di appoggio size che scalo perchè altrimenti troppo grande
	size--;

	//fino a quando pq non è vuota
	while (!pq.empty())
	{
		//assegno all'ultimo elemento della lista il valore più grande di pq
		a[size--] = pq.top();

		//elimino da pq il valore
		pq.pop();
	}
}

void HeapSort::sort()
{
	std::vector<int>& a = this->getItems();
	int size = a.size();

	//build heap
	buildHeap(a);

	//fino a 2 perchè oltre non dobbiamo ordinarlo
	for (int i = size - 1; i > 0; i--)
	{
		//in a[0] ho il massimo, quindi scambio a[0] con a[i]
		//metto il massimo nell'ultima posizione
		int tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;

		//richiamo heapify perchè ho rispettato il vincolo che ci siano heap
		heapify(a, i, 0);
	}
}

void HeapSort::heapify(std::vector<int>& a, int size, int i) const
{
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;
	int largest = i;

	//Controllo se lo head a sinistra ha un valore maggiore del valore i-esimo
	if (l < size && a[l] > a[largest])
		//se è maggiore, allora lo dovrò scambiare e mi salvo l'indice
		largest = l;

	//Controllo se lo head a destra ha un valore maggiore del valore largest assegnato in precedenza
	if (r < size && a[r] > a[largest])
		//nel caso dovrò scambiarlo
		largest = r;

	//Se bisogna sostituire
	if (largest != i)
	{
		//Scambio il valore i-esimo con largest-esimo
		int tmp = a[i];
		a[i] = a[largest];
		a[largest] = tmp;

		//ricorsione
		heapify(a, size, largest);
	}
}

void HeapSort::buildHeap(std::vector<int>& a) const
{
	int size = a.size();

	//size / 2 corrisponde alla posizione dell'ultimo elemento con figlio
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(a, size, i);
}
