#include "Pthread.h"
#include "Pthread_pool.h"
#include "sys/wait.h"
#include <iostream>

using namespace std;

Lock mylock;

class mypthread : public Pthread
{
	public:
		virtual 	void* 	run(void*);
		~mypthread();
	private:
		int iii;
};

void* mypthread::run(void* arg){
	int iii = 0;
	printf("thread output: %d\n", ++iii);
}

mypthread::~mypthread(){
	//TODO GC
}


int main(){
	mypthread ppp[10];
//	cout << sizeof(ppp)/sizeof(ppp[0]) << endl;
	Pthread_pool pthread_pool;
	pthread_pool.add_pthread(ppp);

	
	getchar();
	return 0;
}


