
#ifndef _MQ_DEFINES_H_
#define _MQ_DEFINES_H_

#include <stdio.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include<sys/msg.h>
#include<string.h>
#include<signal.h>

// Define the keys to be used for creating/accessing the Mesage Q
#define KEYPATH		"./msgclient.c"
typedef struct msg_buf{
	long 	mtype;
	int pid;
}msgbuf;
#endif

