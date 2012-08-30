#pragma once
#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "Pthread.h"


class Pthread_pool{
	
public:
	Pthread_pool();
	~Pthread_pool();
	int			count();
	template <class T>
	void			add_pthread(T pthread[]){
		printf("pthread: %d\n", sizeof(*pthread));
		for(int i = 0; i<20; i++){
			printf("pthread[%d]: %d\n", i, sizeof(pthread[i]));
			pthread[i].start();
		}
		printf("Size: %d\n",sizeof(*pthread)/sizeof(pthread[0]));
	}
	void 			add_pthread();

protected:
	

private:
	int 			pthread_count;

};
