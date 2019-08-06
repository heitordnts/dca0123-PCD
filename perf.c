#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10000000

void myalloc(double** a,double** b){
	*a = (double*)malloc(sizeof(double) * MAX);
	*b = (double*)malloc(sizeof(double) * MAX);
}
void mycalloc(double** a,double** b){
	*a = (double*)calloc(MAX,sizeof(double));
	*b = (double*)calloc(MAX,sizeof(double));
}


void init(double *a,double *b){
	for(int i=0;i<MAX;++i){
		a[i] = (double)rand()/RAND_MAX;
		b[i] = (double)rand()/RAND_MAX;
	}
}

double compute(double* a,double* b){
	double res=0;

	for(int i=0;i<MAX;++i){
		res += a[i]*b[i];
	}
	return res;
}

int main(){
	srand(time(0));
	double *a,*b;

	mycalloc(&a,&b);

	double res;

	init(a,b);

	res = compute(a,b);

	printf("res = %lf\n", res);

	free(a);
	free(b);

	return 0;
}
