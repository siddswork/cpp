#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <iostream>

void *worker_function(void* arg) ;
pthread_mutex_t work_mutex ; //our little flag

int counter = 0;
const int N = 20;

int main(int argc, char* argv[]){
  const int MAX_THREAD = 9050;
  int res;
  pthread_t worker_thread[MAX_THREAD];
  void* thread_result;
  res = pthread_mutex_init(&work_mutex, NULL);
  if(res != 0){
    perror("Mutex Initialization Failed");
    exit(EXIT_FAILURE) ;
  }

  for (int i = 0; i < MAX_THREAD; i++)
  {
	  res = pthread_create(&worker_thread[i], NULL, worker_function, NULL) ;
	  if(res != 0){
		std::cout << i << " ";
		perror("Thread creation Failed");
		exit(EXIT_FAILURE) ;
	  }
  }

  pthread_mutex_lock(&work_mutex) ;
  printf("Main Thread\n") ;
  pthread_mutex_unlock(&work_mutex) ;

  std::cout << "Thread 1: " << (long)worker_thread[0] << std::endl;
  std::cout << "Thread 2: " << (long)worker_thread[1] << std::endl;

  printf("Waiting for worker thread to finish\n") ;
  for (int i = 0; i < MAX_THREAD; i++)
  {
	  res = pthread_join(worker_thread[i], &thread_result) ;
	  if(res != 0){
		perror("Worker thread crashed") ;
		exit(EXIT_FAILURE) ;
	  }
  }
  pthread_mutex_destroy(&work_mutex) ;

  printf("Value of counter at the end: %d", counter);

  exit(EXIT_SUCCESS) ;
}

void* worker_function(void* arg) {
  for(int i = 0; i < N ; i++){
    pthread_mutex_lock(&work_mutex) ;
    ++counter;
    pthread_mutex_unlock(&work_mutex) ;
  }
  pthread_exit(0) ;
}
