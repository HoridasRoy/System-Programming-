#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
	int i;

	pid_t childPID , myPID;
	
	/* 0 > childPID --> nusuccessfull
	  0 = childPID -- > child process created successfully

	  0 < childPID -- > parent process

	*/


	childPID = fork();
	myPID = getpid();




	if(childPID < 0)

		printf("fork failed");

	else if(childPID == 0)
		printf("I am child %d %d ",childPID, myPID);

	else{
		printf("I am parent of child- %d %d " , childPID , myPID);


		wait(NULL);
		printf("My child is really dead");
	
	}
	return 0;
}
