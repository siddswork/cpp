//============================================================================
// Name        : cron.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : 
// Description : cron in C++, Ansi-style
//============================================================================

#include "Cron.h"
#include "Schedule.h"
#include "CronEntry.h"
#include "dataGaurd.h"
#include <iostream>


pthread_mutex_t Cron::cronOpMutex = PTHREAD_MUTEX_INITIALIZER;

Cron::~Cron() {
	for (CronEntry *anEntry: entries)
	{
		delete anEntry;
	}
}

void Cron::onNewTime(const struct timeval& now) {
	dataGaurd lockOp(cronOpMutex);
	bool retVal = false;
	for (CronEntry *anEntry: entries)
	{
		retVal = anEntry->runIfNeeded(now) || retVal;
	}
	return;
}

long Cron::addEntry(const Schedule &aSchedule, std::string description, void (*aTask) (void *), void *context) {
	CronEntry *pNewCronEntry = NULL;
	{
		dataGaurd lock(cronOpMutex);
		pNewCronEntry = new CronEntry(aSchedule, description, aTask, context);
		entries.push_back(pNewCronEntry);
	}
	return pNewCronEntry->getID();
}

bool Cron::removeEntry(long idToDelete)
{
	std::vector<CronEntry*>::iterator it;
	{
		dataGaurd lock(cronOpMutex);
		for(it = entries.begin(); it != entries.end(); it++)
		{
			if((*it)->getID() == idToDelete)
			{
				delete *it;
				entries.erase(it);
				return true;
			}
		}
	}
	return false;
}

void Cron::showEntry() {
	std::cout << "Printing All Entries:" << std::endl;
	{
		dataGaurd lock(cronOpMutex);
		for (CronEntry *anEntry: entries)
		{
			if (anEntry != NULL)
				anEntry->print();
			else
				std::cout << "****Entry is NULL****" << std::endl;
		}
	}
	std::cout << std::endl;
}

void Cron::showTailEntry(std::vector<CronEntry*>::size_type count) {
	std::cout << "Printing last " << count << " Entries:" << std::endl;
	if (entries.size() > count)
	{
		dataGaurd lock(cronOpMutex);
		std::vector<CronEntry*>::iterator it = entries.end() - count;
		while (it != entries.end())
		{
			(*it)->print();
			it++;
		}
	}
	else
	{
		showEntry();
	}
}

void Cron::showHeadEntry(std::vector<CronEntry*>::size_type count) {
	std::cout << "Printing first " << count << " Entries:" << std::endl;
	if (entries.size() > count)
	{
		dataGaurd lock(cronOpMutex);
		std::vector<CronEntry*>::iterator it = entries.begin();
		std::vector<CronEntry*>::iterator end = entries.begin() + count;
		while (it != end && it != entries.end())
		{
			(*it)->print();
			it++;
		}
	}
	else
	{
		showEntry();
	}
}
