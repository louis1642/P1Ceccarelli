#include "Node.h"
#include <iostream>

template <typename NODETYPE>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        bool empty() const;
        const NODETYPE& front() const;
        void addFront(const NODETYPE& e);
        void removeFront();
        size_t size() const;
        NODETYPE& operator[](int i);
    private:
        Node<NODETYPE>* head;
};

#include "LinkedList.cpp"