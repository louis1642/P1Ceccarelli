#include <iostream>
#include <iomanip>
#include <string>
#include "DollarAmount.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;


int main() {
    DollarAmount d1{ 12345 };
    DollarAmount d2{ 1277 };

    cout << "After adding d2 (" << d2.toString() << ") into d1(" << d1.toString() << ")" << endl;
    d1.add(d2);
    cout << d1.toString() << endl;

    cout << "After substracting d2 (" << d2.toString() << ") into d1(" << d1.toString() << ")" << endl;
    d1.subtract(d2);
    cout << d1.toString() << endl;

    int rate;
    int divisor;

    cout << "\nEnter interest: " << endl;
    cin >> rate >> divisor;


    DollarAmount balance{ 10000 };
    cout << "\nInitial balance: " << balance.toString() << endl;

    //dispay headers
    cout << "\nYear" << setw(20) << "Amount on deposit: " << endl;

    //calculate amount on deposit for aech of ten years
    for (unsigned int year{ 1 }; year <= 10; year++) {
        // calculate amount on deposit at the end of the specified year
        balance.addInterest(rate, divisor);
        //display the year and the amount
        cout << setw(4) << year << setw(20) << balance.toString() << endl;

    }
    return 0;
}