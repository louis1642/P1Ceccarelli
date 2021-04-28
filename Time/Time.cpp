
#include "Time.h"
#include <iomanip> //for setw and setfill stream manipulators
#include <sstream> //for ostringstream class


void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

std::string Time::toUniversalString() const {
    std::ostringstream output;
    output << std::setfill('0') << std::setw(2) << hour << ":"
           << std::setw(2) << minute << ":" << std::setw(2) << second;
    return output.str();
}

std::string Time::toStandardString() const {
    std::ostringstream output;
    output << (( hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
           << std::setfill('0') << std::setw(2) << minute << ":" << std::setw(2)
           << std::setw(2) << minute << ":" << std::setw(2) << second;
    return output.str();
}

Time::Time(int hour , int minute, int second) {
    setTime(hour,minute,second);
}

void Time::setHour(int hour) {
    if(hour>=0 && hour<24){
        this->hour=hour;
    }else{
        throw std::invalid_argument(
                "Hours was out of range");
    }
}

void Time::setMinute(int minute) {
    if(minute>=0 && minute<60){
        this->minute=minute;
    }else{
        throw std::invalid_argument(
                "minute was out of range");
    }

}

void Time::setSecond(int second) {
    if(second>=0 && second<60){
        this->second=second;
    }else{
        throw std::invalid_argument(
                "second was out of range");
    }
}
