#include "Pthread.h"
#include "sys/wait.h"
#include <iostream>

using namespace std;

Lock mylock;

class mypthread : public Pthread
{
	public:
		virtual void* 	run(void*);	
	private:
		int iii;
};

void* mypthread::run(void* arg){
	int iii = 0;
	printf("thread output: %d\n", ++iii);
}


int main(){
	mypthread ppp[10];
	for (int i = 0; i < 10; i++){
		ppp[i].set_daemon_thread(false);
		ppp[i].start();
	}
	
	sleep(1);
	
	for(int i = 0; i < 10; i++){
		mylock.notifyall();
	}
	mylock.unlock();
	printf("Lock count:%d\n",mylock.get_lock_count());


	for(int i = 0; i < 10; i++){
		ppp[i].join();
	}
	printf("Job Done\n");

	getchar();
	return 0;
}


