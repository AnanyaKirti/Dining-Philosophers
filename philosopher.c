/**********************
**	Ananya Kirti
**	Vamsi 
**********************/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>

static pthread_mutex_t mutex[5] = {			// Mutex Lock for the variable
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_MUTEX_INITIALIZER
};

int resource[5];

void *philosopher(void *vargp){
	int my = (int)vargp;
	int resource_1 = (my) % 5;			// required resource 1
	int resource_2 = (my + 1) % 5;		// required resource 2
	while(1){ 
		sleep(1);
		if ( pthread_mutex_trylock(&mutex[resource_1]) == 0 ){ 			// Check if resources are free.
			if( pthread_mutex_trylock(&mutex[resource_2]) == 0 ){		// Check if resources are free.
				printf("philosopher %d is eating!\n", my);

				pthread_mutex_unlock(&mutex[resource_2]);	// free the resource.
			}
			else{
				printf("philosopher %d is thinking!\n", my);		// resource 2 not available 
			}
			pthread_mutex_unlock(&mutex[resource_1]);		// free the resource.
		}
		else{
			printf("philosopher %d is thinking!\n", my);			// resource 1 not available 
		}
	}

	// return NULL;
	pthread_exit(NULL);			// delete the thread. Never use terminating Ket in the command line.
}

int main(int argc, char const *argv[]){

	pthread_t phil[5];			// create id for the threads.

	int i,j;			// dummy variable.


	for (i = 0; i < 5; i++){
		pthread_create(&phil[i], NULL, philosopher, (void *)i);		// initialise all the threads.
	}
	for (i = 0; i < 5; i++){
		pthread_join(phil[i], NULL);
	}





	return 0;
}