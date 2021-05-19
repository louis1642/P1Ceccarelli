#include <iostream>
#include <sstream>

template <typename T>
DLinkedList<T>::DLinkedList(){
    header =new DNode<T>;
    trailer =new DNode<T>;
    header->next = trailer;
    header->prev = nullptr;
    trailer->prev = header;
    trailer->next = nullptr;
}

template <typename T>
DLinkedList<T>::~DLinkedList(){
    while(!(empty())) removeFront();
    delete header;
    delete trailer;
}

template <typename T>
bool DLinkedList<T>::empty() const{
    return (header->next == trailer);
}

template <typename T>
const T& DLinkedList<T>::front() const{
    return header->next->elem;
}

template <typename T>
const T& DLinkedList<T>::back() const{
    return trailer->prev->elem;
}

template <typename T>
void DLinkedList<T>::remove(DNode<T> *v){
    if(empty()) throw std::runtime_error("The list is empty");
    DNode<T> *u = v->prev;
    DNode<T> *w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

template <typename T>
void DLinkedList<T>::removeFront(){
    remove(header->next);
}

template <typename T>
void DLinkedList<T>::removeBack(){
    remove(trailer->prev);
}

template <typename T>
void DLinkedList<T>::add(DNode<T> *v, const T& e){
    DNode<T>* u =new DNode<T>;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}

template <typename T>
void DLinkedList<T>::addFront(const T& e){
    add(header->next, e);
}

template <typename T>
void DLinkedList<T>::addBack(const T& e){
    add(trailer, e);
}

template <typename T>
std::string DLinkedList<T>::toString(){
    std::ostringstream out;
    DNode<T> *u = header->next;
    out <<"Header <--> ";
    while(u!=trailer){
        out <<u->elem <<" <--> ";
        u = u->next;
    }
    out <<"Trailer";
    return out.str();
}