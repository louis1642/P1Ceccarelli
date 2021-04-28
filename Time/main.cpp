
#include "Time.h"

void displayTime(const std::string& message, const Time& time){
    std::cout << message << "\nUniversal time" << time.toUniversalString()<<
        "\nStandard Time:"<< time.toStandardString() << "\n\n";
}

int main() {
    Time t; //instantiate object t of class Time
    displayTime("Initial Time",t); //display initial state
    t.setTime(13,27,6); //change time
    displayTime("After setTime",t); //display new values

    //attempt to set the time with invalid values
    try{
        t.setTime(99,99,99);    //all values out of range
    }catch (std::invalid_argument& e){
        std::cout<< "Exception: "<< e.what()<< "\n\n";
    }

   //display t's value after attemptiong to set an invalid time
   displayTime("After attemptiong to set an invalid time:",t);
    return 0;
}
