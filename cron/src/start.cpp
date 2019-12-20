/*
 * start.cpp
 *
 *  Created on: May 5, 2019
 *      Author: sidd
 */

#include <iostream>
#include <sys/time.h>
#include <pthread.h>
#include "Cron.h"
#include "Schedule.h"

using namespace std;

//Forward declarations
void fn2(void *);
void fn3(void *);
void test_1_simpleWorking();
void test_2_uniqEntryIDTest(long count);
void test_3_uniqEntryIDTest(long count);

struct ThreadData {
	Cron *pCron;
	long startTime;
	void (*pTask) (void *);
	void *context;
};

int main() {

	test_1_simpleWorking();
	test_2_uniqEntryIDTest(2000l);
	test_3_uniqEntryIDTest(20000l);

	return 0;
}


void test_1_simpleWorking()
{
	cout << endl;
	cout << "Test case 1: Showing basic working with 4 cron entries" << endl <<
			"and passing time to show their triggering, Also we see" << endl <<
			"the affect of context change, changing the behavior of" << endl <<
			"the task" << endl <<
			"========================================================" << endl;
	Cron myCron;
	string ans;
	struct timeval currTime;

	Schedule a(1556989100L, 15); float floatContext = 3.5;
	long id = myCron.addEntry(a, "Lambda 1",
			[] (void *pVal) { if(pVal != NULL)
								cout << "\tLambda1() called with: " << *((float *)pVal) << endl;
							  else
								cout << "\tLambda1() called with: NULL" << endl;
							},
			&floatContext);
	a.setStartTime(1556989113L); a.setInterval(20); string strContext("2.b");
	id = myCron.addEntry(a, "function 2.b", &fn2, &strContext);
	a.setStartTime(1556989106L); a.setInterval(8); int intContext = 154;
	id = myCron.addEntry(a, "function 3", &fn3, &intContext);
	a.setStartTime(1556989100L); a.setInterval(10);
	id = myCron.addEntry(a, "function 2.a NULL", &fn2, NULL);

	myCron.showEntry();
	cout << "Press a key + enter to continue: " ;
	cin >> ans;

	currTime.tv_sec = 1556989100L;
	currTime.tv_usec = 0;
	long endTime = currTime.tv_sec + 50;
	long i = 0;
	cout << "Timer starts at ["<< i << "] @ " << currTime.tv_sec  << endl;
	for(; currTime.tv_sec < endTime; currTime.tv_sec++)
	{
		/* If the onNewTime() could return true or false based on whether it executed something or not
		 * we could have used this information to make the display better by using below code
		bool executed = myCron.onNewTime(currTime);
		if (executed)
			cout << "The above executions happened at ["<< i << "] @ " << currTime.tv_sec  << endl;
		else
			cout << ".";
		i++;
		*/
		/* As per specification we need to stick to void onNewTime( const struct timeval& )
		 * implementation. Below is the code accordingly*/
		cout << "["<< i++ << "] @ " << currTime.tv_sec  << endl;
		myCron.onNewTime(currTime);
		if (currTime.tv_sec % 13)
			intContext += 40;
	}

	myCron.showEntry();
	if(myCron.removeEntry(id)) {
		cout << "Successfully removed entry with id: " << id << endl;
		myCron.showEntry();
	} else {
		cout << "ERROR: failed to remove entry with id: " << id << endl;
		myCron.showEntry();
	}
	cout << "Press a key + enter to continue: " ;
	cin >> ans;
	cout << endl;

}

void* addEntryFunction(void *arg)
{
	if (arg == NULL)
		return NULL;
	struct ThreadData &threadData = *((struct ThreadData*)arg);
	Schedule schedule(threadData.startTime, 15);
	threadData.pCron->addEntry(
				schedule,
				"multi-threaded add test",
				threadData.pTask,
				threadData.context
			);

	return NULL;
}

void test_2_uniqEntryIDTest(long count)
{
	cout << "Test case 2: Showing that Unique IDs gets generated for" << endl <<
			"every cron entry created" << endl <<
			"========================================================" << endl;
	Cron myCron;
	string ans;
	const int num = count;
	long startTime = 1556989100L;
	long range = startTime + num;

	cout << "Adding " << count << " entries in cron" << endl;
	for (Schedule a(1556989100L, 15); startTime < range; startTime++)
	{
		myCron.addEntry(a, "sequential add entry call", &fn2, NULL);
	}

	cout << "Completed adding " << count << " entries"<< endl;

	myCron.showHeadEntry(3);
	myCron.showTailEntry(3);
	cout << endl << "Press a key + enter to continue: ";
	cin >> ans;
	cout << endl;
}

void test_3_uniqEntryIDTest(long count)
{
	cout << "Test case 3: showing that code is thread save, Unique id " << endl <<
			"gets generated properly for every cron entry" << endl <<
			"========================================================" << endl;
	Cron myCron;
	string ans;
	const int num = count;
	pthread_t thread_id[num];
	struct ThreadData threadData;
	threadData.pCron = &myCron;
	threadData.startTime = 1556989100L;
	threadData.pTask = &fn2;
	threadData.context = NULL;

	cout << num << " threads to be created" << endl;

	int status, i = 0;

	for ( ; i < num; threadData.startTime++, i++)
	{
		status = pthread_create ( &thread_id[i], NULL, addEntryFunction, (void *)&threadData);
		if (status != 0)
			cerr << status << " - Creation of thread["<< i << "] failed" << endl;
	}

	cout << "Waiting for threads to complete..." << endl;
	void *thread_result;
	for (int i = 0; i < num; i++) // thread join
	{
		status = pthread_join (thread_id[i], &thread_result);
		if (status !=0)
			cerr << status << " - for thread[" << i << "], join failed" << endl;
	}
	cout << "All threads completed" << endl;
	myCron.showHeadEntry(3);
	myCron.showTailEntry(3);

	cout << endl << "Check the max id = (startID + "<< count <<" - 1)" << endl;
	cout << "It means that the  IDs are getting generated uniquely and sequentially" << endl;
	cout << "Press a key + enter to continue: " ;
	cin >> ans;
	cout << endl;
}

void fn2(void *arg)
{
	if(arg != NULL) {
		string *pStr = (string *)arg;
		cout << "\tfn2() called with value: " << *pStr << endl;
	}
	else
	{
		cout << "\tfn2() called with value: NULL" << endl;
	}
}

void fn3(void *arg)
{
	if(arg != NULL) {
		int *pInt = (int *)arg;
		cout << "\tfn3() called with value: " << *pInt << endl;
	}
	else
	{
		cout << "\tfn3() called with value: NULL" << endl;
	}

}
