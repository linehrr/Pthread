test : Pthread.o main.o
	g++ Pthread.o main.o -o test -lpthread

main.o : main.cpp
	g++ -c main.cpp

Pthread.o : Pthread.h Pthread.cpp
	g++ -c -lpthread Pthread.cpp

clean:
	rm *.o
