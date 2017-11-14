#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

#define READ_END 0
#define WRITE_END 1


int main()
{
	int fd[2];
	char *msg = "Dear, I am your parent, process: ";

	char msg2[80];

	pid_t myPID, P_PID;

	my_PID = getpid();

	P_PID = getpid();

	pid_t childPID;

	pipe(fd);


	//close(fd[0]);


	write(fd[1], msg, 80);

	//close(fd[1]);
	childPID = fork();

	myPID - getpid();

	if(childPID < 0)
		printf("fork() failed " );

	else if(childPID == 0)
	{
		printf("I am process: %d. Message from parent : ", myPID);
		read(fd[0], msg2, 80);
		printf(

	}
	//close(fd[1]);
	read(fd[0], msg2, 80);
	//close(fd[0]);

	printf("My message for u: %s", msg2);

	


	return 0;

}
