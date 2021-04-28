
#include <iostream>
#include <sstream>
#include <array>
#include "Date.h"

Date::Date(unsigned int day, unsigned int mounth, unsigned int year)
    :day{checkDay(day)}, month{mounth}, year{year} {

    if (mounth < 1 || mounth > monthsPerYear){
        throw std::invalid_argument("mounth must be 1-12");
    }

    std::cout<< "Date object constructor for date" << toString()<< std::endl;

}

std::string Date::toString() const {
    std::ostringstream output;
    output<<day<<'/'<<month<<'/'<<year;
    return output.str();
}

Date::~Date() {
    std::cout<< "Date object destructor for date" << toString()<< std::endl;
}

unsigned int Date::checkDay(int testDay) const {
    static const std::array<int, monthsPerYear+1> daysPerMonth{
        0,31,28,31,30,31,30,
        31,31,30,31,30,31};

    if (testDay>0 && testDay <0 <= daysPerMonth[month]){
        return testDay;
    }
    if (month==2 && testDay==29 && (year % 400 ==0 ||(year % 4 ==0 && year %100 !=0))){
        return testDay;
    }
    throw std::invalid_argument("Invalid day for current month and year");
}
