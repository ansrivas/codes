#ifndef PROTO_TYPES_H
#define PROTO_TYPES_H

typedef enum
{
	FAILURE = 0,
	SUCCESS
}ReturnType;


#define LOG_MESSAGE(X) printf(X)
#define SYS_LOG_ERROR_MESSAGE(X) perror(X)

#define NUM_CALL_EVENTS 5

typedef enum
{
	DATA_MSG=0,
	CONTROL_MSG,
	ANY
} MessageType;

typedef enum
{
	SUBS_EVT_OFF_HOOK=0,
	SUBS_EVT_DIGITS_DIALLED,
	SUBS_EVT_RELEASE,
	SUBS_EVT_INVALID,
	SUBS_EVT_DATA
}Subscriber_Call_Events;

typedef enum
{
	SWITCH_EVT_IN_PROGRESS,
	SWITCH_EVT_ANSWER,
	SWITCH_EVT_RELEASE_CNF,
	SWITCH_EVT_INVALID,
	SWITCH_EVT_DATA,
	SWITCH_EVT_NO_RESPONSE
}Switch_Call_Events;


#define LOG_MESSAGE(X) printf(X)
#define SYS_LOG_ERROR_MESSAGE(X) perror(X)

typedef struct NodeId
{
	unsigned char	ipaddress[16];
	unsigned char	port[8];
}NodeId;

typedef struct ControlMsg
{
	unsigned int 	oSubscriber;
	unsigned int	tSubscriber;
}ControlMsg;

typedef struct Message
{
	union{
		Switch_Call_Events		switchEvent;
		Subscriber_Call_Events		subscriberEvent;
	}mtype;
	union
	{
		unsigned char	anyData[60];
		ControlMsg      ctrlData;
	}data;
}Message;

typedef struct TrsfrPacket
{
	unsigned char	buffer[64];
}TrsfrPacket;

#endif
