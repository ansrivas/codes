#ifndef PROTO_TYPES_H
#define PROTO_TYPES_H

typedef enum
{
	FAILURE = 0,
	SUCCESS
}returntype;

#define LOG_MESSAGE(X) printf(X)
#define SYS_LOG_ERROR_MESSAGE(X) perror(X)

#endif
