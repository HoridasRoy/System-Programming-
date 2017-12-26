#include <stdio.h>
#include <unistd.h>

int main()
{
	/* code */

	fork();
	fork();
	fork();
	fork();

	while(1)
	{
		printf("Hello\n");
	}
	return 0;
}