#include "Employee.h"

Employee::Employee(std::string name, Date birthdate, std::string address, std::string phonenum, int gender, std::string profilePic, int referecode, std::string membership, Account account, int EmployeeID, std::string jobTitle, double salary, std::string department, double overtimehrs)
    : Person(name, birthdate, address, phonenum, gender, profilePic, referecode, membership, account), EmployeeID(EmployeeID), jobTitle(jobTitle), salary(salary), department(department), overtimehrs(overtimehrs) {}

int Employee::getemployeeID() const
{
    return EmployeeID;
}

bool Employee::setemployeeID(int const& EmployeeID)
{
    this->EmployeeID = EmployeeID;
    return true;
}


std::string Employee::getDepartment() const
{
    return department;
}

bool Employee::setDepartment(std::string const& department)
{
    this->department = department;
    return true;
}


double Employee::getSalary() const {

    return salary;
}

bool Employee::setSalary(double const& salary)
{
    this->salary = salary;
    return true;
}


std::string Employee::getJobTitle() const
{
    return jobTitle;
}

bool Employee::setJobTitle(std::string const& jobTitle)
{
    this->jobTitle = jobTitle;
    return true;
}

void Employee::viewInfo() const
{
}

void Employee::delete_account() const
{
}
