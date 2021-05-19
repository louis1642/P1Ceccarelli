#include <iostream>
#include <string>
#include "Queue.h"

int main(){
    LinkedQueue<int> Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    std::cout <<Q.front() <<std::endl;
    Q.dequeue();
    std::cout <<Q.front() <<std::endl;
    Q.dequeue();
    std::cout <<Q.front() <<std::endl;
    Q.dequeue();
    return 0;
}