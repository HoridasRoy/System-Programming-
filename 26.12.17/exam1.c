#include <stdio.h>
#include <unistd.h>

int main()
{
	/* code */
	pid_t CID, myPID;

	myPID = getpid();

	CID = fork();

	if(CID == 0)
	{
		printf("MY PID: %d\n",myPID );
		//while(1);
	}

	else
	{
		printf("MY PID: %d\n",myPID );
		//wait(NULL);
	}
	return 0;
}