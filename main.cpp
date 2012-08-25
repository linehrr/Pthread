#include "Pthread.h"
#include "sys/wait.h"
#include <iostream>

using namespace std;
class mypthread : public Pthread
{
	public:
		virtual void* 	run(void*);	
};

void* mypthread::run(void* arg){
	pthread_lock();
	for(int i = 0; i < 100; i++)
	printf("I am a pthread...:%d\n",i);
	pthread_unlock();
}


int main(){
	mypthread ppp[10];
	for (int i = 0; i < 10; i++){
		ppp[i].set_daemon_thread(false);
		cout << ppp[i].get_daemon_state() << endl;
		ppp[i].start();
	}

	getchar();
	return 0;
}


