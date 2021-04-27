/** 
* @file mergeTest.cpp
* @author Luigi Catello (lu.catello@studenti.unina.it)
* @brief test per algoritmo Merge Sort
* @version 0.1
* @date 2021-03-30
* 
* @copyright Copyright (c) 2021
* 
*/

#include <iostream>
#include <vector>

#include "merge.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printVector(const vector<int>& vect);

int main() {
    cout << "Vettore non ordinato:" << endl;
    vector<int> v{1, 123, 2, 4, 3, 43, 6, 98, 765};
    printVector(v);
    cout << '\n' << endl;
    mergeSort(v, 0, v.size()-1);
    cout << "Ora è ordinato:" << endl;
    printVector(v);
    cout << endl;
    return 0;
}

void printVector(const vector<int>& vect) {
    for (int element : vect) {
        // int è il tipo degli elementi di vect: il costrutto è un foreach
        cout << element << ' ';
    }
}
