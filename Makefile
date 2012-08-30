test : Pthread.o Pthread_pool.o main.o
	g++ Pthread.o main.o Pthread_pool.o -o test -lpthread

main.o : main.cpp
	g++ -c main.cpp

Pthread.o : Pthread.h Pthread.cpp
	g++ -c -lpthread Pthread.cpp

Pthread_pool.o : Pthread_pool.h Pthread_pool.cpp
	g++ -c Pthread_pool.cpp

clean:
	rm *.o
