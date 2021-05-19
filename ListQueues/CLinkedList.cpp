#include <iostream>
#include <sstream>

template <typename T>
CircleList<T>::CircleList()
    : cursor{nullptr}{    
}

template <typename T>
CircleList<T>::~CircleList(){while(!empty()) remove(); }

template <typename T>
bool CircleList<T>::empty() const{return cursor == nullptr; }

template <typename T>
const T& CircleList<T>::back() const{return cursor->elem; }

template <typename T>
const T& CircleList<T>::front() const{return cursor->next->elem; }

template <typename T>
void CircleList<T>::advance(){cursor = cursor->next; }

template <typename T>
void CircleList<T>::add(const T& e){
    CNode<T> *v =new CNode<T>;
    v->elem = e;
    if(cursor == nullptr){
        v->next = v;
        cursor = v;
    } else{
        v->next = cursor->next;
        cursor->next = v;
    }
}

template <typename T>
void CircleList<T>::remove(){
    CNode<T> *old = cursor->next;
    if(old == cursor){
        cursor = nullptr;
    } else{
        cursor->next = old->next;
    }
    delete old;
}

template <typename T>
std::string CircleList<T>::toString(){
    std::ostringstream out;
    CNode<T> *u =cursor;
    out <<"Cursor --> ";
    out <<u->elem <<" --> ";
    u = u->next;
    while(u != cursor){
        out <<u->elem <<" --> ";
        u = u->next; 
    }
    out <<"Cursor";
    return out.str();
}