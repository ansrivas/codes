********************************************************************************
 **
 **     FILENAME    :   ss_esl_refer_types.h
 **
 **     DESCRIPTION :   This file contains the data types  defined for the
 **                     Refer SLP.
 **                     
 **     Revision History    :
 **         DATE        NAME                REFERENCE            REASON
 **         ----------------------------------------------------------
 **         Sept 2002  Mayank Rastogi                            Created.
 **
 **      © 2006  Inc  All Rights Reserved
 **
 *******************************************************************************/

#ifndef __SS_ESL_REFER_TYPES_H
#define __SS_ESL_REFER_TYPES_H


/******************** STANDARD INCLUDE FILES *****************************/

/* global hearders */
#include "ss_esl_types.h"
#include "ss_esl_ecodes.h"
#include "ss_esl_sfa_api.h"
#include "ss_esl_interface.h"

/******************** USER INCLUDE FILES *********************************/

/******************** DEFINES, CONSTANTS, LITERALS ***********************/ 
/*
 * This is to be extracted from ESLDB. Presently using a constant 
 * in deci secs ( 100 ms) 
 */

/* Duration between Confirm sent to SF and Disconnect received from party B */
#define ESL_REFER_DURATION           200

/******************** TYPEDEFS, ENUMS ************************************/ 

/* SCA CL, PL IDs */
#define ESL_REFER_OBCSM_CL_ID         1
#define ESL_REFER_OBCSM_PL_A_ID       2        
#define ESL_REFER_TBCSM_CL_ID         2
#define ESL_REFER_TBCSM_PL_A_ID       1

/* sca leg PL2, created after split leg over CL  */
#define ESL_REFER_PL_2_ID             3

/* sca leg PL2  */
#define ESL_REFER_PL_C_ID             4

/* new CS sca ID */
#define ESL_REFER_ORIG_CS_ID          1
#define ESL_REFER_NEW_CS_ID           2

/* Flags used in FSM */
typedef esl_U32bit esl_refer_event_flag_t;

#define ESL_REFER_AWT_UPD_CTRL_BLK_RESP   0x00000001
#define ESL_REFER_ALLOWED                 0x00000002
#define ESL_REFER_DL_SENT_OVR_PL_2        0x00000004
#define ESL_REFER_TIMER_STARTED           0x00000008
#define ESL_REFER_CONFIRM_SENT            0x00000010
#define ESL_REFER_DL_SENT_OVR_CL          0x00000020
#define ESL_REFER_PARTY_A_LOCAL           0x00000040

/*
 * Enum for Refer States.
 */

typedef enum {

   ESL_REFER_00_NULL = 0,
   ESL_REFER_01_AWT_SPLIT_LEG_RESP,
   ESL_REFER_02_AWT_PARTY_C_INFO,
   ESL_REFER_03_AWT_RMT_PARTY_ANSWER,
   ESL_REFER_04_AWT_RELEASE_IND,
   ESL_REFER_05_AWT_DIS_LEG_RESP,
   ESL_REFER_MAX_STATES

} esl_refer_state_et;


/*
 * Enum for Refer Events.
 */


typedef enum {

   ESL_REFER_EVT_INITIAL_DP = 0,
   ESL_REFER_EVT_SPLIT_LEG_RESP,
   ESL_REFER_EVT_PARTY_C_INFO,
   ESL_REFER_EVT_ANSWER,
   ESL_REFER_EVT_PARTY_A_DISCONNECT,
   ESL_REFER_EVT_PARTY_B_DISCONNECT,
   ESL_REFER_EVT_PARTY_C_DISCONNECT,
   ESL_REFER_EVT_REFER_TIMEOUT,
   ESL_REFER_EVT_DIS_LEG_RESP,
   ESL_REFER_MAX_EVENTS

}  esl_refer_event_et;


typedef enum {

   ESL_REFER_ORIGINATING_CALL = 0,
   ESL_REFER_TERMINATING_CALL,
   ESL_REFER_FIRST_CALL_NULL

}  esl_refer_call_type_et;


typedef enum {

   ESL_REFER_SEND_TC_END = 0,
   ESL_REFER_SEND_REL_MSG

}  esl_refer_end_proc_et;


typedef esl_U8bit esl_sub_t;

/* Hash defines for subscriger type to be sent in  esl_sub_t
 * check_n_add */
# define ESL_SUB_A   0x01
# define ESL_SUB_C   0x02

/*
 * Control Block structure for Refer.
 */

typedef struct {

                                /* Current State of the control association. */
   esl_refer_state_et             curr_state;

                                /* Previous State of the control association. */
   esl_refer_state_et             prev_state;

                                /* Event recieved.*/
   esl_refer_event_et             event;

                                /* CL leg id value cud be either 1 or 2. */
   esl_sfa_sca_leg_id_t         cl_id;

                                /* PL Leg id in inital CS cud be either 1 or 2 */
   esl_sfa_sca_leg_id_t         pl_A_id;

                                /* Sus events within state */
   esl_refer_event_flag_t       event_flag;

                                 /* To remember whether first call
                                 * was originating or terminating. */
   esl_refer_call_type_et       first_call_type;

                                /*  A party address */
   esl_sfa_address_st           *p_party_A_address;

                                /*  B party address */
   esl_sfa_address_st           *p_party_B_address;

                                /*  Forwarding info received in initial DP */
   esl_sfa_forwarding_info_st   *p_forwarding_info;

                                /*  Refer information received in initial DP */
   esl_sfa_sip_refer_info_st    *p_refer_info;

                                /* timer id for refer timer. It is 0 if no timer
                                 * have been started */
   esl_U32bit                   refer_timer_id;

                                /* Current State of the control association. */
   esl_boolean_et               is_valid;

   esl_sub_t                    sub_type;
                                /* Indicates whether the A or C or both have 
                                 * been added. */

} esl_refer_ctrl_blk_st;



/*
 * Process Data Block Structure for Refer. 
 */

typedef struct {

                                /* Pointer to recieved message */
esl_service_message_st      *p_recv_msg;

                                /* Pointer to message to be sent */
esl_pvoid                   *p_send_msg;

                                /* Id of the allocated Control Block by SLP*/
esl_ctrl_blk_id_t            ctrl_blk_id;

                                /* Pointer to Control Block used */
esl_refer_ctrl_blk_st        *p_ctrl_blk;

                                /* For bufferring events by SLP */
esl_refer_event_et           event;

                                /* Error code */
esl_response_et              *p_ecode;

                                /*
                                 * Status to SLM specifying whether service is
                                 * is continuing or not.
                                 */
esl_status_et                *p_status;

                                /*
                                 * Specifies whether to end service by sending
                                 * TC end or not.
                                 */
esl_refer_end_proc_et        end_proc;

esl_sfa_cause_et             release_cause;

} esl_refer_pdb_st;


/* 
 * FSM function pointers definition 
 */
typedef esl_return_et  (*esl_refer_fsm_func_ptr_t) (
      INOUT esl_refer_pdb_st      *p_pdb );

#endif
