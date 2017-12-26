#include <stdio.h>
#include <unistd.h>

int main()
{
	/* code */
	fork();
	printf("My PID:%d\n",getpid() );

	fork();
	printf("MY parent's PID: %d\n",getpid());
	return 0;
}