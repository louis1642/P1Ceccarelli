//
// DoubleLinkedList
// DLinkedList.h
// Created by Luigi Catello on 14/05/21.
// 
//

#ifndef DOUBLELINKEDLIST__DLINKEDLIST_H_
#define DOUBLELINKEDLIST__DLINKEDLIST_H_

#include <string>
#include <sstream>
#include "DNode.h"

template<typename T>
class DLinkedList {
 private:
  DNode<T>* header;                     // sentinelle
  DNode<T>* trailer;
 protected:                             // funzioni utili
  void add(DNode<T>* v, const T& e);    // inserisci l'elemento 'e' prima di 'v'
  void remove(DNode<T>* v);             // rimuovi il nodo 'v'
 public:
  DLinkedList();                        // costruttore
  ~DLinkedList();                       // distruttore
  bool isEmpty() const;                 // true se la lista è vuota
  const T& front() const;               // front element
  const T& back() const;                // back element
  void addFront(const T& elem);               // aggiungi elemento al front
  void addBack(const T& elem);                // aggiungi elemento al back
  void removeFront();                   // rimuove elemento dal front
  void removeBack();                    // rimuove elemento dal back
  std::string toString();               // converte in stringa

};

template<typename T>
DLinkedList<T>::DLinkedList() {
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    header->prev = nullptr;
    trailer->next = nullptr;
    trailer->prev = header;
}

template<typename T>
DLinkedList<T>::~DLinkedList() {
    while (!isEmpty()) {
        removeFront();
    }
    delete header;
    delete trailer;
}

template<typename T>
bool DLinkedList<T>::isEmpty() const {
    return (header->next == trailer);
}

template<typename T>
const T & DLinkedList<T>::front() const {
    return header->next->element;
}

template<typename T>
const T & DLinkedList<T>::back() const {
    return trailer->prev->element;
}

template<typename T>
void DLinkedList<T>::addFront(const T &elem) {
    add(header->next, elem);
}

template<typename T>
void DLinkedList<T>::addBack(const T &elem) {
    add(trailer, elem);
}

template<typename T>
void DLinkedList<T>::add(DNode<T> *v, const T &e) {
    // creo un nuovo nodo
    auto *u = new DNode<T>;
    u->element = e;

    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

template<typename T>
void DLinkedList<T>::removeFront() {
    remove(header->next);
}

template<typename T>
void DLinkedList<T>::removeBack() {
    remove(trailer->prev);
}

template<typename T>
void DLinkedList<T>::remove(DNode<T> *v) {
    if (isEmpty()) {
        throw std::runtime_error("List is empty!");
    }
    DNode<T>* u = v->prev;
    DNode<T>* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

template<typename T>
std::string DLinkedList<T>::toString() {
    std::ostringstream out;
    DNode<T> *u = header->next;
    out << "Header <--> ";
    while (u != trailer) {
        out << u->element << " <--> ";
        u = u->next;
    }
    out << "Trailer";
    return out.str();
}
#endif //DOUBLELINKEDLIST__DLINKEDLIST_H_
