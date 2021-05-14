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
  int size();                           // lunghezza della lista
  NODETYPE operator[](int i);           // l'i-esimo elemento della lista

};



// costruttore
template<typename NODETYPE>
LinkedList<NODETYPE>::LinkedList() : head{nullptr} {
}

// distruttore
template<typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList() {
    while (!isEmpty()) {
        removeFront();
    }
}

template<typename NODETYPE>
bool LinkedList<NODETYPE>::isEmpty() const {
    return (head == nullptr);
    // se la lista è vuota la testa punta al nulla
}

template<typename NODETYPE>
const NODETYPE & LinkedList<NODETYPE>::front() const {
    return head->element;
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& elem) {
    auto* v = new Node<NODETYPE>;       // creo il nodo
    v->element = elem;                  // conservo il dato
    v->next = head;                     // collego alla lista
    head = v;                           // reindirizzo l'head
}

template<typename NODETYPE>
void LinkedList<NODETYPE>::removeFront() {
    if (isEmpty()) {
        throw std::invalid_argument("List is empty!");
    }
    Node<NODETYPE>* old = head;         // identifico la testa (da eliminare)
    head = old->next;                   // reindirizzo l'head
    delete old;                         // cancello il vecchio elemento
}

template<typename NODETYPE>
int LinkedList<NODETYPE>::size() {
    int count = 1;
    Node<NODETYPE>* n = head;
    while (n->next != nullptr) {
        n = n->next;
        ++count;
    }
    return count;
}

template<typename NODETYPE>
NODETYPE LinkedList<NODETYPE>::operator[](int i) {
    if (i >= size()) {
        throw std::invalid_argument("Reached end of list!");
    }
    Node<NODETYPE>* n = head;
    for (int j = 0; j < i; ++j) {
        n = n->next;
    }
    return n->element;
}

#endif //GENERICLINKEDLIST__LINKEDLIST_H_
