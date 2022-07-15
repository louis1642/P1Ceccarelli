#include "MergeSort.h"
#include <iostream>

/*
Sfrutta la tecnica divide et impera, ovvero la suddivisione del problema in sotto-problemi della stessa natura
di dimensione a mano a mano sempre pi� piccola, li risolve ricorsivamente e infine combina le soluzioni parziali
per ottenere la soluzione al problema di partenza.

a � il vettore
p � il punto di partenza
r il punto di arrivo

complessit� nlog n
tempo di esecuzione O(r-p+1), ovvero il numero di elementi da scorrere
analisi: 
Essendo ricorsivo abbiamo che:
T(n) = 2T(n/2)+O(n) con n > 1
T(n) = O(1)			con n = 1

Il tempo di esecuzione � nlog n perch� nlog � data dalla ricorsione ed n dal fatto che ogni volta che si splitta il vettore, si ha come somma sempre n
*/
MergeSort::MergeSort(std::vector<int> items)
	: Sorter(items)
{
	this->name = "MergeSort";
}

void MergeSort::sort()
{
	int p = 0;
	int r = this->getSize() - 1;
	std::vector<int>&a = this->getItems();

	this->sort(a, p, r);
}

/*
*@brief divide il vettore a in due pezzi e chiama se stessa sulle due met� 
* 
*@param p il punto iniziale del vettore su cui lavorare
*@param r il punto finale del vettore su cui lavorare
*/
void MergeSort::sort(std::vector<int> &a, int p, int r) const
{
	int q; //variabile temporanea

	//se � presente almeno un elemento
	if (p < r)
	{
		//p = alla posizione che si trova a met� tra p ed r
		q = (p + r) / 2;

		//ricorsione per la parte che va da p a q (iniziale)
		sort(a, p, q);

		//ricorsione per la parte che va da p+1 a q (finale)
		sort(a, q+1, r);

		//unisce le parti separate
		merge(a, p, q, r);
	}

	return;
}

/*
* @brief fonde due sequenze ordinate in un'unica sequenza ordinata
*
* @param p punto iniziale
* @param r punto di termine
* @param q punto di separazione tra le due sequenze
*/
void MergeSort::merge(std::vector<int> &a, int p, int q, int r) const
{
	//istanzio un vettore di appoggio STATICO per evitare nuove istanze ad ogni ciclo
	static std::vector<int> c(a.size());
	
	int i = p;
	int k = p;
	int j = q + 1;

	//Fino a quando i non spulcia la prima met� (iniziale) e j la seconda (finale)
	while (i <= q && j <= r)
	{
		//Se l'elemento i-esimo (parte iniziale) � minore dell'elemento j-esimo (parte finale)
		if (a[i] < a[j])
		{
			//Inserisco nella posizione k (che coincide inizialmente con il punto iniziale), l'elemento i-esimo
			//Questo perch� in i ho un valore minore rispetto j
			c[k] = a[i];

			//incremento
			k++;
			i++;
		}
		else
		{
			//In caso contrario, essendo l'elemento j-esimo pi� piccolo, lo inserico in k
			c[k] = a[j];

			//Incremento
			k++;
			j++;
		}
	}

	//Quando il ciclo precedente termina, ci saranno valori non non ancora inseriti in c
	//Quindi inserisco la parte rimanente per la met� iniziale
	while (i <= q)
	{
		c[k] = a[i];
		k++;
		i++;
	}

	//Stessa, cosa che accade nel ciclo precedente, ma questa volta riferito alla met� finale
	while (j <= r)
	{
		c[k] = a[j];
		k++;
		j++;
	}

	//ricopio gli elementi nel vettore a, cos� da averlo ordinato
	for (int i = p; i < k; i++)
	{
		a[i] = c[i];
	}
}