#include "Pthread_pool.h"

using namespace std;


Pthread_pool::Pthread_pool(){
	printf("Constructor1...\n");
	perror("Constructor1...\n");

}




Pthread_pool::~Pthread_pool(){
}

int Pthread_pool::count(){
	return pthread_count;
}





	




