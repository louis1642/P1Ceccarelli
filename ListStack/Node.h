#ifndef NODE_H
#define NODE_H

template <typename NODETYPE> class LinkedList;

template <typename NODETYPE>
class Node{
    private:
        NODETYPE elem;
        Node<NODETYPE> *next;

    friend class LinkedList<NODETYPE>;
};

#endif