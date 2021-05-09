//
// CreditProcessingProgram
// ClientData.cpp
// Created by Luigi Catello on 09/05/21.
// 
//

#include "ClientData.h"
ClientData::ClientData(int newAccountNumber, std::string &newLastName, std::string &newFirstName, double newBalance)
    : accountNumber{newAccountNumber}, balance{newBalance} {
    SetFirstName(newFirstName);
    SetLastName(newLastName);
}
ClientData::ClientData() : accountNumber{0}, balance{0}, firstName{""}, lastName{""} {}

int ClientData::GetAccountNumber() const {
    return accountNumber;
}
std::string ClientData::GetLastName() const {
    return lastName;
}
std::string ClientData::GetFirstName() const {
    return firstName;
}
double ClientData::GetBalance() const {
    return balance;
}
void ClientData::SetAccountNumber(int account_number) {
    this->accountNumber = account_number;
}
void ClientData::SetBalance(double newBalance) {
    this->balance = newBalance;
}
void ClientData::SetFirstName(std::string &newFirstName) {
    size_t length{newFirstName.length()};   // .length() restituisce un size_t
    length = (length < FIRST_NAME_LENGHT) ? length : FIRST_NAME_LENGHT;
    newFirstName.copy(firstName, length);
    firstName[length] = '\0';   // append null char
}
void ClientData::SetLastName(std::string &newLastName) {
    size_t length{newLastName.length()};   // .length() restituisce un size_t
    length = (length < LAST_NAME_LENGHT) ? length : LAST_NAME_LENGHT;
    newLastName.copy(lastName, length);
    lastName[length] = '\0';   // append null char
}


