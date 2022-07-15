#include "QuickSort.h"

/*
Sfrutta la tecnica divide et impera, ovvero la suddivisione del problema in sotto-problemi della stessa natura
di dimensione a mano a mano sempre pi� piccola, li risolve ricorsivamente e infine combina le soluzioni parziali
per ottenere la soluzione al problema di partenza.

a � il vettore
p � il punto di partenza
r il punto di arrivo

complessit� nlog n
tempo di esecuzione peggiore O(n^2)
caso medio e migliore nlog n

caso migliore: l'elemento pivot si trovi a met� e quindi avremo due liste bilanciate
	Con Partition con die regioni uguale (ciascuna con n/2 elementi), l'ordinamento sar� pi� veloce
	T(n) = 2T(n/2)+O(n) = O(n log n)

caso peggiore: si ha quando l'input � ordinato o ordinato in ordine inverso
	partition produce una regione con n-1 elementi ed una con n=1 (tutti a sinistra o destra tranne uno)
	Ad ogni passo avremo T(n) = T(n-1)+O(n) = O(n^2)

	Per ovviare, il pivot viene scelto non all'inizio, ma in una posizione randomica.

caso medio: anche se non abbiamo un array ordinato, anche se le partizioni sono sbilanciate (90% a sinistra e 10% a destra), 
	comunque dividiamo n per 10/9 che � costante e quindi abbiamo una equazione logaritmica come per il caso migliore.
	allora T(n) = O(n log n)

Vantaggio: nordinamento in place, non necessita di ulteriore memoria (come per il merge sort)
	fattori costanti bassi

"si spostano tutti valori pi� piccoli a sinistra e tutti i pi� grandi a destra"
l'indice q � calcolato.
Non � necessaria alcuna combinazione perch� gli elementi di sinistra sono gi� minori di quelli di destra e, una volta ordinati, lo saranno nell'intero vettore

analisi:
La procedura scorre tutti gli elementi di a[p..r] una sola volta
La complessit� di partition sar� O(n) con n = r - p + 1

Il tempo di esecuzione � nlog n perch� nlog � data dalla ricorsione ed n dal fatto che ogni volta che si splitta il vettore, si ha come somma sempre n
*/
QuickSort::QuickSort(std::vector<int>& items) : Sorter(items)
{
	this->name = "Quick sort";
}

QuickSort::~QuickSort()
{
}

void QuickSort::sort()
{
	std::vector<int>& a = this->getItems();

	int p = 0;
	int r = a.size() - 1;

	sort(a, p, r);
}

/*
*@brief ricerca una partizione
*
*@param p il punto iniziale del vettore su cui lavorare
*@param r il punto finale del vettore su cui lavorare
*/
void QuickSort::sort(std::vector<int>& a, int p, int r) const
{
	//se � presente almeno un elemento
	if (p < r)
	{
		//la funzione partition sposta gli elementi pi� grandi a destra e quelli 
		//pi� piccoli a sinistra e si posiziona tra i due. 
		//Tutti gli elementi che si trovano tra p e q saranno minori di tutti quelli che 
		//vanno da q + 1 ed r
		int q = partition(a, p, r);

		//ricorsione per la prima partizione
		//l'array si ordina separatamente
		sort(a, p, q);

		//ricorsione per la seconda
		//l'array si ordina separatamente
		sort(a, q + 1, r);
	}
}

//Sposta gli elementi a sinistra o a destra se sono uguali ad un certo valore
int QuickSort::partition(std::vector<int>& a, int p, int r) const
{
	//elemento pivot
	//tutti gli elementi che sono <= del pivot vanno a sinistra, altrimenti a destra
	//si sceglie uno a caso, come il primo, ad esempio
	int x = a[p];   
	//parte pi� a sinistra del pivot
	int i = p - 1;
	//parte pi� a destra dell'ultimo elemento dell'array
	int j = r + 1;

	//sposto l'indice di sinistra verso destra e quello di destra verso sinistra
	//fino a trovare un elemento che
	//a sinistra sia >= del pivot 
	//a destra <= del pivot

	//il ciclo va fino a quando i < j
	while (true) 
	{
		//sposto l'indice di destra, j, pi� a sinistra
		do
			j = j - 1;
		//se un elemento � minore o uguale del pivot, mi fermo
		//se non ci sta, significa che � tornato indietro fino al pivot e quindi esce
		while (a[j] > x);

		//sposto l'indice di sinistra, i, verso destra
		do
			i = i + 1;
		//cerca il primo elemento da sinistra che sia maggiore o uguale al pivot
		while (a[i] < x);

		if (i < j)
			//se l'array non � stato scandito completamente, si scambiano a[i] con a[j]
			swap(a, i, j);
		else
			//altrimenti tutti gli elementi che sono <= al pivot sono gi� stati spostati a sinistra
			//i e j si sono sovrapposti e j non pu� andare pi� a sinistra
			return j;
	}
}