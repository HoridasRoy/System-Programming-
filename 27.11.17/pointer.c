#include <stdio.h>

void sum(void *x, void *y)
{
	float sum;

	sum = *(float *) x + *(float *) y;

	printf("%f\n",sum );
}

int main()
{
	/* code */

	float x, y;
	//int x,y;
	x = 5;
	y = 10;

	sum(&x, &y);

	//printf("\n");


	return 0;
}