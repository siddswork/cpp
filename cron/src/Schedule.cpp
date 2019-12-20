/*
 * Schedule.cpp
 *
 *  Created on: May 4, 2019
 *      Author: sidd
 */
#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule(long startSecond, long frequency) {
	startTime.tv_sec = startSecond;
	startTime.tv_usec = 0;
	interval = frequency;
}

Schedule::Schedule(const Schedule &other) {
	startTime.tv_sec = other.startTime.tv_sec;
	startTime.tv_usec = other.startTime.tv_usec;
	interval = other.interval;
}

long Schedule::getStartTime() {
	return startTime.tv_sec;
}

long Schedule::getStartTime() const {
	return startTime.tv_sec;
}

long Schedule::getInterval() {
	return interval;
}

long Schedule::getInterval() const {
	return interval;
}

void Schedule::setStartTime(long seconds) {
	startTime.tv_sec = seconds;
}

void Schedule::setInterval(long interval)
{
	this->interval = interval;
}

void Schedule::print()
{
	cout << startTime.tv_sec << "\t" << interval;
}
