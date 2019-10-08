#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

#define N 10000000

int main(){
	int th_id,n;
	#pragma omp parallel private(th_id)
	{
		th_id = omp_get_thread_num();
		printf("Hello, world from thread %d\n", th_id);
	}


	float *a,*b,*c;
	int i=0;
	a = (float*)malloc(sizeof(float)*N);
	b = (float*)malloc(sizeof(float)*N);
	c = (float*)malloc(sizeof(float)*N);
	for(i = 0;i<N;i++){
		a[i] = i* 2;
		b[i] = i* 3;
	}

	clock_t t;
	#pragma omp parallel shared(a,b,c) private(i)
	{
	#pragma omp for
	for(i = 0;i< N;i++){
		c[i] = a[i] + b[i];
	}
	}

	t = clock() - t;

	printf("t = %f\n", (float)t/CLOCKS_PER_SEC); 

free(a);
free(b);
free(c);
	return 0;
}
