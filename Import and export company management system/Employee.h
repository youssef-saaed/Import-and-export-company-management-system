#pragma once
#include <string>
#include "Person.h"

class Employee : public Person {

private:
    int EmployeeID;
    std::string jobTitle;
    double salary;
    std::string department;
    double overtimehrs;

public:
    
    Employee(std::string name, Date birthdate, std::string address, std::string phonenum, Gender gender, std::string profilePic, std::string membership, Account account, int EmployeeID, std::string jobTitle, double salary, std::string department, double overtimehrs);

    int getemployeeID() const;
    bool setemployeeID(int const& EmployeeID);

    std::string getDepartment() const;
    bool setDepartment(std::string const& department);

    double getSalary() const;
    bool setSalary(double const& salary);

    std::string getJobTitle() const;
    bool setJobTitle(std::string const& jobTitle);

    double overTime_Ecalc() const;
    void viewInfo() const;
    void delete_account() const;
};