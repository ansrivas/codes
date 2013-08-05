/*
Message Manager header file
*/

#ifndef MSG_MGR_H
#define MSG_MGR_H

#include "prototype.h"
#include "connmgr.h"

extern ReturnType establishconnection(CommPoint * pchannelid, NodeId * pnexthop);

extern ReturnType receivepacket(CommPoint  channelid, TrsfrPacket *precvbuffer);

extern ReturnType establishconnection(CommPoint * pchannelid, NodeId * pnexthop);

extern ReturnType waitforpacket(CommPoint  * pdescriptorlist, unsigned int nsd, TrsfrPacket *precvbuffer);

extern ReturnType createmessagefrompacket(TrsfrPacket *precvbuffer, Message *pmsg);

extern ReturnType createpacketfrommessage(Message *pmsg, TrsfrPacket *precvbuffer);

extern ReturnType sendpacket(CommPoint  channelid, TrsfrPacket *psendbuffer);

#endif
