//============================================================================
// Name        : mutex.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <pthread.h>
#include <random>
#include <vector>
using namespace std;

typedef struct my_struct_tag {
	pthread_mutex_t mutex; /* Protects access to value */
	int value; /* Access protected by mutex */
} my_struct_t;



int shared_i = 0;

void readerWriter();

void threadIncrementCounter(bool useMutex);
void *incrementerThread(void *arg);

void mutex_basic();

class dataGaurd
{
public:
	dataGaurd()
	{
		pthread_mutex_lock(&mutex);
		/* Either the above code should be there *
		 * or the code below. Above code using   *
		 * mutex initialized with                *
		 * PTHREAD_MUTEX_INITIALIZER. Else we    *
		 * should use below code to customize    *
		 * mutex initialization                  *
		 */
//		bool internal_lock = false;
//		if (!initialized)
//		{
//			pthread_mutex_lock(&mutex_internal);
//			internal_lock = true;
//		}
//		if (!initialized)
//		{
//			pthread_mutex_init(&mutex, NULL);
//			cout << ">> new mutex created" << endl;
//			initialized = true;
//		}
//		if(internal_lock)
//			pthread_mutex_unlock(&mutex_internal);
//		pthread_mutex_lock(&mutex);

	}
	~dataGaurd()
	{
		pthread_mutex_unlock(&mutex);
		//cout << "  unlocked" << endl;
	}
private:
	static pthread_mutex_t mutex;
	static pthread_mutex_t mutex_internal;
	static bool initialized;
};

pthread_mutex_t dataGaurd::mutex_internal = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dataGaurd::mutex = PTHREAD_MUTEX_INITIALIZER;
bool dataGaurd::initialized = false;




int main() {
	cout << "!!!Posix Mutex!!!" << endl; // prints !!!Posix Mutex!!!
	mutex_basic();
	cout << endl;
	threadIncrementCounter(false);
	threadIncrementCounter(true);
	cout << endl;
	readerWriter();
	cout << endl;

	return 0;
}


void readerWriter()
{
	// Seed with a real random value, if available
	std::random_device r;
	// Choose a random number between min_question_num and max_question_num
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(0, 1);
	for (int i = 1; i <= 20; i++)
	{
		int random_num = uniform_dist(e1);
		cout << "Random number : " << random_num << endl;
	}

}


void threadIncrementCounter(bool useMutex)
{
	const int num = 200000;

	vector<pthread_t> threadIdArray;
	pthread_t thread_id;
	bool thread_data = useMutex;
	void *thread_result;
	int status;

	cout << num << " threads to be created " << (thread_data?"with mutex":"without mutex") << endl;
	for (int i = 1; i <= num;i++) // thread creation
	{
		status = pthread_create ( &thread_id, NULL, incrementerThread, (void *)&thread_data);
		if (status != 0)
			cerr << status << " - Creation of thread["<< i << "] failed" << endl;
		else
			threadIdArray.push_back(thread_id);
	}
	cout << num << " threads created" << endl;
	cout << "Current value of shared_i = " << shared_i << endl;
	cout << "Need to wait for " << num << " threads to complete" << endl;
	for (pthread_t t_id : threadIdArray) // thread join
	{
		status = pthread_join (t_id, &thread_result);
		if (status !=0)
			cerr << status << " - for thread[" << t_id << "], join failed" << endl;
	}
	cout << num << " threads completed" << endl;

	cout << "Final value of shared_i = " << shared_i << " after execution of "<< num <<" threads" << endl;
}

void *incrementerThread (void *arg)
{
	bool useMutex = false;
	if (arg != NULL)
	{
		useMutex = *((bool *)arg);
	}
	if (useMutex)
	{ // with mutex
		dataGaurd lock;
		shared_i++;
	}
	else
	{ // without mutex
		shared_i++;
	}
	return arg;
}

void mutex_basic()
{
	my_struct_t *data;
	int status;

	data = (my_struct_t *)malloc (sizeof (my_struct_t));
	if (data == NULL)
		cerr << "Allocate structure failed" << endl;
	else
		cout << "Allocate structure successful" << endl;
	status = pthread_mutex_init (& data-> mutex, NULL);
	if (status != 0)
		cerr << status << " - Init mutex"<< endl;
	else
		cout << status << " - mutex initialized" << endl;
	status = pthread_mutex_destroy (& data-> mutex);
	if (status != 0)
		cerr << status << " - Destroy mutex failed" << endl;
	else
		cout << status << " - mutex destroyed" << endl;
	(void) free (data);
}
