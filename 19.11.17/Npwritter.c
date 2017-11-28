#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define Buffsize 1024

int main(int argc, char const *argv[])
{
	
	//printf("%s %s\n",argv[0], argv[1] );

	int fd;
	char *pipeName ="writterReaderpipe";
	char msgBuff[Buffsize];


	return 0;
}