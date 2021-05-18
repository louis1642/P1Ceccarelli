//
// CircularlyLinkedList
// CNode.h
// Created by Luigi Catello on 18/05/21.
// 
//

#ifndef CIRCULARLYLINKEDLIST__CNODE_H_
#define CIRCULARLYLINKEDLIST__CNODE_H_

template<typename T>
class CircleList;

template<typename T>
class CNode {
 private:
  T elem;
  CNode* next;
  friend class CircleList<T>;
};

#endif //CIRCULARLYLINKEDLIST__CNODE_H_
