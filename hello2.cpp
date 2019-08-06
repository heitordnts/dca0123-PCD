#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

void *work(void *threadid){
	//printf("Oi mundo da thread %d\n",(threadid));
	pthread_exit(NULL);
}

int main(){ 
	pthread_t tid[NUM_THREADS];
	int t;
	for(t = 0;t< 2*NUM_THREADS;++t){
		 pthread_create(&tid[t], NULL, work, (void *)t);
		 pthread_join(tid[t],NULL);
	}
	/*	
	for(t = 0;t< 2*NUM_THREADS;++t){
	}
*/	
	return 0;
}
