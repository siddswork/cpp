/*
 * dataGaurd.h
 *
 *  Created on: May 5, 2019
 *      Author: sidd
 */

#ifndef DATAGAURD_H_
#define DATAGAURD_H_
#include <pthread.h>

class dataGaurd
{
public:
	dataGaurd(pthread_mutex_t& mutex)
	{
		pMutex = &mutex;
		pthread_mutex_lock(&mutex);
	}
	~dataGaurd()
	{
		pthread_mutex_unlock(pMutex);
	}
private:
	pthread_mutex_t* pMutex;
};


#endif /* DATAGAURD_H_ */
