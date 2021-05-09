//
// CreditProcessingProgram
// ClientData.h
// Created by Luigi Catello on 09/05/21.
// 
//

#ifndef CREDITPROCESSINGPROGRAM__CLIENTDATA_H_
#define CREDITPROCESSINGPROGRAM__CLIENTDATA_H_

#define LAST_NAME_LENGHT 15
#define FIRST_NAME_LENGHT 10

#include <string>

class ClientData {
 private:
  int accountNumber;
  char lastName[LAST_NAME_LENGHT];
  char firstName[FIRST_NAME_LENGHT];
  double balance;
 public:
  void SetLastName(std::string &newLastName);
  void SetFirstName(std::string &newFirstName);
  void SetAccountNumber(int account_number);
  void SetBalance(double balance);
  int GetAccountNumber() const;
  std::string GetLastName() const;
  std::string GetFirstName() const;
  double GetBalance() const;
  ClientData(int newAccountNumber, std::string &newLastName, std::string &newFirstName, double newBalance);
  ClientData();
};

#endif //CREDITPROCESSINGPROGRAM__CLIENTDATA_H_
