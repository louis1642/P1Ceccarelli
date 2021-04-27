/** 
* @file merge.cpp
* @author Luigi Catello (lu.catello@studenti.unina.it)
* @brief implementation of Merge Sort Algorithm
* @version 0.1
* @date 2021-03-30
* 
* @copyright Copyright (c) 2021
* 
*/

#include <vector>

// signature della funzione merge - dato che in mergeSort() è chiamata marge(),
// abbiamo bisogno di scrivere la signature sopra
void merge(std::vector<int>& a, int p, int r, int q);

/** 
* @brief splitta il vettore a in due pezzi e chiama se stessa sulle due metà
* 
* @param a il vettore su cui lavorare
* @param p il punto iniziale del vettore su cui lavorare
* @param r il punto finale del vettore su cui lavorare
*/
void mergeSort(std::vector<int>& a, int p, int r) {
    int q = 0;
    if (p < r) {
        q = (p+r)/2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, r, q);
    }
}

/** 
* @brief fonde due sequenze ordinate in un'unica sequenza ordinata
* 
* @param a il vettore contenente le due sequenze
* @param p punto iniziale
* @param r punto di termine
* @param q punto di separazione tra le due sequenze
*/
void merge(std::vector<int>& a, int p, int r, int q) {
    int i, j, k;
    // c è dichiarato come static per non doverlo inizializzare ogni volta - pensa
    // se a avesse dimensione 1000!
    static std::vector<int> c(a.size());
    i = p;
    k = p;
    j = q+1;
    // questo primo ciclo confronta elemento per elemento le due sequenze, prendendo
    // di volta in volta l'elemento maggiore e copiandolo in c
    while (i <= q && j <= r) {
        if(a[i] < a[j]) {
            c[k] = a[i];
            k++;
            i++;
        } else {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    // quando il primo ciclo avrà finito, una delle due sequenze avrà valori avanzati. 
    // questi due cicli while completano la copia dalle sequenze in c
    while (i <= q) {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= r) {
        c[k] = a[j];
        k++;
        j++;
    }
    // ora che c è effettivamente l'unione ordinata delle due sequenze, viene
    // ricopiato in a - elemento per elemento
    for (i = p; i < k; i++) {
        a[i] = c[i];
    }
}