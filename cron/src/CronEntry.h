/*
 * CronEntry.h
 *
 *  Created on: May 5, 2019
 *      Author: sidd
 */

#ifndef CRONENTRY_H_
#define CRONENTRY_H_

#include "Schedule.h"
#include <string>

class CronEntry {
public:
	CronEntry(const Schedule &aSchedule, std::string description, void (*aTask) (void *), void *context)
		:schedule(aSchedule),
		 desc(description),
		 task(aTask),
		 dataContext(context),
		 id(0)
	{
		id = generateNewID();
	}
	~CronEntry();
	long getID();
	static bool lessThan(CronEntry *a, CronEntry *b);
	bool runIfNeeded(const struct timeval&);
	void print();
protected:
	long generateNewID();

private:
	Schedule schedule;
	std::string desc;
	void (*task) (void *arg);
	void *dataContext;
	long id;
};



#endif /* CRONENTRY_H_ */
