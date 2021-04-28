// AccountTest.cpp
// Displaying and updating Account
#include <iostream>
#include "Account.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    // create two Account objects
    Account account1{ "Jane Green", 50 };
    Account account2{ "John Blue", -7 };

    // display initial value of name for each Account
    cout << "account1: " << account1.getName() << " balance is $"
        << account1.getBalance();
    cout << "\naccount2: " << account2.getName() << " balance is $"
        << account2.getBalance();

    cout << "\n\nEnter deposit amount for account 1: "; //prompt
    int depositAmount;
    cin >> depositAmount; //obtain user input
    cout << "adding " << depositAmount << " to account1's balance";
    account1.deposit(depositAmount); // add to account1's balance

    //display balances
    cout << "account1: " << account1.getName() << " balance is $"
        << account1.getBalance();
    cout << "\naccount2: " << account2.getName() << " balance is $"
        << account2.getBalance();

    cout << "\n\nEnter deposit amount for account 2: "; //prompt
    cin >> depositAmount; //obtain user input
    cout << "adding " << depositAmount << " to account2's balance";
    account2.deposit(depositAmount); // add to account1's balance

    //display balances
    cout << "account1: " << account1.getName() << " balance is $"
        << account1.getBalance();
    cout << "\naccount2: " << account2.getName() << " balance is $"
        << account2.getBalance() << endl;
}
