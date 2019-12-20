#ifndef SCHEDULE_H_
#define SCHEDULE_H_

//Header files
#include <sys/time.h>

class Schedule {
public:
	Schedule(long startSecond, long frequency);
	Schedule(const Schedule &other);
	long getStartTime();
	long getStartTime() const;
	long getInterval();
	long getInterval() const;
	void setStartTime(long seconds);
	void setInterval(long interval);
	void print();
private:
	struct timeval startTime;
	long interval;
};

#endif
