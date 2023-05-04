#pragma once
class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int&, int&, int&);
	bool setDay(const int&);
	bool setMonth(const int&);
	bool setYear(const int&);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	bool isValid() const;
	int getAge() const;
	int timeTillDate(const Date&) const;
	int timeFromDate(const Date&) const;
};

