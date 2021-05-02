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
void quickSort(std::vector<T>& A, int p, int r);
//template <class T>
//void quickSort(std::vector<T>& A);

template <class T>
int partition(std::vector<T>& A, int p, int r);

template <class T>
void swap(std::vector<T>& A, int i, int j);





#endif //BIBLIOGRAPHY__QUICKSORT_H_
