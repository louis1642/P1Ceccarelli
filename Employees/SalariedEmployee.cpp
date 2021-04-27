#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(const std::string &first, const std::string &last, const std::string &ssn, double salary)
    : Employee(first, last, ssn){
        setWeeklySalary(salary);
}

void SalariedEmployee::setWeeklySalary(double salary){
    if(salary<0.0){
        throw std::invalid_argument("Weekly salary must be >= 0.0");
    }
    weeklySalary = salary;
}
double SalariedEmployee::getWeeklySalary() const{return weeklySalary; }

double SalariedEmployee::earnings() const{return getWeeklySalary(); }

std::string SalariedEmployee::toString() const{
    std::ostringstream output;
    output <<std::fixed <<std::setprecision(2);
    output <<"salaried employee: " <<Employee::toString()
        <<"\nweekly salary: " <<getWeeklySalary();
    return output.str();
}