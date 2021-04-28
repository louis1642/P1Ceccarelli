
#include "Invoice.h"

Invoice::Invoice(std::string number, std::string descript, int qnt, int prc, float vat, float disc)
        :partNumber{number},descrption{descript},quantity{qnt},price{prc},vatAccount{vat},discountAccount{disc}{

}

std::string Invoice::getPartNumber() {
    return partNumber;
}

std::string Invoice::getDescrption() {
    return descrption;
}

int Invoice::getQuantity() {
    return quantity;
}

int Invoice::getPrice() {
    return price;
}

float Invoice::getVatAccount() {
    return vatAccount;
}

float Invoice::getDiscountAccount() {
    return discountAccount;
}

void Invoice::setPartNumber(std::string number) {
    partNumber = number;
}

void Invoice::setDescrption(std::string descript) {
    descrption=descript;
}

void Invoice::setQuantity(int qnt) {
    if(qnt>0){
        quantity=qnt;
    }
}

void Invoice::setPrice(int prc) {
    if(prc > 0){
        price=prc;
    }
}

void Invoice::setVatAccount(float vat) {
    if(vat >=0.00 && vat<=1.00){
        vatAccount=vat;
    }
}

void Invoice::setDiscountAccount(float disc) {
    if(disc >=0.00 && disc<=1.00){
        discountAccount=disc;
    }
}
