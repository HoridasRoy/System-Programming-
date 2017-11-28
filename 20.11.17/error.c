#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


int main()
{
	/* code */
	int fd;

	

	fd = open("abc", O_RDONLY);

	if(fd == -1 ){

		int errNO = errno;

		printf("%d\n",errNO );
		perror("Error during open()");

		return 1;
	}

	return 0;
}