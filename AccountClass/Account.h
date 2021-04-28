
#ifndef ACCOUNTCLASS_ACCOUNT_H
#define ACCOUNTCLASS_ACCOUNT_H

#include <string>

class Account{
public:

    void setName(std::string accountName){
        name = accountName;
    }
    std::string getName(){
        return name;
    }
private:
    std::string name;
};

int g;

#endif //ACCOUNTCLASS_ACCOUNT_H
