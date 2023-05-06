#include "Date.h"



Date::Date()
{
	setDay(1);
	setMonth(1);
	setYear(1900);
}

Date::Date(int& day, int& month, int& year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

bool Date::setDay(const int& day)
{
	if (day > 0 && day <= 31) {
		this->day = day;
		return true;
	}
	this->day = 1;
	return false;
}

bool Date::setMonth(const int& month)
{
	if (month > 0 && month <= 12) {
		this->month = month;
		return true;
	}
	this->month = 1;
	return false;
}

bool Date::setYear(const int& year)
{
	if (year > 1900 && year <= 2300) {
		this->year = year;
		return true;
	}
	this->year = 1990;
	return false;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

bool Date::isValid() const
{
	return true;
}

int Date::getAge() const
{
	return 0;
}
