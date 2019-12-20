/*
 * dateGame.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: sidd
 */

#include <iostream>
#include "MyDate.h"

using namespace std;


string* getDateFromUser(string prompt) {
	string date;
	cout << prompt;
	cin >> date;
	return new string(date);
}

int main() {
	/*
	auto_ptr<string> fromDate(NULL);
	auto_ptr<string> untilDate(NULL);
	fromDate.reset(getDateFromUser("Enter from Date [yyyy.mm.dd]: "));
	untilDate.reset(getDateFromUser("Enter until Date [yyyy.mm.dd]: "));
	cout << "Dates entered are:" << endl;
	cout << *(fromDate.get()) << " > " << *(untilDate.get()) << endl;
	*/
	MyDate date1(2020,2,29);
	if (date1.isValidDate()) {
		cout << "date1= " << date1.convertToString() << endl;
	} else {
		cout << date1.convertToString() << endl;
	}
	MyDate date2(2020,2,29);
	if (date2.isValidDate()) {
		cout << "date2= " << date2.convertToString() << endl;
	} else {
		cout << date2.convertToString() << endl;
	}
	MyDate date3(2020,2,28);
	if (date3.isValidDate()) {
		cout << "date3= " << date3.convertToString() << endl;
	} else {
		cout << date3.convertToString() << endl;
	}
	cout << "date1 < date2 = " << (date1 < date2?"True":"False") << endl;
	cout << "date2 < date1 = " << (date2 < date1?"True":"False") << endl;
	cout << "date2 < date3 = " << (date2 < date3?"True":"False") << endl;
	cout << "--------------" << endl;
	cout << "date1 > date2 = " << (date1 > date2?"True":"False") << endl;
	cout << "date2 > date1 = " << (date2 > date1?"True":"False") << endl;
	cout << "date1 > date1 = " << (date1 > date1?"True":"False") << endl;
	cout << "--------------" << endl;
	cout << "date1= " << date1.convertToString() << endl;
	cout << "date2= " << date2.convertToString() << endl;
	cout << "date3= " << date3.convertToString() << endl;
	cout << "date1 <= date2 = " << (date1 <= date2?"True":"False") << endl;
	cout << "date2 <= date1 = " << (date2 <= date1?"True":"False") << endl;
	cout << "date2 <= date3 = " << (date2 <= date3?"True":"False") << endl;
	cout << "--------------" << endl;
	cout << "date1 >= date2 = " << (date1 >= date2?"True":"False") << endl;
	cout << "date2 >= date3 = " << (date2 >= date3?"True":"False") << endl;
	cout << "date2 >= date1 = " << (date2 >= date1?"True":"False") << endl;

	return 0;
}



