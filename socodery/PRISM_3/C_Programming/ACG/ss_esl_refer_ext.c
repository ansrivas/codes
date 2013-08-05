/*********************************************************************************
 **
 **     FILENAME       :    ss_esl_refer_ext.c
 **
 **     DESCRIPTION    :    This file defines the functions which send 
 **                         external messages for Refer.
 **                     
 **     Revision History    :
 **     DATE        NAME                REFERENCE            REASON
 **     ----------------------------------------------------------
 **     Sept 2002  Mayank Rastogi                           Created.
 **
 **      © 2006  Inc  All Rights Reserved
 **
 ********************************************************************************/

#include "ss_esl_refer_types.h"
#include "ss_esl_refer_fp.h"
#include "ss_esl_refer_macros.h"
#include "ss_esl_sib_fp.h"


/*********************************************************************************
 **
 **  FUNCTION NAME   :    ss_esl_refer_arm
 **
 **  DESCRIPTION     :    In this function sends a call event request 
 **                       to SF for arming the specified event on the 
 **                       specified leg.
 **
 **  RETURNS         :    ESL_SUCCESS, and in case of any error ESL_FAILURE
 **                       with the corresponding ecode.
 **
 ********************************************************************************/

esl_return_et ss_esl_refer_arm
(
   INOUT esl_refer_pdb_st           *p_pdb, 
   IN    esl_sfa_call_event_et      event_type,
   IN    esl_sfa_notification_et    mode,
   IN    esl_U32bit                 sca_leg_id
)
{
   if (ESL_FAILURE == ss_esl_slp_call_event_req(
                              ESL_NULL,
                              p_pdb->p_recv_msg->p_api_msg_hdr,
                              event_type,
                              mode,
                              ESL_SFA_INVALID_ID,
                              sca_leg_id,
                              ESL_SFA_EVENT_CRITERIA_UNDEFINED,
                              0,
                              0,
                              p_pdb->p_ecode))
   {
      return ESL_FAILURE;
   }

   ESL_REFER_TRACE(ESL_TRACE_REFER_SENT_EDP_R_REQ, ESL_THREE_INT_PRESENT,
   p_pdb->ctrl_blk_id, sca_leg_id, event_type, ESL_REFER_INVALID_ARG)

   return ESL_SUCCESS;
}


/*********************************************************************************
 **
 **    FUNCTION NAME   :    ss_esl_refer_send_split_leg
 **
 **    DESCRIPTION      : In this function sends a split leg request to SF.
 **
 **  RETURNS         :   ESL_SUCCESS, and in case of any error ESL_FAILURE
 **                      with the corresponding ecode.
 **
 ********************************************************************************/

esl_return_et ss_esl_refer_send_split_leg
(
   INOUT esl_refer_pdb_st *p_pdb
)
{
   esl_sfa_split_leg_st *p_split_leg = ESL_NULL;
   esl_return_et         ret_val = ESL_SUCCESS;
   esl_U32bit            optional_fields_flag = ESL_SFA_INVALID_ID;

   optional_fields_flag = ESL_SFA_INVALID_ID |
                          ESL_SFA_SPLIT_LEG_NEW_CS_ID_MASK |
                          ESL_SFA_SPLIT_LEG_NEW_LEG_ID_MASK;

   ret_val = ss_esl_slp_send_split_leg(
                  p_split_leg, 
                  p_pdb->p_recv_msg->p_api_msg_hdr,
                  p_pdb->p_ctrl_blk->cl_id,
                  optional_fields_flag,
                  ESL_REFER_NEW_CS_ID,
                  ESL_REFER_PL_2_ID,
                  p_pdb->p_ecode);
   if (ESL_SUCCESS == ret_val)
   {
      ESL_REFER_TRACE(ESL_TRACE_REFER_SENT_SPLIT_LEG_REQ, ESL_FOUR_INT_PRESENT,
      p_pdb->ctrl_blk_id, p_pdb->p_ctrl_blk->cl_id, ESL_REFER_NEW_CS_ID,
      ESL_REFER_PL_2_ID)
   }

   return ret_val;
}


