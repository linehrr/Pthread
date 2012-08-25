#include "pthread.h"
#include "errno.h"
#include "stdlib.h"
#include "stdio.h"


class Pthread {

	

public:
	Pthread();	
	//Starting the pthread
	void 				start();
	void 				destroy();
	unsigned int 			get_pthread_id();
	void 				set_daemon_thread(bool);
	bool 				get_daemon_state();
	void 				join();

	//@Overwrite func
	virtual void* 			run(void *);
	~Pthread();
		
protected:
	

private:
	pthread_t 			pthread_id;
	pthread_attr_t			pthread_attr;


};

//Lock***************************************************

class Lock{
public:
	Lock();
	~Lock();
	void				lock();
	void				unlock();
	void				wait();
	void				notify();
	void				notifyall();
	int 				get_lock_count();
protected:

private:
	pthread_mutex_t 		pthread_mutex;
	pthread_cond_t			pthread_cond;
	int	 			lock_count;

};
