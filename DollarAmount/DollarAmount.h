
#ifndef INTERESTDOLLARAMOUNTER_DOLLARAMOUNT_H
#define INTERESTDOLLARAMOUNTER_DOLLARAMOUNT_H

#include <cmath>
#include <string>

class DollarAmount {
private:
    int64_t amount{ 0 };          //dollar amount  in pennies
public:
    // explict means it cannot be used for implicit conversions/copy-initialization
    //The explicit specifier may be used with a constant expression.
    // The function is explicit if and only if that constant expression evaluates to true.
    explicit DollarAmount(int64_t value) : amount{ value } {}

    //add the right amount to this object's amount
    void add(DollarAmount right) {
        //can access private data of other objects of the same class
        amount += right.amount;
    }
    //subtract the right amount to this object's amount
    void subtract(DollarAmount right) {
        //can access private data of other objects of the same class
        amount -= right.amount;
    }

    //uses integer arithmetic to calculate interest amount
    //then calls add with the interest amount
    void addInterest(int rate, int divisor) {
        //Create DollarAmount representing the interest
        DollarAmount interest{
            (amount * rate + divisor / 2) / divisor
        };
        add(interest);      //add interest to this object
    }

    //return a string representation of a DollarAmount object
    std::string toString() const {
        std::string dollars{ std::to_string(amount / 100) };
        std::string cents{ std::to_string(std::abs(amount % 100)) };
        return dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
    }

};


#endif //INTERESTDOLLARAMOUNTER_DOLLARAMOUNT_H
