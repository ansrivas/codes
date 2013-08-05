#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFSZ 32
#define MY_FIFO "abcfile"

int readfunction()
{
        int    fd;
        int    retval = 0;
        int    lcounter = 0;
        size_t buffsize = 31;
        char   readbuffer[BUFSZ];

        retval = mkfifo("abcfile", S_IRWXU);
        if(-1 == retval)
        {
                printf("FIFO CREATION ERROR\n");
                if(EEXIST == errno)
                {
                        printf("FIFO ALREADY Exists\n");
                }
                else
                        exit(-1);
        }
        fd = open("abcfile", O_RDONLY);
        memset(readbuffer,'\0',BUFSZ);
        while (lcounter++ < 5)
        {
                buffsize = read(fd, readbuffer, buffsize);
                if (buffsize > 0)
                {       printf("I have read\n");
                        write(1, readbuffer, buffsize);
                }
                buffsize = 31;
        }
        close(fd);
	unlink(MY_FIFO);
        return 0;
}

int main ()
{

        printf("I am the reader program\n");
        readfunction();
        printf("I am done with reading\n");
        return 1;
}

