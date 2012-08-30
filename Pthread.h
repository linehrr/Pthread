#pragma once
#include "pthread.h"
#include "semaphore.h"
#include "errno.h"
#include "stdlib.h"
#include "stdio.h"



#define VERBOSE 1			//define verbose mode

class Pthread_pool;

class Pthread {

	

public:
	//***********************Pthread Implementation************
	Pthread();
	~Pthread();
	
	void 				start();//Starting the pthread
	void 				destroy();
	unsigned int 			get_pthread_id();
	void 				set_daemon_thread(bool);
	bool 				get_daemon_state();
	void 				join();


	//@Overwrite func
	virtual void* 			run(void *);

		
protected:
	

private:
	pthread_t 			pthread_id;
	pthread_attr_t			pthread_attr;


};

//Lock***************************************************

class Lock{
public:
	Lock();
	Lock(int);
	virtual 			~Lock();
	void				lock();
	void				trylock();
	void				unlock();
	void				wait();
	void				notify();
	void				notifyall();
	int 				get_lock_count();
	int 				get_sem_count();
protected:

private:
	pthread_mutex_t 		pthread_mutex;
	sem_t				pthread_sem;
	pthread_cond_t			pthread_cond;
	int	 			lock_count;
	int				sem_value;
	int				type;

};
