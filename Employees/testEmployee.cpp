#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using std::cout;
using std::vector;

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main(){
    cout <<std::fixed <<std::setprecision(2);

    SalariedEmployee salariedEmployee{"Paul", "Chambers", "111-11-1111", 800};
    CommissionEmployee commissionEmployee{"Bill", "Evans", "333-33-3333", 10000, .06};
    BasePlusCommissionEmployee basePlusCommissionEmployee{"Miles", "Davis", "444-44-4444", 5000, .04, 300};

    cout <<"EMPLOYEES PROCESSED INDIVIDUALLY USING STATIC BINDING\n"
        <<salariedEmployee.toString()
        <<"\nearned $" <<salariedEmployee.earnings() <<"\n\n"
        <<commissionEmployee.toString()
        <<"\nearned $" <<commissionEmployee.earnings() <<"\n\n"
        <<basePlusCommissionEmployee.toString()
        <<"\nearned $" <<basePlusCommissionEmployee.earnings() <<"\n\n";

    vector<Employee*> employees{&salariedEmployee, &commissionEmployee, &basePlusCommissionEmployee};

    cout <<"EMPLOYEES PROCESSED POLYMORPHICALLY VIA DYNAMIC BINDING\n\n";
    cout <<"VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS POINTERS\n";
    for(const Employee *employeePtr: employees){
        virtualViaPointer(employeePtr);
    }
    cout <<"VIRTUAL FUNCTION CALLS MADE OFF BASE-CLASS REFERENCE\n";
    for(const Employee *employeePtr: employees){
        virtualViaReference(*employeePtr);
    }
}

void virtualViaPointer(const Employee* const baseClassPtr){
    cout <<baseClassPtr->toString() <<"\nearned $" <<baseClassPtr->earnings() <<"\n\n";
}
void virtualViaReference(const Employee& baseClassRef){
    cout <<baseClassRef.toString() <<"\nearned $" <<baseClassRef.earnings() <<"\n\n";
}