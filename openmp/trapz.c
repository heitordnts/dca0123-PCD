#include <stdio.h>
#include <omp.h>

double f(double x){
	return x*x;
}


int main(){
	double a,b,h;
	int n = 10000000;
	a = 0.0;
	b = 2.0;
	h = (b-a)/n;
	double x_i;
	double sum=0;
	
	for(int i=0;i < n ;i++){
		x_i = a + i*h;
		//printf("%lf\n",x_i);
		sum += f(x_i)*h;
	}
	printf("sum = %lf\n", sum);

	return 0;
}
