#include<stdio.h>
#include<unistd.h>


int main()
{
	int i;

	pid_t myPID;

	myPID = getpid();
 
	for(i = 1; i >= 0; i++){
		
		printf("Hi I am a process, and my PID: %d ", myPID);

	}

	return 0;
}
