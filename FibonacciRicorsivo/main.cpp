#include <iostream>

int main() {

    unsigned int x{1};
    unsigned int y{1};
    unsigned int next;

    std::cout << x << std::endl;

    while (true){
        std::cout << y << std::endl;
        next = x + y;
        x = y;
        y = next;
    }

    return 0;
}
