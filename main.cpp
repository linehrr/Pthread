#include "Pthread.h"
#include "sys/wait.h"
#include <iostream>

using namespace std;

Lock mylock(3);

class mypthread : public Pthread
{
	public:
		virtual 	void* 	run(void*);
		~mypthread();
	private:
		int iii;
};

void* mypthread::run(void* arg){
	mylock.lock();
	cout << "lock: " << mylock.get_lock_count() << endl;
	cout << "sem: " << mylock.get_sem_count() << endl;
	int iii = 0;
	printf("thread output: %d\n", ++iii);
	mylock.unlock();
}

mypthread::~mypthread(){
	//TODO GC
}


int main(){
	mypthread ppp[10];
	for(int i = 0; i < 10; i++)
		ppp[i].start();

	cout << mylock.get_lock_count() << endl;
	
	getchar();
	return 0;
}


