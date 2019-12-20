/*
 * Cron.h
 *
 *  Created on: May 5, 2019
 *      Author: sidd
 */

#ifndef CRON_H_
#define CRON_H_

#include <pthread.h>
#include <vector>

class Schedule;
class CronEntry;

class Cron {
public:
	Cron() {}
	~Cron();
	void onNewTime(const struct timeval& );
	long addEntry(const Schedule &, std::string, void (*) (void *), void *);
	bool removeEntry(long);
	void showEntry();
	void showTailEntry(std::vector<CronEntry*>::size_type count = 10);
	void showHeadEntry(std::vector<CronEntry*>::size_type count = 10);
protected:
private:
	static pthread_mutex_t cronOpMutex;
	std::vector<CronEntry*> entries;
};



#endif /* CRON_H_ */
