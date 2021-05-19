template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList()
    : head(nullptr){
}

template <typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const{return head == nullptr; }

template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const{return head->elem; }

template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList(){while(!empty()) removeFront(); }

template <typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& e){
    Node<NODETYPE> *v =new Node<NODETYPE>;
    v->elem = e;
    v->next = head;
    head = v;
} 

template <typename NODETYPE>
void LinkedList<NODETYPE>::removeFront(){
    if(head == nullptr) throw std::invalid_argument{"List is empty"};
    Node<NODETYPE> *old = head;
    head = old->next;
    delete old;
}

template <typename NODETYPE>
size_t LinkedList<NODETYPE>::size() const{
    if(head == nullptr) throw std::invalid_argument{"List is empty"};
    Node<NODETYPE> *ptr = head;
    size_t c{1};
    while(!(ptr->next == nullptr)){
        c++;
        ptr = ptr->next;
    }
    return c;
}

template <typename NODETYPE>
NODETYPE& LinkedList<NODETYPE>::operator[](int i){
    if(head == nullptr) throw std::invalid_argument{"List is empty"};
    Node<NODETYPE> *ptr = head;
    for(int k=0; k<i; k++){
        ptr = ptr->next;
    }
    return ptr->elem;
}