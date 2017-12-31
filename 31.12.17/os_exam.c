#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int a, d, n;

void *thread1()
{
	int value;
	value = n;

	pthread_mutex_t mute;

	while(value--)
	{
		pthread_mutex_lock(&mute);
		printf("%d + %d = %d\n", a , d , a + d );

		a = a + d;

		pthread_mutex_unlock(&mute);
	}
}

void *thread2()
{
	int value;
	value = n;

	pthread_mutex_t mute;

	
	while(value--)
	{
		pthread_mutex_lock(&mute);
		printf("%d - %d = %d\n", a , d , a - d );

		a = a - d;

		pthread_mutex_unlock(&mute);
	}

}


int main()
{
	/* code */
	int value;

	scanf("%d %d %d ", &a,&d,&n);

	value = 3 * n;

	//printf("%d %d %d \n",a,d,n );
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, thread1, NULL);
	pthread_create(&tid2, NULL, thread2, NULL);

	while(value--)
	{
		printf("Hello\n" );
	}


	return 0;
}