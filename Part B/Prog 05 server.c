/*
 * Author : SkyKOG
 * File Request : Server 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERM 0666

int main()
{
    system("clear");

    int readfd,writefd,fd;
    size_t n;
    char buff[512],fname[256];

    if(mkfifo(FIFO1,S_IFIFO|PERM)<0)
        perror("FIFO1");
    if(mkfifo(FIFO2,S_IFIFO|PERM)<0)
        perror("FIFO2");
    
    printf("\n[SERVER] Waiting for connection request : \n");

    readfd = open(FIFO1,O_RDONLY,0);
    writefd = open(FIFO2,O_WRONLY,0);

    printf("\n[SERVER] Connection established\n");
    read(readfd,fname,255);

    printf("\n[SERVER] Client has requested file : %s",fname);
    if((fd=open(fname,O_RDWR))<0)
        write(writefd,"[SERVER] File dosen't exist,\n",30);
    else
        while((n=read(fd,buff,512))>0)
            write(writefd,buff,n);
    printf("\n[SERVER] Request Complete \n");

    close(fd);
    close(readfd);
    close(writefd);
    unlink(FIFO1);
    unlink(FIFO2);
    return 0;
}

