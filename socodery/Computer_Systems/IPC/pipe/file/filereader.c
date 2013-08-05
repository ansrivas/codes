#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int readfunction()
{
	int    fd;
	int    lcounter = 0;
	size_t buffsize = 31;
	char   readbuffer[32];

	fd = open ("abcfile", O_RDONLY);
	while (lcounter++ < 16)
	{
		buffsize = read(fd, readbuffer, buffsize);
		if (buffsize > 0)
		{
			write(1, readbuffer, buffsize);
		}
		buffsize = 31;
	}
	close(fd);
	return;
}

int main ()
{
	printf("I am the reader program\n");
	readfunction();
	printf("Hall No , I am done with reading\n");
	return 1;
}
