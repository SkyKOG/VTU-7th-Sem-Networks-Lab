/*
 * Author : SkyKOG
 * File Request : Client 
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666

int main()
{
    system("clear");
    size_t n;
    char buff[512],fname[256];
    int readfd,writefd;

    printf("\n[CLIENT] Trying to Connect to Server");

    writefd = open(FIFO1,O_WRONLY,0);
    readfd = open(FIFO2,O_RDONLY,0);
    
    printf("\n[CLIENT] Connected");
    printf("\n[CLIENT] Enter the filename to request from server : ");
    scanf("%s",fname);

    write(writefd,fname,strlen(fname));

    printf("\n[CLIENT] Done ...\n\n");

    while((n=read(readfd,buff,512))>0)
        write(1,buff,n);

    close(readfd);
    close(writefd);
    return 0;
}

