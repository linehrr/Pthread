#include "Pthread.h"
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

	
	getchar();
	return 0;
}


