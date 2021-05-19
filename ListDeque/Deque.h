#include "DLinkedList.h"

template <typename T>
class LinkedDeque{
    public:
        LinkedDeque();
        int size() const;
        bool empty() const;
        const T& front();
        const T& back();
        void insertFront(const T& e);
        void insertBack(const T& e);
        void removeFront();
        void removeBack();
    private:
        DLinkedList<T> D;
        int n;
};

template <typename T>
void LinkedDeque<T>::insertFront(const T& e){
    D.addFront(e);
    n++;
}

template <typename T>
void LinkedDeque<T>::insertBack(const T& e){
    D.addBack(e);
    n++;
}

void LinkedDeque::removeFront(){
    if(empty()) throw std::runtime_error("deque empty");
    D.removeFront();
    n--; 
}

void LinkedDeque::removeBack(){
    if(empty()) throw std::runtime_error("deque empty");
    D.removeBack();
    n--;
}