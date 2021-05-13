//
// GenericLinkedList
// LinkedList.h
// Created by Luigi Catello on 13/05/21.
// 
//

#ifndef GENERICLINKEDLIST__LINKEDLIST_H_
#define GENERICLINKEDLIST__LINKEDLIST_H_

#include "Node.h"
#include <iostream>

template<typename NODETYPE>
class LinkedList {
 private:
  Node<NODETYPE>* head;
 public:
  LinkedList();                         // costruttore
  ~LinkedList();                        // distruttore
  bool isEmpty() const;                 // true se la lista è vuota
  const NODETYPE& front() const;        // elemento front
  void addFront(const NODETYPE &elem);  // aggiungi un elemento in cima
  void removeFront();                   // rimuovi il primo elemento

};

#include "LinkedList.cpp"       // devo includerlo qui perchè la classe è un template!
                                // se non facessi così non sarebbe compilato il .cpp

#endif //GENERICLINKEDLIST__LINKEDLIST_H_
