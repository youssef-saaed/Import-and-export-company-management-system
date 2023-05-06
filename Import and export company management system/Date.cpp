#include "Date.h"

int* Date::toIntDate(std::string date)
{
	std::string day, month, year;
	int intDate[3];
	int pos = 0;
	for (char x : date) {
		if (x == '/') pos++;
		if (pos == 0) month += x;
		if (pos == 1) day += x;
		if (pos == 2) year += x;
	}
	if (day.length() == 1) {
		intDate[0] = day[0] - '0';
	}
	else {
		intDate[0] = (day[0] - '0') * 10 + (day[1] - '0');
	}
	if (month.length() == 1) {
		intDate[1] = month[0] - '0';
	}
	else {
		intDate[1] = (month[0] - '0') * 10 + (month[1] - '0');
	}
	intDate[2] = (year[0] - '0') * 1000 + (year[1] - '0') * 100 + (year[2] - '0') * 10 + (year[0] - '0');
	return intDate;
}

Date::Date()
{
	setDay(1);
	setMonth(1);
	setYear(1900);
}

Date::Date(std::string date)
{
	int* theIntDate = toIntDate(date);
	day = *theIntDate;
	month = *(theIntDate + 1);
	year = *(theIntDate + 2);
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
	return false;
}

bool Date::setMonth(const int& month)
{
	if (month > 0 && month <= 12) {
		this->month = month;
		return true;
	}
	return false;
}

bool Date::setYear(const int& year)
{
	if (year > 1900 && year <= 2300) {
		this->year = year;
		return true;
	}
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
