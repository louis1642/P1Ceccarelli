
#ifndef TIME_H
#define TIME_H

#include <string>
#include <ostream>
#include <iostream>
#include <stdexcept> //for invalid_argument exception class

class Time {
public:

    explicit Time(int = 0,int = 0, int = 0);    //default constructor

    void setTime(int,int,int);  //set hour, minute and second
    void setHour(int);  //set hour after validation
    void setMinute(int);  //set minute after validation
    void setSecond(int);  //set seconf after validation
    std::string toUniversalString() const; //224-hour time format
    std::string toStandardString() const; //224-hour time format
private:
    unsigned int hour{0};   //0-23
    unsigned int minute{0}; //0-59
    unsigned int second{0}; //0-59
};


#endif //TIME_H
