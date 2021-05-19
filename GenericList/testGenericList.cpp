#include <iostream>
#include <string>
#include "LinkedList.h"

int main(){
    LinkedList<std::string> L;
    L.addFront("FCO");
    L.addFront("LAX");
    std::cout <<L.front() <<"\n";
    std::cout <<"size L: " <<L.size() <<std::endl;

    LinkedList<int> L2;
    L2.addFront(10);
    L2.addFront(20);
    L2.addFront(25);
    std::cout <<L2.front() <<"\n";
    std::cout <<"size L2: " <<L2.size() <<std::endl;
    std::cout <<"L2[0]: " <<L2[0] <<std::endl;
    std::cout <<"L2[1]: " <<L2[1] <<std::endl;
    std::cout <<"L2[2]: " <<L2[2] <<std::endl;
}