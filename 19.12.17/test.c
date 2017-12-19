#include <stdio.h>
#include <unistd.h>

int main()
{
	/* code */
	int a = 10 ;
	int b = 3;

	int status;

	char *argv[] = {"sum.exe",NULL};
	status = execve("sum.exe", argv, NULL);

	if(status == -1)
	{
		perror("Error during execve()");

		return 1;
	}

	printf("a : %d , b: %d\n",a,b );
	return 0;
}