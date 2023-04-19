#pragma once
#include <string>

class Employee {
private:
    int EmployeeID;
    std::string jobTitle;
    double salary;
    std::string department;
    double overtimehrs;

public:
    Employee();

    int getemployeeID() const;
    void setemployeeID(int const& EmployeeID);

    std::string getDepartment() const;
    void setDepartment(std::string const& department);

    double getSalary() const;
    void setSalary(double const& salary);

    std::string getJobTitle() const;
    void setJobTitle(std::string const& jobTitle);

    double overTime_Ecalc() const;

    void add(double const& value, double& variable) const {
        variable += value;
    }
};
