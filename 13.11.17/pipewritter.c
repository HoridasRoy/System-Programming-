#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	/* code */
	char *pipeName = "writterReaderpipe";
	int fd;
	char *str1 ="Hi, I am process -";

	char *str2 ="I would like to tell you a story. I will continue writting if you like it \n\n Once upon a time there were a frog prince and butterfly princess.\n There parentswere a Banyan tree and a river .";

	char msgBuff[20000];

	sprintf(msgBuff, "%s. %d . %s",str1,getpid(),str2);

	umask(0);

	mknod(pipeName,S_IFIFO | 0666, 0);

	for(int i = 0; i < 3; i++)
	{
		fd = open(pipeName, O_WRONLY);

		write(fd,msgBuff,20000);

		close(fd);
	}

	
	return 0;
}