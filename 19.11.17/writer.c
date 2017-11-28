#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char *argv[])
{   
    char *msgBuf = "HELLO";
    char msg[1024];
    int fd;

    umask(0);
    mknod(argv[1],S_IFIFO | 0666,0);
    mknod(argv[2],S_IFIFO | 0666,0);

    
    fd = open(argv[1],O_WRONLY);
    write(fd,msgBuf,strlen(msgBuf) + 1);
    close(fd);
    
    fd = open(argv[2],O_RDONLY);
    read(fd,msg,1024);
    close(fd);

    printf("%s",msg);
    

    /* printf("%d ",argc);
        printf("%s %s",argv[0],argv[1]);
        return 0;
    */




}