/*********************************************************************************
 **
 **  FUNCTION NAME : ss_esl_refer_send_disconnect_leg
 **
 **  DESCRIPTION   : In this function sends a disconnect_leg request to SF.
 **
 **  RETURNS       : ESL_SUCCESS, and in case of any error ESL_FAILURE
 **                  with the corresponding ecode.
 **
 ********************************************************************************/

esl_return_et ss_esl_refer_send_disconnect_leg
(
   INOUT esl_refer_pdb_st        *p_pdb,
   IN    esl_sfa_sca_leg_id_t    sca_leg_id
)
{
   esl_return_et  ret_val = ESL_SUCCESS;

   ret_val = ss_esl_slp_send_disconn_leg(
                  ESL_NULL, 
                  p_pdb->p_recv_msg->p_api_msg_hdr,
                  ESL_SFA_INVALID_ID,
                  sca_leg_id,
                  0,
                  0,
                  p_pdb->p_ecode);
   if (ESL_SUCCESS == ret_val)
   {
      ESL_REFER_TRACE(ESL_TRACE_REFER_SENT_DISCONN_LEG, ESL_THREE_INT_PRESENT,
      p_pdb->ctrl_blk_id, sca_leg_id, 0, ESL_REFER_INVALID_ARG)
   }

   return ret_val;
}


/*********************************************************************************
 **
 **  FUNCTION NAME : ss_esl_refer_send_connect
 **
 **  DESCRIPTION   : This function sends a connect request to SF.
 **
 **  RETURNS       : ESL_SUCCESS, and in case of any error ESL_FAILURE
 **                  with the corresponding ecode.
 **
 ********************************************************************************/
