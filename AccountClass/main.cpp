#include <iostream>
#include "Account.h"

int main() {
    Account acc;

    std::cout << "My account name is: " << acc.getName() << std::endl;

    std::cout << "Plese insert an account name: ";
    std::string newName;
    getline(std::cin,newName);

    acc.setName(newName);

    std::cout << "My account name is: " << acc.getName() << std::endl;

    return 0;
}
