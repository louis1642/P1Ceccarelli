template <typename T> class DLinkedList;

template <typename T> 
class DNode{
    private:
        T elem;
        DNode *prev;
        DNode *next;
        friend class DLinkedList<T>;
};