esl_return_et ss_esl_refer_send_connect
(
   INOUT esl_refer_pdb_st    *p_pdb
)
{
   esl_U32bit            msg_len;
   esl_sfa_connect_st    *p_connect;
   esl_return_et         ret_val = ESL_SUCCESS;
   esl_refer_ctrl_blk_st *p_ctrl_blk = ESL_NULL;

   msg_len = sizeof(esl_sfa_connect_st) + sizeof(esl_sfa_sip_refer_info_st);
   
   p_ctrl_blk = p_pdb->p_ctrl_blk;

   ESL_MEMGET(msg_len, p_connect, p_pdb->p_ecode, ret_val)

   p_connect->optional_fields_flag = ESL_SFA_CONNECT_CALL_STATE_INFO_MASK;

   p_connect->call_state_info.misc_info.info_type = ESL_SFA_INVALID_ID;
   p_connect->call_state_info.state_info.report_type = 
                                  ESL_SFA_TRIGGER_REPORT_CALLED_PARTY_ADDRESS ;
   
   p_connect->call_state_info.state_info.called_party_address = 
                                 p_ctrl_blk->p_refer_info->contact_address;

   if (ESL_NULL != p_ctrl_blk->p_party_A_address)
   {
       p_connect->call_state_info.state_info.report_type |= 
                                  ESL_SFA_TRIGGER_REPORT_CALLING_PARTY_ADDRESS ;
       p_connect->call_state_info.state_info.calling_party_address =
                          *(p_ctrl_blk->p_party_A_address);
   }

   p_connect->call_state_info.state_info.report_type |= 
                         ESL_SFA_TRIGGER_REPORT_FORWARDING_INFO;
   p_connect->call_state_info.state_info.forwarding_info.optional_fields_flag =
						 ESL_SFA_INVALID_ID;

   if ((ESL_NULL != p_ctrl_blk->p_forwarding_info) &&
      (ESL_SFA_FORWARDING_INFO_ORIGINAL_CALLED_PARTY_NUM & p_ctrl_blk-> \
					   p_forwarding_info->optional_fields_flag))
   {
	   p_connect->call_state_info.state_info.forwarding_info. \
	   original_called_party_address = 
				p_ctrl_blk->p_forwarding_info->original_called_party_address;
       p_connect->call_state_info.state_info.forwarding_info.optional_fields_flag |=
	   ESL_SFA_FORWARDING_INFO_ORIGINAL_CALLED_PARTY_NUM;
   }
   else
   {
	   p_connect->call_state_info.state_info.forwarding_info. \
				 original_called_party_address = *(p_ctrl_blk->p_party_B_address);
       p_connect->call_state_info.state_info.forwarding_info.optional_fields_flag |=
	   ESL_SFA_FORWARDING_INFO_ORIGINAL_CALLED_PARTY_NUM;
   }

   p_connect->call_state_info.state_info.forwarding_info. \
				 redirecting_party_address = *(p_ctrl_blk->p_party_B_address);
   p_connect->call_state_info.state_info.forwarding_info.optional_fields_flag |=
                 ESL_SFA_FORWARDING_INFO_REDIRECTING_NUM;

   p_connect->call_state_info.state_info.forwarding_info.optional_fields_flag |=
                 ESL_SFA_FORWARDING_INFO_REDIRECTION_INFO;

   if ((ESL_NULL != p_ctrl_blk->p_forwarding_info) &&
      (ESL_SFA_FORWARDING_INFO_REDIRECTION_INFO & 
					   p_ctrl_blk->p_forwarding_info->optional_fields_flag))
   {
	   p_connect->call_state_info.state_info.forwarding_info.redirection_info. \
	       orig_redirecting_reason = 
	       p_ctrl_blk->p_forwarding_info->redirection_info.orig_redirecting_reason;
	   p_connect->call_state_info.state_info.forwarding_info.redirection_info. \
	       redirecting_ctr++; 
   }
   else
   {
	   p_connect->call_state_info.state_info.forwarding_info.redirection_info. \
	       orig_redirecting_reason = ESL_SFA_ORIGINAL_REDIRECTING_REASON_UNCONDITIONAL;
	   p_connect->call_state_info.state_info.forwarding_info.redirection_info. \
	       redirecting_ctr = 1; 
   }

   p_connect->call_state_info.state_info.forwarding_info.redirection_info. \
   redirecting_ind = ESL_SFA_CALL_DIVERTED;

   p_connect->call_state_info.state_info.forwarding_info.redirection_info. \
   redirecting_reason = ESL_SFA_REDIRECTING_REASON_UNCONDITIONAL;

   p_connect->optional_fields_flag |= ESL_SFA_CONNECT_SERVICE_EVENT_INFO_MASK;
   p_connect->service_event_info.req_event.req_type = 
   (esl_sfa_service_event_req_type_et) ESL_SFA_SERVICE_EVENT_REQ_INFO_SIP_MSG;
   p_connect->service_event_info.req_event.service_event_req.sip_msg_req. \
   info_type = ESL_SFA_SIP_MSG_REQ_INFO_MSG_TYPE;
   p_connect->service_event_info.req_event.service_event_req.sip_msg_req. \
   msg_type = (esl_sfa_sip_msg_type_t) ESL_SFA_SS_OP_SIP_REFER;
   p_connect->service_event_info.req_event.service_event_req.sip_msg_req. \
   info_type |= ESL_SFA_SIP_MSG_REQ_INFO_ENCODE_MODE;
   p_connect->service_event_info.req_event.service_event_req.sip_msg_req. \
   encode_mode = ESL_SFA_DECODE_MODE;
   p_connect->service_event_info.service_data_len = 
                                             sizeof(esl_sfa_sip_refer_info_st);
   ret_val = ss_esl_memcpy((esl_U8bit *)(p_ctrl_blk->p_refer_info),
                               sizeof(esl_sfa_sip_refer_info_st),
                               p_connect->service_event_info.service_data);
   if (ESL_SUCCESS != ret_val)
   {
       *p_pdb->p_ecode = ESL_INVALID_MEMCPY;
       return (ret_val);
   }

   p_connect->optional_fields_flag |= ESL_SFA_CONNECT_LEG_ID_MASK;

   if (ESL_FAILURE == ss_esl_slp_send_connect(
                        p_connect,
                        p_pdb->p_recv_msg->p_api_msg_hdr,
                        ESL_SFA_INVALID_ID,
                        p_ctrl_blk->pl_A_id,
                        p_connect->optional_fields_flag,
                        ESL_SFA_INVALID_ID,
                        ESL_REFER_PL_C_ID,
                        p_pdb->p_ecode))
   {
      return ESL_FAILURE;
   }

   ESL_REFER_TRACE(ESL_TRACE_REFER_SENT_CONNECT, ESL_INT_NOT_PRESENT,
   ESL_REFER_INVALID_ARG, ESL_REFER_INVALID_ARG, ESL_REFER_INVALID_ARG, 
   ESL_REFER_INVALID_ARG)

   return ESL_SUCCESS;
}


