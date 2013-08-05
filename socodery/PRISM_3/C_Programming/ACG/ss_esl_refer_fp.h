/*********************************************************************************
 **    
 **	FILENAME	:   ss_esl_refer_fp.h
 **
 ** 	DESCRIPTION	:   This file contains the function prototypes for the
 ** 			    functions defined in the Refer SLP.
 ** 					
 ** 	Revision History	:
 **     DATE  	      NAME	  	   REFERENCE		REASON
 ** ---------------------------------------------------------------------------
 **   Sept 2002   Mayank Rastogi                               Created
 **
 ** 	 © 2006  Inc  All Rights Reserved
 **
 ********************************************************************************/

#ifndef __SS_ESL_REFER_FP_H
#define __SS_ESL_REFER_FP_H

/* global hearders */
#include "ss_esl_types.h"
#include "ss_esl_sfa_api.h"
#include "ss_esl_interface.h"

/* Refer headers */
#include "ss_esl_refer_types.h"

/******************** FUNCTION DECLARATIONS ******************************/

/******************** Function Prototypes of ss_esl_refer_ext.c ************/

extern esl_return_et ss_esl_refer_arm
(
   INOUT esl_refer_pdb_st           *p_pdb,
   IN    esl_sfa_call_event_et      event_type,
   IN    esl_sfa_notification_et    mode,
   IN    esl_U32bit                 sca_leg_id
);

extern esl_return_et ss_esl_refer_send_split_leg
(
   INOUT esl_refer_pdb_st *p_pdb
);

extern esl_return_et ss_esl_refer_send_disconnect_leg
(
   INOUT esl_refer_pdb_st        *p_pdb,
   IN    esl_sfa_sca_leg_id_t    sca_leg_id
);

extern esl_return_et ss_esl_refer_send_connect
(
   INOUT esl_refer_pdb_st        *p_pdb
);

extern esl_return_et ss_esl_refer_send_continue
(
   INOUT esl_refer_pdb_st        *p_pdb,
   IN    esl_sfa_sca_leg_id_t    sca_leg_id
);

extern esl_return_et ss_esl_refer_send_tc_end
(
   INOUT esl_refer_pdb_st   *p_pdb
);

extern esl_return_et ss_esl_refer_send_release_call
(
   INOUT esl_refer_pdb_st   *p_pdb
);

extern esl_return_et ss_esl_refer_send_confirm_service_msg_info
(
   INOUT esl_refer_pdb_st        *p_pdb,
   IN    esl_boolean_et          is_success
);


/******************** Function Prototypes of ss_esl_refer_utils.c ************/

extern esl_return_et ss_esl_refer_release_service
(
   INOUT esl_refer_pdb_st   *p_pdb,
   IN    esl_sfa_cause_et   cause
);

extern esl_return_et ss_esl_refer_end_service
(
   INOUT esl_refer_pdb_st *p_pdb
);

extern esl_return_et ss_esl_refer_update_ctrl_blk
(
   INOUT   esl_refer_pdb_st    *p_pdb
);

extern esl_return_et ss_esl_refer_check_n_add_or_del_sub
(
   INOUT esl_refer_pdb_st       *p_pdb,
   IN    esl_boolean_et         operation,
   IN    esl_sub_t              subscriber
   /* The hash define for above is defined in ss_esl_refer_types.h
    * as ESL_SUB_A onwards */
);

/******************** Function Prototypes of ss_esl_refer_fsm.c ************/

extern esl_return_et ss_esl_refer_trigger_fsm
(
   INOUT   esl_refer_pdb_st         *p_pdb
);

/******************** Function Prototypes of ss_esl_refer_db.c ************/

extern esl_return_et ss_esl_refer_init_ctrl_blk_pool
(
      OUT esl_response_et      *p_ecode
);

extern esl_return_et ss_esl_refer_allocate_ctrl_blk
(
      OUT esl_ctrl_blk_id_t      *p_new_ctrl_blk_id,
      OUT esl_response_et        *p_ecode
);

extern esl_return_et ss_esl_refer_deallocate_ctrl_blk
(
      IN  esl_ctrl_blk_id_t       ctrl_blk_id_to_free,
      OUT esl_response_et         *p_ecode
);

esl_refer_ctrl_blk_st * ss_esl_refer_get_ctrl_blk_ptr
(
      IN esl_ctrl_blk_id_t      ctrl_blk_id
);

/******************** Function Prototypes of ss_esl_refer_db.c ************/
 
extern esl_return_et ss_esl_refer_init
(
       OUT   esl_response_et   *p_ecode
);

/******************** Function Prototypes of ss_esl_refer_db.c ************/
 
extern esl_return_et ss_esl_refer_process_trigger_data
(
        IN     esl_service_message_st       *p_message,
        OUT    esl_status_et                *p_status,
        OUT    esl_response_et              *p_ecode
);

#endif /* End of ifndef __SS_ESL_REFER_FP_H */
