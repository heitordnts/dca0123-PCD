
/* File:       
 *    mpi_hello.c
 *
 * Purpose:    
 *    A "hello,world" program that uses MPI
 *
 * Compile:    
 *    mpicc -g -Wall -std=C99 -o mpi_hello mpi_hello.c
 * Usage:        
 *    mpiexec -n<number of processes> ./mpi_hello
 *
 * Input:      
 *    None
 * Output:     
 *    A greeting from each process
 *
 * Algorithm:  
 *    Each process sends a message to process 0, which prints 
 *    the messages it has received, as well as its own message.
 *
 * IPP:  Section 3.1 (pp. 84 and ff.)
 */
#include <stdio.h>
#include <string.h>  /* For strlen             */
#include <unistd.h>  /* For strlen             */
#include <mpi.h>     /* For MPI functions, etc */ 

int main(void) {
	int        comm_sz;               /* Number of processes    */
	int        my_rank;               /* My process rank        */

	/* Start up MPI */
	MPI_Init(NULL, NULL); 
	/* Get the number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); 
	/* Get my rank among all the processes */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
	int tree[16][16];

	int my_num = my_rank +1;
	int div = 2,offset=1;
	int partner = 0;
	int r;
	int c=comm_sz;
	
	while(div <= comm_sz){
		tree[my_rank][div] = my_num;
		if (my_rank % div == 0) {
			partner = my_rank + offset;
			MPI_Recv(&r, 1, MPI_INT, partner, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			//printf("thread %d recebendo %d de %d\n", my_rank,r,partner);
			printf("%8d",my_num);
			my_num += r;
			c--;
		} 
		else{
			partner = my_rank - offset;
			MPI_Send(&my_num, 1, MPI_INT, partner, 0, MPI_COMM_WORLD); 
			//printf("thread %d mandando %d para %d\n", my_rank,my_num,partner);
			printf("%8d",my_num);
			c--;
			break;
		} 
		div    *=2;
		offset *=2;
		if(c<=0){
			printf("\n");
			c = comm_sz/offset;	
		}
	}
	if(my_rank == 0){ printf("\nsum: %d\n",my_num);

	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
		}


	}
	}
	/* Shut down MPI */
	MPI_Finalize(); 

	return 0;
}  
