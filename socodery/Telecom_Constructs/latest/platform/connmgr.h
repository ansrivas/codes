/*
Connection Manager header file

*/

#ifndef CONN_MGR_H
#define CONN_MGR_H

#define SERVER_CONN_QUEUE     5

typedef int CommPoint;

extern ReturnType tcpcreatepassivesocket(char * ipaddress, char * portno, CommPoint * opsd);

extern ReturnType tcpcreateactivesocketwobind(CommPoint * opsd);

extern ReturnType tcpcreateactivesocket(char * ipaddress, char * portno, CommPoint * opsd);

extern ReturnType tcpwaitforconnection(CommPoint sd, CommPoint * opsd);

extern ReturnType tcpconnect(CommPoint sockid, char *destip, char *destport);

extern ReturnType tcpreceivedata(CommPoint  channelid, char *precvbuffer, unsigned int   datalength);

extern ReturnType tcpsenddata(CommPoint channelid, char *psendbuffer, unsigned int datalength);

extern ReturnType tcpreceivedatamultiplechannel(CommPoint *pdescriptorlist, unsigned int  ndescriptor, char *precvbuffer, unsigned int datalength);

extern ReturnType tcpcloseconnection(CommPoint channelid);

#endif
