#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <sys/time.h>
#include    <sys/types.h>
#include    <sys/socket.h>
#include    <netinet/in.h>
#include    "prototype.h"
#include    "platform.h"
#include    "connmgr.h"
#include    "msgqueue.h"
#include    "threadmgr.h"
#include    "msgmgr.h"
#include    "timerutility.h"

#define     RESEND_LIMIT      2
#define     TIMEOUT_PERIOD    500

typedef enum
{
    OFF_HOOK=0,
    SETUP_INITIATED,
    INPROGRESS,
    CONNECTED,
    TERM_INITIATED,
    TERMINATED
}CALL_STATES;

typedef enum
{
    EVT_IN_PROGRESS,
    EVT_ANSWER,
    EVT_RELEASE_CNF,
    EVT_INVALID,
    EVT_DATA,
    EVT_NO_RESPONSE,
    EVT_TIMER_EXPIRED,
    EVT_COMMUNICATION_ERROR
}CALL_EVENTS;


typedef struct timerexp
{
    TimerIdType     tId;
}timerExpType;

typedef enum
{
    PACKET_RCVD=0,
    TIMER_EXP,
    COMM_ERROR
} enumEventType;

typedef struct eventType
{
    enumEventType  event;
    union
    {
        timerExpType    timer;
        Message         peermsg;
    } eventObj;
}eventType;


MessageQue     *gQ;


void * timerExpHandler(void * pData)
{
    ReturnType      retval;
    struct timeval    tv;

    gettimeofday(&tv, NULL);
    printf("timer expired : %ld : %ld\n", tv.tv_sec, tv.tv_usec);

    timerExpType *pTimerExpData = (timerExpType*)pData;
    eventType    *pEvent  = NULL;
    pEvent = (eventType *)malloc(sizeof(eventType));
    pEvent->event = TIMER_EXP;
    memcpy(&pEvent->eventObj.timer, pTimerExpData, sizeof(timerExpType));
    retval = putqueue(gQ, pEvent);
    if (FAILURE == retval)
    {
        printf("could not put timer in the queue \n");
    }
    return NULL;
}


ReturnType sendpackettopeer(CommPoint sd, Message *psentvalue, timerExpType * ptimerData)
{
    ReturnType       retval = 0;
    TrsfrPacket         packet;

    retval = createpacketfrommessage(psentvalue, &packet);
    if (FAILURE == retval)
    {
        return FAILURE;
    }
    retval = tcpsenddata(sd, (char *)&packet, sizeof(packet));
    if (FAILURE == retval)
    {
        return FAILURE;
    }
    if (NULL != ptimerData)
    {
        retval = createtimer(TIMEOUT_PERIOD, 1, timerExpHandler, ptimerData, &ptimerData->tId);
        if (FAILURE == retval)
        {
            printf("cannot create a timer");
            return FAILURE;
        }
    }
    return SUCCESS;
}


void * receivedataonchannel(void * pInput)
{
    int             cretval = FAILURE;
    int             qretval = FAILURE;
    eventType       *pEvent = NULL;
    CommPoint       sd = *(CommPoint *)pInput;
    TrsfrPacket     packet;

    while(1)
    {
        cretval = tcpreceivedata(sd, (char *)&packet, sizeof(TrsfrPacket));
        if (FAILURE == cretval)
        {
            break;
        }
        else
        {
            pEvent = (eventType *)malloc(sizeof(eventType));
            pEvent->event = PACKET_RCVD;
            createmessagefrompacket(&packet, &pEvent->eventObj.peermsg);
        }
        qretval = putqueue(gQ, pEvent);
        if (FAILURE == qretval)
        {
            free(pEvent);
            break;
        }
    }
    return NULL;
}


ReturnType getevent(CALL_EVENTS * pEvent, Message *precvdvalue)
{
    eventType        *pObject = NULL;
    pObject = (eventType*) getqueue(gQ);
    if (NULL == pObject)
    {
        return FAILURE;
    }
    if (TIMER_EXP == pObject->event)
    {
        *pEvent    = EVT_TIMER_EXPIRED;
    }
    else if (COMM_ERROR == pObject->event)
    {
        *pEvent    = EVT_COMMUNICATION_ERROR;
    }
    else if (PACKET_RCVD == pObject->event)
    {
        *pEvent = (CALL_EVENTS)pObject->eventObj.peermsg.mtype.switchEvent;
    }
    free(pObject);
    return SUCCESS;
}


