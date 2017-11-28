#include <stdio.h>
#include "myStaticHeader.h"

int main(int argc, char const *argv[])
{
	int a = 10;
	int b = 3;

	int x;

	 x = sum(a,b);
	printf("%d\n",x );

	 x = larger(a,b);
	printf("%d\n",x );


	x = sub(a,b);
	printf("%d\n",x );


	x = smaller(a,b);
	printf("%d\n",x );


	return 0;
}