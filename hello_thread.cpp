#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid){
	long tid;
	tid = (long)threadid;
	printf("Hello world from Thread #%ld\n",tid);
	
	pthread_exit(NULL);
}

int main(){ 
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t = 0;t< NUM_THREADS;++t){
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if(rc){
			printf("ERRO %d\n",rc);
			exit(-1);
		}
	}
	return 0;
}
