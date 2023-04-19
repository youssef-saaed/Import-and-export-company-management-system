//
// Created by Ashraf on 4/19/2023.
//
#pragma once
#include <string>
using namespace std
class Employee {
private:
    int EmployeeID;
    string jobTitle;
    float salary;
    string department;
    float overtimehrs;

public:
    Employee();

    int getemployeeID();
    void setemployeeID(int EmployeeID);

    string getDepartment();
    void setDepartment(string department);

    float getSalary();
    void setSalary(float salary);

    string getJobTitle();
    void setJobTitle(string jobTitle);

    float overTime_Ecalc();
};

#endif //IMPORT_AND_EXPORT_COMPANY_MANAGEMENT_SYSTEM_EMPLOYEE_H
