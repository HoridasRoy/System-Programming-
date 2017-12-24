#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>


int main()
{
	/* code */

	int fd1, fd2;

	char* pipeName = "OsNoteBook";
	char* msgBuff[1024];
	char* responseBuff[1024];

	pid_t writer;
	pid_t reader;

	umask(0);
	mknod(pipeName,S_IFIFO|0666,0);

	writer = fork();

	if(writer < 0)
	{
		printf("fork failed\n");
	}

	else if(writer == 0)
	{
		sprintf(msgBuff,"OS is like the mother of a family who hides all difficulties from kids.-- writter: %d\n =====================================================\n",getpid());

		fd1 = open(pipeName,O_WRONLY);
		write(fd1,msgBuff,1024);
		close(fd1);
		return 0;
	}

	else
	{

	}

	reader = fork();

	if(reader < 0)
	{
		printf("fork failed\n");
	}

	else if(reader == 0)
	{

		fd2 = open(pipeName,O_RDONLY);
		read(fd2,msgBuff,1024);
		close(fd2);

		sprintf(responseBuff,"Hi, i am reader. My PID : %d. iread the latest version of OsNoteBook\n ===============================================================\n",getpid());
		
		printf("%s\n", responseBuff);
		printf("%s\n", msgBuff);
		return 0;
	}

	else
	{

	}
	return 0;
}