#include <iostream>
#include <array>
#include <iomanip>
#include <cstdlib>

int main() {

    const size_t arraySize{6};          //size_t è consigliato per gli array
    std::array<int,arraySize> frequency{};

    for (unsigned int roll{1};roll<=600000;roll++){
        frequency[rand() % 6]++;
    }

    std::cout << "Face" << std::setw(13) << "Frequency" << std::endl;

    for (size_t face{0}; face < frequency.size(); face++) {
        std::cout <<  std::setw(4)<< face+1 << std::setw(13) << frequency[face] << std::endl;
    }
    return 0;
}
