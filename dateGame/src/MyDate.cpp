/*
 * MyDate.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: sidd
 */

#include "MyDate.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

MyDate::MyDate(int yyyy, int mm, int dd) {
	static int nonLeapYearDaysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static int leapYearDaysInMonth[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int month, day;
	// Year validation
	isInvalid_ = false;
	if (yyyy >= 1) {
		year_=yyyy;
		isLeapYear_ = setIsLeapYear();

		// Month validation
		month = max(1, mm);
		month = min(month,12);
		if (month != mm) {
			isInvalid_ = true;
			error_ += "Incorrect Month;";
		} else {
			month_ = mm;
		}

		// Day validation
		if(!isInvalid_) {
			day = max(1,dd);
			if(isLeapYear_) {
				day = min(day, leapYearDaysInMonth[month_]);
			} else {
				day = min(day, nonLeapYearDaysInMonth[month_]);
			}
			if(day != dd) {
				isInvalid_ = true;
				error_ += "Incorret Day;";
			} else {
				day_ = day;
			}
		}

	} else {
		isInvalid_ = true;
		error_ += "Incorret Year;";
	}


	if (isInvalid_) {
		year_=yyyy;
		month_=mm;
		day_=dd;
	}
}
bool MyDate::isLeapYear() {
	return isLeapYear_;
}
bool MyDate::isValidDate() const{
	return !isInvalid_;
}
void MyDate::addDay(int noOfDays) {

}
string MyDate::convertToString() {
    int size=4+1+2+1+2+10;
    char *temp = (char *)malloc(size);
    auto_ptr<char> apCharString;
    apCharString.reset(temp);
    snprintf(temp, size, "%04d-%02d-%02d", year_, month_, day_);
    string dateAsString(temp);
    if(isInvalid_)
    	return error_ + ": (" + dateAsString + ")";
    else
    	return dateAsString;
}
string MyDate::convertToString() const {
    int size=4+1+2+1+2+10;
    char *temp = (char *)malloc(size);
    auto_ptr<char> apCharString;
    apCharString.reset(temp);
    snprintf(temp, size, "%04d-%02d-%02d", year_, month_, day_);
    string dateAsString(temp);
    if(isInvalid_)
    	return error_ + ": (" + dateAsString + ")";
    else
    	return dateAsString;
}

MyDate::~MyDate() {
	// do nothing
}

int MyDate::max (int a, int b)
{
   if (a>b) return(a) ; else return (b);
}

int MyDate::min (int a, int b)
{
   if (a>b) return(b); else return (a);
}

bool MyDate::setIsLeapYear()
{
	/*
	 * 1. If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
	 * 2. If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
	 * 3. If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
	 * 4. The year is a leap year (it has 366 days).
	 * 5. The year is not a leap year (it has 365 days).
	 */
	bool isLeapYear = false;
	if (year_ % 4 == 0) {
		if (year_ % 100 == 0) {
			if (year_ % 400 == 0) {
				isLeapYear = true;
			} // else  it is not a leap year, which is our default value; do nothing
		} else {
			isLeapYear = true;
		}
	}
	return isLeapYear;
}

//const int MyDate::getYear() { return year_; }
//const int MyDate::getMonth() { return month_; }
//const int MyDate::getDay() { return day_; }
const int MyDate::getYear() const { return year_; }
const int MyDate::getMonth() const { return month_; }
const int MyDate::getDay() const { return day_; }

inline bool MyDate::operator< (const MyDate& rhs) const {
	if(this->isValidDate() && rhs.isValidDate()) {
		return this->convertToString() < rhs.convertToString();
	}
	return false;
}

bool MyDate::operator< (const MyDate& rhs) {
	if(this->isValidDate() && rhs.isValidDate()) {
		return this->convertToString() < rhs.convertToString();
	}
	return false;
}

bool MyDate::operator> (const MyDate& rhs) const {
	if(this->isValidDate() && rhs.isValidDate()) {
		return this->convertToString() > rhs.convertToString();
	}
	return false;
}

bool MyDate::operator> (const MyDate& rhs) {
	if(this->isValidDate() && rhs.isValidDate()) {
		return this->convertToString() > rhs.convertToString();
	}
	return false;
}

bool MyDate::operator<= (const MyDate& rhs) const {
	if(this->isValidDate() && rhs.isValidDate()) {
		return this->convertToString() <= rhs.convertToString();
	}
	return false;
}

bool MyDate::operator<= (const MyDate& rhs) {
	if(this->isValidDate() && rhs.isValidDate()) {
		return this->convertToString() <= rhs.convertToString();
	}
	return false;
}

bool MyDate::operator>= (const MyDate& rhs) const {
	if(this->isValidDate() && rhs.isValidDate()) {
		return this->convertToString() >= rhs.convertToString();
	}
	return false;
}

bool MyDate::operator>= (const MyDate& rhs) {
	if(this->isValidDate() && rhs.isValidDate()) {
		return this->convertToString() >= rhs.convertToString();
	}
	return false;
}
