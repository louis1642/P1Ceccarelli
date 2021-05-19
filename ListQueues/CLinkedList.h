#ifndef CLINKED_LIST_H
#define CLINKED_LIST_H
#include <iostream>
#include "CNode.h"

template <typename T>
class CircleList{
    public:
        CircleList();
        ~CircleList();
        bool empty() const;
        const T& front() const;
        const T& back() const;
        void advance();
        void add(const T& e);
        void remove();
        std::string toString();
    private:
        CNode<T>* cursor;
};

#include "CLinkedList.cpp"
#endif