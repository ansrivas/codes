#ifndef CALL_LIB_H
#define CALL_LIB_H
/*
call lib header File
*/

#include	<stdio.h>
#include	"basictypes.h"
#include	"msgmgr.h"


extern ReturnType defaulthandler(OriginatingCall * pcallobj, Message * pmsg);
extern ReturnType datatransfer(OriginatingCall * pcallobj, Message * pmsg);
extern ReturnType callrelease(OriginatingCall * pcallobj, Message * pmsg);
extern ReturnType callsetup(OriginatingCall * pcallobj, Message * pmsg);
extern ReturnType callanswer(OriginatingCall * pcallobj, Message * pmsg);

#endif
