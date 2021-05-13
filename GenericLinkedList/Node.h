//
// GenericLinkedList
// Node.h
// Created by Luigi Catello on 13/05/21.
// 
//

#ifndef GENERICLINKEDLIST__NODE_H_
#define GENERICLINKEDLIST__NODE_H_
// nomino la classe LinkedList<NODETYPE> per poterla definire come friend
template<typename NODETYPE> class LinkedList;

template <typename NODETYPE>
class Node {
 private:
  NODETYPE element;
  Node<NODETYPE>* next;

  friend class LinkedList<NODETYPE>;
};


#endif //GENERICLINKEDLIST__NODE_H_