/*********************************************************************************
 **
 **  FUNCTION NAME : ss_esl_refer_send_continue
 **
 **  DESCRIPTION   : In this function we send continue to SF.
 **
 **  RETURNS       : ESL_SUCCESS, and in case of any error ESL_FAILURE
 **                  with the corresponding ecode.
 **
 ********************************************************************************/

esl_return_et ss_esl_refer_send_continue
(
   INOUT esl_refer_pdb_st        *p_pdb,
   IN    esl_sfa_sca_leg_id_t    sca_leg_id
)
{
   esl_return_et                  ret_val = ESL_SUCCESS;

   ret_val = ss_esl_slp_send_continue(
                  ESL_NULL,
                  p_pdb->p_recv_msg->p_api_msg_hdr,
                  ESL_SFA_INVALID_ID,
                  sca_leg_id,
                  ESL_SFA_INVALID_ID,
                  ESL_SFA_INVALID_ID,
                  ESL_SFA_INVALID_ID,
                  ESL_SFA_INVALID_ID,
                  p_pdb->p_ecode);
   if (ESL_SUCCESS == ret_val)
   {
      ESL_REFER_TRACE(ESL_TRACE_REFER_SENT_CONTINUE, ESL_TWO_INT_PRESENT,
                      p_pdb->ctrl_blk_id, sca_leg_id, ESL_REFER_INVALID_ARG, 
                      ESL_REFER_INVALID_ARG)
   }

   return ret_val;
}


/*********************************************************************************
 **
 **   FUNCTION NAME :  ss_esl_refer_send_tc_end
 **
 **   DESCRIPTION   :  This function sends an abort request to
 **                    SF for a given transaction with is_normal flag
 **                    signifying TC_END (TRUE) and TC_ABORT (FALSE)
 **
 **   RETURNS       :  ESL_SUCCESS, in case of success,
 **                    else, ESL_FAILURE with the corresponding ecode.
 **
 ********************************************************************************/

esl_return_et ss_esl_refer_send_tc_end 
(
   INOUT esl_refer_pdb_st   *p_pdb
)
{
   esl_return_et ret_val = ESL_SUCCESS;

   ret_val =  ss_esl_slp_abort(
                 ESL_NULL,
                 p_pdb->p_recv_msg->p_api_msg_hdr,
                 ESL_TRUE,
                 p_pdb->p_ecode);

   if (ESL_SUCCESS == ret_val)
   {
      ESL_REFER_TRACE(ESL_TRACE_REFER_SENT_TC_END, ESL_ONE_INT_PRESENT,
      p_pdb->ctrl_blk_id, ESL_REFER_INVALID_ARG, ESL_REFER_INVALID_ARG, 
      ESL_REFER_INVALID_ARG)
   }

   return ret_val;
}


/*********************************************************************************
 **
 **   FUNCTION NAME :  ss_esl_refer_send_release_call
 **
 **   DESCRIPTION   :  This function sends a release call to SF.
 **
 **   RETURNS       :  ESL_SUCCESS, in case of success,
 **                    else, ESL_FAILURE with the corresponding ecode.
 **
 ********************************************************************************/

