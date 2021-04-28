
#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    unsigned int year;
    unsigned int day;
    unsigned int month;

    //utility function to check if day is proper for month and year
    unsigned int checkDay(int) const;

public:
    static const unsigned int monthsPerYear{12};
    explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 1900);
    std::string toString() const;   //date string in month/day/year
    ~Date(); // destructor
};


#endif //DATE_DATE_H
