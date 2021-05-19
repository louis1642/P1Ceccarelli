template <typename T> class CircleList;

template <typename T>
class CNode{
    private:
        T elem;
        CNode* next;
        friend class CircleList<T>;
};