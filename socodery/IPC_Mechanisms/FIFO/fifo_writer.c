#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFSZ 32
#define MY_FIFO "abcfile"

int writefunction()
{
        int    fd;
        int    retval;
        char   writebuffer[32];
        int    lcounter = 0;
        size_t buffsize = 31;
        char readbuffer[BUFSZ];

        fd = open("abcfile", O_WRONLY);
        memset(readbuffer,'\0',BUFSZ);
        while (lcounter++ < 5)
        {
                printf("please enter the next string to send to the reader\n");
                buffsize = read(0, writebuffer, buffsize);
                if (buffsize > 0)
                {
                        write(fd, writebuffer, buffsize);
                }

                buffsize = 31;
        }
        close(fd);
        return 0;
}
int main ()
{
        printf("I am the writer program\n");
        writefunction();
        printf("I am done with writing\n");
        return 1;
}

