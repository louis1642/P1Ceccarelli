// demostrante command line arguments
#include <iostream>

int main(int argc, char** argv) {
    std::cout << "This is the program " << argv[0] << "\n";
    std::cout << "You specified " << argc << " arguments:" << std::endl;
    std::cout << "Hello ";
    for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << " ";
    }

    std::cout << "\n";

}