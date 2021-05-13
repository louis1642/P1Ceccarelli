//
// GenericLinkedList
// LinkedList.cpp
// Created by Luigi Catello on 13/05/21.
// 
//

// #include non è necessario in quanto questo file è incluso nel .h
#include "LinkedList.h"

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









