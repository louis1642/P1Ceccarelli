//
// DoubleLinkedList
// DNode.h
// Created by Luigi Catello on 14/05/21.
// 
//

#ifndef DOUBLELINKEDLIST__DNODE_H_
#define DOUBLELINKEDLIST__DNODE_H_

template<typename T> class DLinkedList;

template<typename T>
class DNode {
 private:
  T element;
  DNode<T>* next;
  DNode<T>* prev;
  friend class DLinkedList<T>;
};

#endif //DOUBLELINKEDLIST__DNODE_H_
