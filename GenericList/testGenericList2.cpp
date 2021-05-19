#include <iostream>
#include <string>
#include "LinkedList.h"

template <typename T>
void printFront(LinkedList<T>& L);

int main(){
    LinkedList<std::string> L;
    L.addFront("FCO");
    L.addFront("LAX");
    printFront(L);

    LinkedList<int> L2;
    L2.addFront(10);
    L2.addFront(20);
    printFront(L2);
}

template <typename T>
void printFront(LinkedList<T>& L){
    cout <<L.front() <<"\n";
}