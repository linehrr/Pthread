#include "Pthread.h"

using namespace std;

pthread_mutex_t Pthread::pthread_mutex = PTHREAD_MUTEX_INITIALIZER;

Pthread::Pthread(){
	if(pthread_attr_init(&pthread_attr)){
		perror("Cannot init pthread attr\n");
	}
	if(pthread_mutex_init(&Pthread::pthread_mutex,NULL)){
		perror("Cannot init pthread mutex\n");
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

void Pthread::pthread_lock(){
	pthread_mutex_lock(&(Pthread::pthread_mutex));
}

void Pthread::pthread_unlock(){
	pthread_mutex_unlock(&(Pthread::pthread_mutex));

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
	pthread_mutex_destroy(&pthread_mutex);
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
