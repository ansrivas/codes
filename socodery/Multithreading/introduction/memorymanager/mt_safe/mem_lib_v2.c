/*
More optimized implementation of thread safe memory manager
free and init functions have been optimized
find out if these optimizations will work or not
*/

#include<stdio.h>
#include<pthread.h>

#define FREE 0
#define BUSY 1
#define NOT_INITIALIZED 0
#define INITIALIZED 	1

#define MAX_BLOCKS 	2
#define MAX_BLOCK_SIZE	1024

typedef struct block_info
{
	unsigned char status; /* block is free or used */
	char data[MAX_BLOCK_SIZE];
}Block_Info;

pthread_mutex_t gmutex   = PTHREAD_MUTEX_INITIALIZER;
Block_Info memory_block_arr[MAX_BLOCKS];

static int initindicator = NOT_INITIALIZED;

int init()
{
	if (NOT_INITIALIZED == initindicator)
	{
		pthread_mutex_lock(&gmutex);
		if (NOT_INITIALIZED == initindicator)
		{
			//it may be better if we set the individual fields of structures in the array
			memset(memory_block_arr, 0, MAX_BLOCKS*sizeof(Block_Info));
			initindicator = INITIALIZED;
		}
		pthread_mutex_unlock(&gmutex);
	}
}

char * mymalloc(int size)
{
#ifdef  STD_LIB_IMPL
	return ((char*)malloc(size));
#else
	int lindex;

	if(size > MAX_BLOCK_SIZE)
	{
		return (NULL);
	}

	init();

	pthread_mutex_lock(&gmutex);
	/* find a free block */
	for(lindex = 0; lindex< MAX_BLOCKS; lindex++)
	{
		if(FREE == memory_block_arr[lindex].status)
		{
			memory_block_arr[lindex].status = BUSY;
			pthread_mutex_unlock(&gmutex);
			return((char *)&memory_block_arr[lindex].data);
		}
		else
		{
			/*all the blocks have been allocated, could not 
			find any free block*/
			if((MAX_BLOCKS - 1) == lindex)
			{
				pthread_mutex_unlock(&gmutex);
				return(NULL); 
			}
		}
	}

#endif
}


void myfree(char * address)
{
#ifdef  STD_LIB_IMPL
	free(address);
#else
	int lindex;
	/* find the block by a linear search which has been freed by the user and mark that free */
	for(lindex = 0; lindex< MAX_BLOCKS; lindex++)
	{
		if(address == (char *)&memory_block_arr[lindex].data)
			memory_block_arr[lindex].status = FREE;
	}
#endif
}