int main(int argc, char *argv[]) 
{
    CommPoint          sd = 0;
    Message            sentvalue;
    Message            recvdvalue;
    ThreadData         thrObj;
    timerExpType       timerData;
    ReturnType         retval = SUCCESS;
    CALL_EVENTS        event;
    CALL_STATES        state;

    if (argc != 3) {
        printf("please provide following command line arguments\n");
        printf("server IP address\n");
        printf("server port\n");
        exit(1);
    }
    retval = initializeplatform();
    if (FAILURE == retval)
    {
        printf("platform initialization failed");
        exit(1);
    }

    gQ = createmsgqueue();
    if (NULL == gQ)
    {
        printf("internal message queue creation failed ");
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
    thrObj.state                = INACTIVE;
    thrObj.available            = FREE;
    thrObj.type                 = STANDALONE;
    thrObj.execEnv.fcnObj.pFptr = receivedataonchannel;
    thrObj.execEnv.fcnObj.pArg  = &sd;
    retval = createthread(&thrObj);
    if (FAILURE == retval)
    {
        printf("cannot create a thread to receive data on socket\n");
        close(sd);
        exit(1);
    }

    state = OFF_HOOK;
    printf("sending digits : offhook state\n");
    sentvalue.mtype.subscriberEvent=SUBS_EVT_DIGITS_DIALLED;
    retval = sendpackettopeer(sd, &sentvalue, &timerData);
    if (FAILURE == retval)
    {
        printf("cannot send digits\n");
    }
    state = INPROGRESS;
    printf("going to : inprogress state\n");

    while (1)
    {
        retval = getevent(&event, &recvdvalue);
        if (FAILURE == retval)
        {
                printf("cannot get event \n");
                break;
        }
        switch(state)
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
                    case EVT_IN_PROGRESS :
                        break;
                    case EVT_ANSWER :
                        printf("received answer : inprogress state\n");
                        retval = deletetimer(timerData.tId);
                        if (FAILURE == retval)
                        {
                            printf("can not delete timer\n");
                        }
                        else
                        {
                            printf("timer deleted\n");
                        }
        		printf("sending data : inprogress state\n");
                        sentvalue.mtype.subscriberEvent=SUBS_EVT_DATA;
                        retval = sendpackettopeer(sd, &sentvalue, NULL);
                        if (FAILURE == retval)
                        {
                            printf("cannot send data\n");
                        }
                	printf("going to : connected state\n");
                        state = CONNECTED;
                        break;
                    case EVT_RELEASE_CNF :
                        break;
                    case EVT_INVALID :
                        break;
                    case EVT_DATA :
                        break;
                    case EVT_NO_RESPONSE :
                        state = TERMINATED;
                        break;
                    case EVT_TIMER_EXPIRED :
                        printf("timer expired : inprogress state\n");
        		printf("sending digits again: inprogress state\n");
                        sentvalue.mtype.subscriberEvent=SUBS_EVT_DIGITS_DIALLED;
                        retval = sendpackettopeer(sd, &sentvalue, &timerData);
                        if (FAILURE == retval)
                        {
                            printf("cannot send digits\n");
                        }
                        break;
                    case EVT_COMMUNICATION_ERROR :
                        state = TERMINATED;
                        break;
                    default:
                        break;
                }
                break;
            case CONNECTED :
                switch (event)
                {
                    case EVT_IN_PROGRESS :
                        break;
                    case EVT_ANSWER :
                        printf("received answer : connected state\n");
        		printf("ignore : connected state\n");
                        break;
                    case EVT_RELEASE_CNF :
                        break;
                    case EVT_INVALID :
                        break;
                    case EVT_DATA :
                        printf("received data : connected state\n");
        		printf("sending release : connected state\n");
                        sentvalue.mtype.subscriberEvent=SUBS_EVT_RELEASE;
                        retval = sendpackettopeer(sd, &sentvalue, &timerData);
                        if (FAILURE == retval)
                        {
                            printf("cannot send release request\n");
                        }
                	printf("going to : term_init state\n");
                        state = TERM_INITIATED;
                        break;
                    case EVT_NO_RESPONSE :
                        state = TERMINATED;
                        break;
                    case EVT_TIMER_EXPIRED :
                        printf("timer expired : connected state\n");
        		printf("sending release again : connected state\n");
                        sentvalue.mtype.subscriberEvent=SUBS_EVT_RELEASE;
                        retval = sendpackettopeer(sd, &sentvalue, &timerData);
                        if (FAILURE == retval)
                        {
                            printf("cannot send release request\n");
                        }
                	printf("going to : term_init state\n");
                        state = TERM_INITIATED;
                        break;
                    case EVT_COMMUNICATION_ERROR :
                        state = TERMINATED;
                        break;
                    default:
                        break;
                }
                break;
            case TERM_INITIATED :
                switch (event)
                {
                    case EVT_IN_PROGRESS :
                        break;
                    case EVT_ANSWER :
                        break;
                    case EVT_RELEASE_CNF :
                        printf("received release confirm : connected state\n");
                        retval = deletetimer(timerData.tId);
                        if (FAILURE == retval)
                        {
                            printf("can not delete timer\n");
                        }
                        else
                        {
                            printf("timer deleted\n");
                        }
                	printf("going to : terminated state\n");
                        state = TERMINATED;
                        break;
                    case EVT_INVALID :
                        break;
                    case EVT_DATA :
                        break;
                    case EVT_NO_RESPONSE :
                        state = TERMINATED;
                        break;
                    case EVT_TIMER_EXPIRED :
                        printf("timer expired data : term_init state\n");
        		printf("sending release again : term_init state\n");
                        sentvalue.mtype.subscriberEvent=SUBS_EVT_RELEASE;
                        retval = sendpackettopeer(sd, &sentvalue, &timerData);
                        if (FAILURE == retval)
                        {
                            printf("cannot send release\n");
                        }
                        break;
                    case EVT_COMMUNICATION_ERROR :
                        state = TERMINATED;
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
        if (TERMINATED == state)
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