esl_return_et ss_esl_refer_send_release_call 
(
   INOUT esl_refer_pdb_st   *p_pdb
)
{
   if (ESL_FAILURE == ss_esl_slp_release(
                              ESL_NULL, 
                              p_pdb->p_recv_msg->p_api_msg_hdr,
                              ESL_SFA_RELEASE_CALL_ALL_CS_MASK,
                              p_pdb->release_cause,
                              p_pdb->p_ecode))
   {
      return ESL_FAILURE;
   }

   ESL_REFER_TRACE(ESL_TRACE_REFER_SENT_RELEASE_CALL, ESL_THREE_INT_PRESENT,
             p_pdb->release_cause, 
             p_pdb->p_recv_msg->p_api_msg_hdr->ctrl_blk_id, 
             p_pdb->p_recv_msg->p_api_msg_hdr->transaction_id,
             ESL_REFER_INVALID_ARG)

   return ESL_SUCCESS;
}

/*********************************************************************************
 **
 **  FUNCTION NAME : ss_esl_refer_send_confirm_service_msg_info
 **
 **  DESCRIPTION   : In this function sends a service_to SF  to SF.
 **
 **  RETURNS       : ESL_SUCCESS, and in case of any error ESL_FAILURE
 **                  with the corresponding ecode.
 **
 ********************************************************************************/

esl_return_et ss_esl_refer_send_confirm_service_msg_info
(
   INOUT esl_refer_pdb_st        *p_pdb,
   IN    esl_boolean_et          is_success
)
{
   esl_return_et                    ret_val = ESL_SUCCESS;
   esl_sfa_send_service_msg_info_st *p_service_info = ESL_NULL;
   esl_U32bit                       msg_len;
   esl_refer_ctrl_blk_st            *p_ctrl_blk = ESL_NULL;


   msg_len = sizeof(esl_sfa_send_service_msg_info_st);
   
   p_ctrl_blk = p_pdb->p_ctrl_blk;

   ESL_MEMGET(msg_len, p_service_info, p_pdb->p_ecode, ret_val)

   p_service_info->service_event_info.req_event.req_type =
   (esl_sfa_service_event_req_type_et)   ESL_SFA_SERVICE_EVENT_REQ_INFO_SIP_MSG;
   p_service_info->service_event_info.req_event.service_event_req.sip_msg_req. \
   info_type = ESL_SFA_SIP_MSG_REQ_INFO_MSG_TYPE;

   if (is_success)
   {
     p_service_info->service_event_info.req_event.service_event_req.sip_msg_req. \
     msg_type = (esl_sfa_sip_msg_type_t) ESL_SFA_SS_OP_SIP_CONFIRM;
   }
   else
   {
     p_service_info->service_event_info.req_event.service_event_req.sip_msg_req. \
     msg_type = (esl_sfa_sip_msg_type_t) ESL_SFA_SS_OP_SIP_NEGATIVE_CONFIRM;
   }

   p_service_info->service_event_info.service_data_len = ESL_SFA_INVALID_ID;
   
   ret_val = ss_esl_slp_send_service_msg_info(
                  p_service_info, 
                  p_pdb->p_recv_msg->p_api_msg_hdr,
                  ESL_SFA_INVALID_ID,
                  p_pdb->p_ctrl_blk->cl_id,
                  ESL_SFA_INVALID_ID,
                  p_pdb->p_ecode);
   if (ESL_SUCCESS == ret_val)
   {
      ESL_REFER_TRACE(ESL_TRACE_REFER_SENT_SERVICE_MSG_INFO, 
                      ESL_TWO_INT_PRESENT,
                      p_pdb->ctrl_blk_id, p_ctrl_blk->cl_id, 
                      ESL_REFER_INVALID_ARG, ESL_REFER_INVALID_ARG)
   }

   return ret_val;
}
