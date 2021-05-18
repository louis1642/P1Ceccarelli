//
// CircularlyLinkedList
// CircleList.h
// Created by Luigi Catello on 18/05/21.
// 
//

#ifndef CIRCULARLYLINKEDLIST__CIRCLELIST_H_
#define CIRCULARLYLINKEDLIST__CIRCLELIST_H_

#include "CNode.h"
#include <string>
#include <sstream>

template<typename T>
class CircleList {
 private:
  CNode<T>* cursor;
 public:
  CircleList();              // costruttore
  ~CircleList();             // distruttore
  bool isEmpty();           // true se la lista è vuota
  const T& front() const;   // elemento che segue il cursore
  const T& back() const;    // elemento al cursore
  void advance();           // fai avanzare la posizione del cursore
  void add(const T& e);     // aggiungi dopo il cursore
  void remove();            // rimuovi che segue il cursore
  std::string toString();   // stampa come stringa
};

template<typename T>
CircleList<T>::CircleList() : cursor{nullptr} {}

template<typename T>
CircleList<T>::~CircleList() {
    while (!isEmpty()) {
        remove();
    }
}

template<typename T>
bool CircleList<T>::isEmpty() {
    return (cursor == nullptr);
}

template<typename T>
const T & CircleList<T>::front() const {
    return cursor->next->elem;
}

template<typename T>
const T & CircleList<T>::back() const {
    return cursor->elem;
}

template<typename T>
void CircleList<T>::advance() {
    cursor = cursor->next;
}

template<typename T>
void CircleList<T>::add(const T &e) {
    auto* v = new CNode<T>;
    v->elem = e;

    if (isEmpty()) {
        // l'unico elemento nella lista è v!
        // quindi il successivo è di nuovo se stesso
        v->next = v;
        cursor = v;
    } else {
        // setto il puntatore next del nuovo elemento
        v->next = cursor->next;
        // inserisco il nuovo elemento nella catena
        cursor->next = v;
    }
}

template<typename T>
void CircleList<T>::remove() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot remove element: list is empty!");
    }
    CNode<T>* old = cursor->next;   // ad essere rimosso è l'elemento che segue il cursore
    if (old == cursor) {
        // c'è un solo elemento nella lista
        cursor = nullptr;
    } else {
        cursor->next = old->next;
    }
    delete old;
}

template<typename T>
std::string CircleList<T>::toString() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot print: list is empty!");
    }
    std::ostringstream out;
    CNode<T>* u = cursor;
    out << "Cursor --> ";
    out << u->elem << " --> ";
    u = u->next;
    while (u != cursor) {
        // devo eseguire questo stesso codice una volta prima di entrare nel ciclo:
        // infatti u == cursor, quindi il ciclo non sarebbe stato eseguito!
        out << u->elem << " --> ";
        u = u->next;
    }
    out << "Cursor";
    return out.str();
}







#endif //CIRCULARLYLINKEDLIST__CIRCLELIST_H_
