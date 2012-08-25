#include "pthread.h"
#include "errno.h"
#include "stdlib.h"
#include "stdio.h"


class Pthread {

	static pthread_mutex_t			pthread_mutex;

	public:
	Pthread();	
	//Starting the pthread
	void 				start();
	void 				destroy();
	unsigned int 			get_pthread_id();
	void 				set_daemon_thread(bool);
	bool 				get_daemon_state();
	//@Overwrite func
	virtual void* 			run(void *);
	~Pthread();
		
	protected:
	static void 			pthread_lock();
	static void 			pthread_unlock();
	

	private:
	pthread_t 			pthread_id;
	pthread_attr_t			pthread_attr;
	

};
