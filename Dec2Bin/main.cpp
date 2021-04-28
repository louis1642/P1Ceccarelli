#include <iostream>

std::string recDec2Bin(int number){
    if(number==0){
        return "0";
    } else{
        return recDec2Bin(number/2) + std::to_string(number%2);
    }
};


int main() {
    int number;
    std::cout << "Enter a number: " << std::endl;
    std::cin>>number;
    std::cout << "Binary: " << recDec2Bin(number) << std::endl;
    return 0;
}
