


#include <pthread.h>	// For pthread_create().
#include <stdio.h>	// For sprintf().
#include <unistd.h>	//	For write().
#include <string.h>	// For strlen().
#include <stdlib.h>	// For exit().


#define N_THREADS 2
#define N 200
#define MSG_SZ 200

int a;
pthread_mutex_t key;

void child1 () { 
	int i;
	char msg[MSG_SZ];	
	

	for (i = 1; i <= N; i++) {
		
		pthread_mutex_lock(&key);

		sprintf(msg, "%d. I am Thread-1. My task is to child one  a. Before (a = a + 1): %d\n", i, a);	
		write(1, msg, strlen(msg) + 1);
		a = a + 1;
		sprintf(msg, "%d. I am Thread-1. My task is to child one a. After (a = a + 1): %d\n", i, a);
		write(1, msg, strlen(msg) + 1);

		pthread_mutex_unlock(&key);

	}	
	
	sleep(1);
}

void child2 () {
	
	int i;
	char msg[MSG_SZ];	
	

	for (i = 1; i <= N; i++) {
		pthread_mutex_lock(&key);

		sprintf(msg, "%d. I am Thread-2. My task is to child two  a. Before (a = a - 1): %d\n", i, a);	
		write(1, msg, strlen(msg) + 1);
		a = a - 1;
		sprintf(msg, "%d. I am Thread-2. My task is to child two  a. After (a = a - 1): %d\n", i, a);
		write(1, msg, strlen(msg) + 1);
		pthread_mutex_unlock(&key);

	}	
	
		sleep(1);
}


int main() {
	
	int status; 
	pid_t pid1,pid2;
	
	int i;	
	char msg[MSG_SZ];

	a = 0; 
	
	pid1 = fork();
	
	if(pid1 < 0)

		printf("fork failed");

	else if(pid1 == 0){
		printf("I am child %d  ",pid1);

		child1();

		return 0;
	}



	else{
		printf("I am parent of child- %d  " , pid1 );


		wait(NULL);
		printf("My child is really dead\n ");
	
	}
	
	pid2 = fork();

	
	//if(pid2==0)
	
	   	if(pid2 < 0)

		printf("fork failed");

		else if(pid2 == 0){

			printf("I am child %d ",pid2);

			child2();

			return 0;

		}

		else{
			printf("I am parent of child- %d  " , pid2 );


			wait(NULL);
			printf("My child is really dead\n ");
	
	}

	   
	

	/*status = pthread_create(&TID[0], NULL, thread1, NULL);
	if (status != 0) {
		perror("Error during pthread_create()");
		exit(EXIT_FAILURE);
	}

	status = pthread_create(&TID[1], NULL, thread2, NULL);
	if (status != 0) {
		perror("Error during pthread_create()");
		exit(EXIT_FAILURE);	// similar to "return 0;"
	}

	
	for(i = 1; i <= N; i++){
		sprintf(msg, "%d. I am Main Thread. I am not changing a. I found a: %d\n", i, a);
		write(1, msg, strlen(msg) + 1);
	}
*/
	printf("the value of a : %d \n", a );
    while(1);
	exit(EXIT_SUCCESS);	
}



