#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define Buffsize 1024

int main()
{
	/* code */
	int fd;
	char *pipeName ="writterReaderpipe";
	char msgBuff[Buffsize];
	pid_t P_PID;

	P_PID = getpid();

	umask(0);

	//mknod(pipeName,S_IFIFO | 0666, 0);

	printf("I am process :%d. I have read a funny story. Should i believe it? \n", P_PID);

	fd = open(pipeName, O_RDONLY);
	read(fd,msgBuff,Buffsize);
	close(fd);

	printf("Message from writter: %s\n", msgBuff);
	
	return 0;
}