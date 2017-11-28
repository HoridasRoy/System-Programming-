#include <stdio.h>

void fun(void *a, void *b)
{
	printf("x = %d y = %d\n",*(int *) a, *(int *) b);

}

int main()
{
	/* code */
	int x, y;
	int *p;

	x = 10;
	y = 5;

	//p = &y;

	fun(&x,&y);

	return 0;
}