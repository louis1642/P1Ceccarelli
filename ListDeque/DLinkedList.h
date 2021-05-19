#include "DNode.h"
#include <iostream>

template <typename T>
class DLinkedList{
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const T& front() const;
        const T& back() const;
        void addFront(const T& e);
        void addBack(const T& e);
        void removeFront();
        void removeBack();
        std::string toString();
    private:
        DNode<T> *header;
        DNode<T> *trailer;
    protected:
        void add(DNode<T> *v, const T& e);
        void remove(DNode<T> *v);
};

#include "DLinkedList.cpp"