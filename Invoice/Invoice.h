
#ifndef INVOICE_INVOICE_H
#define INVOICE_INVOICE_H

#include <string>

class Invoice {
public:
    Invoice(std::string number,std::string descript,int qnt,int prc,float vat,float disc);

    void setPartNumber(std::string number);
    void setDescrption(std::string descript);
    void setQuantity(int qnt);
    void setPrice(int prc);
    void setVatAccount(float vat);
    void setDiscountAccount(float disc);

    std::string getPartNumber();
    std::string getDescrption();
    int getQuantity();
    int getPrice();
    float getVatAccount();
    float getDiscountAccount();

private:
    std::string partNumber;
    std::string descrption;
    int quantity;
    int price;
    float vatAccount;
    float discountAccount;
};


#endif //INVOICE_INVOICE_H
