//
// Bibliography
// QuickSort.h
// Created by Luigi Catello on 02/05/21.
// 
//

#ifndef BIBLIOGRAPHY__QUICKSORT_H_
#define BIBLIOGRAPHY__QUICKSORT_H_


#include <vector>

template <class T>
void quickSort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q);
        quickSort(A, q+1, r);
    }
}
//template <class T>
//void quickSort(std::vector<T>& A);

template <class T>
int partition(std::vector<T>& A, int p, int r) {
    T pivot = A.at(p);
    int i = p-1;
    int j = r+1;
    while (true) {
        do {
            j--;
        } while (A.at(j) > pivot);
        do {
            i++;
        } while (A.at(i) < pivot);
        if (i < j) {
            swap(A, i, j);
        } else {
            return j;
        }
    }
}
template <class T>
void swap(std::vector<T>& A, int i, int j) {
    T temp = A.at(i);
    A.at(i) = A.at(j);
    A.at(j) = temp;
}




#endif //BIBLIOGRAPHY__QUICKSORT_H_
