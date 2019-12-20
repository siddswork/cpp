/*
 * CronEntry.cpp
 *
 *  Created on: May 5, 2019
 *      Author: sidd
 */
#include "CronEntry.h"
#include <iostream>
#include "dataGaurd.h"

CronEntry::~CronEntry()
{
//	std::cout << "Removing: ";
//	print();
}

bool CronEntry::lessThan(CronEntry *a, CronEntry *b)
{
	if(a != NULL && b != NULL)
		return a->schedule.getStartTime() < b->schedule.getStartTime();
	else
		return false;
}

bool CronEntry::runIfNeeded(const struct timeval& now)
{
	bool didExecutedSomething = false;
	if( ((schedule.getStartTime() - now.tv_sec) % schedule.getInterval()) == 0
			&& schedule.getStartTime() < now.tv_sec) {
		/* Currently I have just called the task to be performed.
		 * This function gets called sequentially by the caller.
		 * However as an improvement we could call them by spawning
		 * a new thread. This could help if there are may tasks to
		 * be executed at a time. And instead of boolean we could
		 * return the thread id, so that thread join can be executed
		 * by the caller */
		task(dataContext);
		didExecutedSomething = true;
	}
	return didExecutedSomething   ;
}

void CronEntry::print()
{
	std::cout <<"["<< id << "]\t";
	schedule.print();
	std::cout << "\t" << desc << std::endl;
}

long CronEntry::generateNewID()
{
	static long counter = 0;
	static pthread_mutex_t genIdMutex = PTHREAD_MUTEX_INITIALIZER;
	dataGaurd lock(genIdMutex);
	return ++counter;
}

long CronEntry::getID()
{
	return id;
}
