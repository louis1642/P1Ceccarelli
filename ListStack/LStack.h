#ifndef LSTACK_H
#define LSTACK_H
#include "LinkedList.h"
#include <stdexcept>

template <typename E>
class LinkedStack{
    public:
        LinkedStack();
        int size() const;
        bool empty() const;
        const E& top();
        void push(const E& e);
        void pop();
    private:
        LinkedList<E> S;
        int n;
};

template <typename E>
LinkedStack<E>::LinkedStack()
    : S(), n{0}{
}

template <typename E>
int LinkedStack<E>::size() const{return n; }

template <typename E>
bool LinkedStack<E>::empty() const{return n == 0; }

template <typename E>
const E& LinkedStack<E>::top(){
    if(empty()) throw std::runtime_error("Top of empty stack");
    return S.front();
}

template <typename E>
void LinkedStack<E>::push(const E& e){
    ++n;
    S.addFront(e);
}

template <typename E>
void LinkedStack<E>::pop(){
    if(empty()) throw std::runtime_error("Pop from empty stack");
    --n;
    S.removeFront();
}

#endif