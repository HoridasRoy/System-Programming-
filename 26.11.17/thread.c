#include <stdio.h>
#include <pthread.h>

int x = 10;

void *sum1()
{
	while(1)
	{
		printf("I am number 1\n");
	}
}

void *sum2()
{
	while(1)
	{
		printf("I am number 2\n");
	}
}

void *sum3()
{
	while(1)
	{
		printf("I am number 3\n");
	}
}

void *sum4()
{
	while(1)
	{
		printf("I am number 4\n");
	}
}

void *sum5()
{
	while(1)
	{
		printf("I am number 5\n");
	}
}

int main()
{
	/* code */

	//sum();




	int tdstatus;

	pthread_t TID1;

	tdstatus = pthread_create(&TID1, NULL, sum1, NULL);

	if(tdstatus != 0)
	{
		perror("Error during pthread_create()");

		return 1;
	}

	x = 100;
	printf("%d\n", x);

	pthread_t TID2;

	pthread_create(&TID2, NULL, sum2, NULL);

	pthread_t TID3;

	pthread_create(&TID3, NULL, sum3, NULL);

	pthread_t TID4;

	pthread_create(&TID4, NULL, sum4, NULL);

	pthread_t TID5;

	pthread_create(&TID5, NULL, sum5, NULL);





	while(1)
	{
		printf("I am unstoppable.\n");
	}
	return 0;
}