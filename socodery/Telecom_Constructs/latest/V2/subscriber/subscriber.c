#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <sys/types.h>
#include    <sys/socket.h>
#include    <netinet/in.h>
#include    "prototype.h"
#include    "connmgr.h"
#include    "msgmgr.h"


typedef enum
{
    OFF_HOOK=0,
    SETUP_INITIATED,
    INPROGRESS,
    CONNECTED,
    TERM_INITIATED,
    TERMINATED
}CALL_STATES;


ReturnType sendpackettopeer(CommPoint sd, Message *psentvalue)
{
    ReturnType       retval = FAILURE;
    TrsfrPacket      packet;

    retval = createpacketfrommessage(psentvalue, &packet);
    if (FAILURE == retval)
    {
        return FAILURE;
    }
    retval = sendpacket(sd, &packet);
    if (FAILURE == retval)
    {
        return FAILURE;
    }
    return SUCCESS;
}


ReturnType getnextevent(CommPoint sd, Switch_Call_Events * pEvent)
{
    int             retval = FAILURE;
    TrsfrPacket     packet;
    Message         lmsg;

    retval = receivepacket(sd, &packet);
    if (FAILURE == retval)
    {
        return FAILURE;
    }
    retval = createmessagefrompacket(&packet, &lmsg);
    if (FAILURE == retval)
    {
        return FAILURE;
    }
    *pEvent = lmsg.mtype.switchEvent;
    return SUCCESS;
}


int main(int argc, char *argv[]) 
{
    CommPoint           sd = 0;
    Message             sentvalue;
    ReturnType          retval = SUCCESS;
    CALL_STATES         callstate;
    Switch_Call_Events  event;

    if (argc != 3) {
        printf("please provide following command line arguments\n");
        printf("server IP address\n");
        printf("server port\n");
        exit(1);
    }
    retval = tcpcreateactivesocketwobind(&sd);
    if (FAILURE == retval)
    {
        printf("cannot create socket \n");
        close(sd);
        exit(1);
    }

    retval = tcpconnect(sd, argv[1], argv[2]);
    if (FAILURE == retval)
    {
        printf("cannot connect to server\n");
        close(sd);
        exit(1);
    }

    callstate = OFF_HOOK;
    sentvalue.mtype.subscriberEvent=SUBS_EVT_DIGITS_DIALLED;
    retval = sendpackettopeer(sd, &sentvalue);
    if (FAILURE == retval)
    {
        printf("cannot send digits\n");
    }
    printf("sent digits\n");
    callstate = INPROGRESS;

    while (1)
    {
        retval = getnextevent(sd, &event);
        if (FAILURE == retval)
        {
            printf("cannot get event \n");
            break;
        }
        switch(callstate)
        {
            case OFF_HOOK :
                printf("program should not come here \n");
                break;
            case SETUP_INITIATED :
                printf("program should not come here \n");
                break;
            case INPROGRESS :
                switch (event)
                {
                    case SWITCH_EVT_IN_PROGRESS :
                        printf("wrong event received\n");
                        break;
                    case SWITCH_EVT_ANSWER :
                        printf("received answer\n");
                        sentvalue.mtype.subscriberEvent = SUBS_EVT_DATA;
                        retval = sendpackettopeer(sd, &sentvalue);
                        if (FAILURE == retval)
                        {
                            printf("cannot send data\n");
                        }
                	printf("sent data\n");
                        callstate = CONNECTED;
                        break;
                    case SWITCH_EVT_RELEASE_CNF :
                        break;
                    case SWITCH_EVT_INVALID :
                        break;
                    case SWITCH_EVT_DATA :
                        break;
                    case SWITCH_EVT_NO_RESPONSE :
                        callstate = TERMINATED;
                        break;
                    default:
                        break;
                }
                break;
            case CONNECTED :
                switch (event)
                {
                    case SWITCH_EVT_IN_PROGRESS :
                        break;
                    case SWITCH_EVT_ANSWER :
                        printf("received answer in connected state\n");
                        sentvalue.mtype.subscriberEvent = SUBS_EVT_DATA;
                        retval = sendpackettopeer(sd, &sentvalue);
                        if (FAILURE == retval)
                        {
                            printf("cannot send data\n");
                        }
                	printf("sent data again\n");
                        break;
                    case SWITCH_EVT_RELEASE_CNF :
                        break;
                    case SWITCH_EVT_INVALID :
                        break;
                    case SWITCH_EVT_DATA :
                        printf("received data \n");
                        sentvalue.mtype.subscriberEvent=SUBS_EVT_RELEASE;
                        retval = sendpackettopeer(sd, &sentvalue);
                        if (FAILURE == retval)
                        {
                            printf("cannot send release request\n");
                        }
                	printf("sent release\n");
                        callstate = TERM_INITIATED;
                        break;
                    case SWITCH_EVT_NO_RESPONSE :
                        callstate = TERMINATED;
                        break;
                    default:
                        break;
                }
                break;
            case TERM_INITIATED :
                switch (event)
                {
                    case SWITCH_EVT_IN_PROGRESS :
                        break;
                    case SWITCH_EVT_ANSWER :
                        break;
                    case SWITCH_EVT_RELEASE_CNF :
                        printf("received release confirmation \n");
                        callstate = TERMINATED;
                        break;
                    case SWITCH_EVT_INVALID :
                        break;
                    case SWITCH_EVT_DATA :
                        break;
                    case SWITCH_EVT_NO_RESPONSE :
                        callstate = TERMINATED;
                        break;
                    default:
                        break;
                }
                break;
            case TERMINATED :
                printf("program should not come here \n");
                break;
            default:
                printf("program should not come here \n");
                break;
        }
        if (FAILURE == retval)
            break;
        if (TERMINATED == callstate)
            break;
    }
    printf("exiting \n");
    retval = tcpcloseconnection(sd);
    if (FAILURE == retval)
    {
        return 1;
    }
    return 0;
}
