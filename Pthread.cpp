#include "Pthread.h"

using namespace std;


Pthread::Pthread(){
	if(pthread_attr_init(&pthread_attr)){
		perror("Cannot init pthread attr\n");
	}

}

void* mystub(void* arg){
	Pthread* obj = (Pthread*)arg;
	obj->run(NULL);
	return NULL;
}

void Pthread::set_daemon_thread(bool arg){
	if(arg){
		pthread_attr_setdetachstate(&pthread_attr,PTHREAD_CREATE_DETACHED);
	}else{
		pthread_attr_setdetachstate(&pthread_attr,PTHREAD_CREATE_JOINABLE);
	}
}

bool Pthread::get_daemon_state(){
	int state = -1;
	pthread_attr_getdetachstate(&pthread_attr,&state);
	if(state == PTHREAD_CREATE_DETACHED){
		return true;
	}else if(state == PTHREAD_CREATE_JOINABLE){
		return false;
	}
}




void Pthread::join(){
	if(pthread_join(pthread_id,NULL))
		perror("Fail to join pthread\n");
}


void Pthread::start(){

	pthread_create(&pthread_id,&pthread_attr,mystub,this);
}

Pthread::~Pthread(){
	pthread_attr_destroy(&pthread_attr);
}

void Pthread::destroy(){
	if(!pthread_cancel(pthread_id)){
		perror("Error destroy pthread:"+pthread_id);
	}
}

void* Pthread::run(void* arg){
}

unsigned int Pthread::get_pthread_id(){
	return (unsigned int)pthread_id;
}



//*********************************************
//------------implementation of the lock-------
//*********************************************

Lock::Lock(){
	lock_count = 0;

	if(pthread_mutex_init(&pthread_mutex,NULL)){
		perror("Cannot init pthread mutex\n");
	}
	if(pthread_cond_init(&pthread_cond,NULL)){
		perror("Cannot init pthread cond\n");
	}
}

Lock::~Lock(){
	pthread_mutex_destroy(&pthread_mutex);
	pthread_cond_destroy(&pthread_cond);
}

void Lock::lock(){
	if(pthread_mutex_lock(&pthread_mutex)==0){
		lock_count += 1;
	}else{
		perror("pthread lock fail\n");
	}
}

void Lock::unlock(){
	if(pthread_mutex_unlock(&pthread_mutex)==0){
		lock_count -= 1;
	}else{
		perror("pthread unlock fail\n");
	}
	if(lock_count < 0){
		perror("nothing to unlock now\n");
		lock_count = 0;
	}
}

int Lock::get_lock_count(){
	return lock_count;
}

void Lock::wait(){
	if(pthread_cond_wait(&pthread_cond,&pthread_mutex)!=0)
		perror("pthread wait fail\n");
}

void Lock::notify(){
	if(pthread_cond_signal(&pthread_cond)!=0)
		perror("pthread notify fail\n");
}

void Lock::notifyall(){
	if(pthread_cond_broadcast(&pthread_cond)!=0)
		perror("pthread notifyall fail\n");
}
