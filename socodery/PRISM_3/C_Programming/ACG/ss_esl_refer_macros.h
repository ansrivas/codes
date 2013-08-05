/********************************************************************************
 **
 ** 	FILENAME	: 	ss_esl_refer_macros.h
 **
 ** 	DESCRIPTION	:	This file contains the macros defined for the 
 ** 					Refer SLP.
 ** 					
 ** 	Revision History	:
 **     DATE		NAME		REFERENCE	     REASON
 **   ------------------------------------------------------------------------
 **   Sept 2002	  Mayank Rastogi                             Created.
 **
 ** 	 © 2006  Inc  All Rights Reserved
 **
 *******************************************************************************/

#ifndef __SS_ESL_REFER_MACRO_H
#define __SS_ESL_REFER_MACRO_H
/******************** STANDARD INCLUDE FILES *****************************/

/******************** USER INCLUDE FILES *********************************/
#include "ss_esl_traces.h"
#include "ss_esl_macros.h"

/******************** MACROS *********************************************/

#define ESL_REFER_INVALID_ARG 0

#ifdef ESL_TRACE_ENABLED
#define ESL_REFER_TRACE(trc_id, no_int_args, arg1, arg2, arg3, arg4) { \
	esl_trace_inp_st trace_inp; \
	trace_inp.trace_id = (trc_id); \
	trace_inp.service_id = ESL_SERVICE_REFER; \
	trace_inp.no_int_present = no_int_args; \
	trace_inp.integer_val[0] = (arg1); \
	trace_inp.integer_val[1] = (arg2); \
	trace_inp.integer_val[2] = (arg3); \
	trace_inp.integer_val[3] = (arg4); \
	ESL_TRACE (trace_inp); \
}
#else
#define ESL_REFER_TRACE(trc_id, no_int_args, arg1, arg2, arg3, arg4)
#endif /* end of ifdef ESL_TRACE_ENABLED */

#endif /* End of ifndef __SS_ESL_REFER_MACRO_H */
