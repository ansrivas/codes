#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H

#include "prototype.h"
#include "connmgr.h"

#define NUM_CALLER_STATES 6

typedef enum
{
	OCALL_IDLE_STATE=0,
	OCALL_SETUP_INITIATED,
	OCALL_INPROGRESS,
	OCALL_CONNECTED,
	OCALL_TERM_INITIATED,
	OCALL_TERMINATED
}Originating_Call_States;


typedef struct OriginatingCall
{
	Originating_Call_States		state;
	CommPoint			oComPoint;
	CommPoint			dComPoint;
	unsigned int			oSubscriber;
	unsigned int			tSubscriber;
}OriginatingCall;

typedef ReturnType (*oCallEventHandler)(OriginatingCall *, Message *);


#endif
