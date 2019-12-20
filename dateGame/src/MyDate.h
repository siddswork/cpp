/*
 * MyDate.h
 *
 *  Created on: Oct 1, 2016
 *      Author: sidd
 */

#ifndef MYDATE_H_
#define MYDATE_H_

#include <string>
using namespace std;

class MyDate {
public:
	// Constructor
	MyDate();
	MyDate(int yyyy, int mm, int dd);

	// Destructor
	virtual ~MyDate();

	// Public methods
	//const int getYear();
	//const int getMonth();
	//const int getDay();
	const int getYear() const;
	const int getMonth() const;
	const int getDay() const;
	void addDay(int noOfDays);
	bool isLeapYear();
	bool isValidDate() const;
	string convertToString();
	string convertToString() const;
	bool operator< (const MyDate& rhs) const;
	bool operator< (const MyDate& rhs);
	bool operator> (const MyDate& rhs) const;
	bool operator> (const MyDate& rhs);
	bool operator<= (const MyDate& rhs) const;
	bool operator<= (const MyDate& rhs);
	bool operator>= (const MyDate& rhs) const;
	bool operator>= (const MyDate& rhs);

protected:

private:
	// Private methods
	int max (int a, int b);
	int min (int a, int b);
	bool setIsLeapYear();

	// Private members
	int year_;
	int month_;
	int day_;
	bool isLeapYear_;
	bool isInvalid_;
	string error_;
	const static int debug_ = 0;
};

#endif /* MYDATE_H_ */
