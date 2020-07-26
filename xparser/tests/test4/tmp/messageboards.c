/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"



/* Box filtering functions */




union pu_m_sub_1 
{
    m_m_sub_1 *ptr;
    void *ptr_anon;
};

/** \fn void add_m_sub_1_message(int int_single, float float_single, double double_single, char char_single, int int_list, float float_list, double double_list, char char_list)
 * \brief Add m_sub_1 message by calling internal and processing.
 * \param int_single Message variable.
 * \param float_single Message variable.
 * \param double_single Message variable.
 * \param char_single Message variable.
 * \param int_list Message variable.
 * \param float_list Message variable.
 * \param double_list Message variable.
 * \param char_list Message variable.
 */
void add_m_sub_1_message(int int_single, float float_single, double double_single, char char_single, int int_list[], float float_list[], double double_list[], char char_list[])
{
    int rc;
	m_m_sub_1 msg;
    
    msg.int_single = int_single;
    msg.float_single = float_single;
    msg.double_single = double_single;
    msg.char_single = char_single;
    memcpy(msg.int_list, int_list, 2*sizeof(int));
    memcpy(msg.float_list, float_list, 2*sizeof(float));
    memcpy(msg.double_list, double_list, 2*sizeof(double));
    memcpy(msg.char_list, char_list, 2*sizeof(char));
    
    
    rc = MB_AddMessage(b_m_sub_1, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'm_sub_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_1' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_m_sub_1* getInternalMessage_m_sub_1(void)
{
    static m_m_sub_1 *msg_prev = NULL;
    union pu_m_sub_1 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_m_sub_1); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'm_sub_1' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'm_sub_1' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_m_sub_1, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'm_sub_1' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_1' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_m_sub_1 * get_first_m_sub_1_message()
 * \brief Get the first m_sub_1 message in the m_sub_1 message list.
 * \return The first message in the list.
 */
m_m_sub_1 * get_first_m_sub_1_message()
{
	return getInternalMessage_m_sub_1();
}

/** \fn xmachine_message_m_sub_1 * get_next_m_sub_1_message(xmachine_message_m_sub_1 * current)
 * \brief Get the next m_sub_1 message in the m_sub_1 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_m_sub_1 * get_next_m_sub_1_message(m_m_sub_1 * current)
{
	return getInternalMessage_m_sub_1();
}


/* Box filtering functions */




union pu_m_sub_2 
{
    m_m_sub_2 *ptr;
    void *ptr_anon;
};

/** \fn void add_m_sub_2_message(int int_single)
 * \brief Add m_sub_2 message by calling internal and processing.
 * \param int_single Message variable.
 */
void add_m_sub_2_message(int int_single)
{
    int rc;
	m_m_sub_2 msg;
    
    msg.int_single = int_single;
    
    
    rc = MB_AddMessage(b_m_sub_2, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'm_sub_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_2' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_m_sub_2* getInternalMessage_m_sub_2(void)
{
    static m_m_sub_2 *msg_prev = NULL;
    union pu_m_sub_2 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_m_sub_2); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'm_sub_2' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'm_sub_2' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_m_sub_2, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'm_sub_2' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_2' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_m_sub_2 * get_first_m_sub_2_message()
 * \brief Get the first m_sub_2 message in the m_sub_2 message list.
 * \return The first message in the list.
 */
m_m_sub_2 * get_first_m_sub_2_message()
{
	return getInternalMessage_m_sub_2();
}

/** \fn xmachine_message_m_sub_2 * get_next_m_sub_2_message(xmachine_message_m_sub_2 * current)
 * \brief Get the next m_sub_2 message in the m_sub_2 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_m_sub_2 * get_next_m_sub_2_message(m_m_sub_2 * current)
{
	return getInternalMessage_m_sub_2();
}


/* Box filtering functions */




union pu_m_sub_3 
{
    m_m_sub_3 *ptr;
    void *ptr_anon;
};

/** \fn void add_m_sub_3_message(int int_single)
 * \brief Add m_sub_3 message by calling internal and processing.
 * \param int_single Message variable.
 */
void add_m_sub_3_message(int int_single)
{
    int rc;
	m_m_sub_3 msg;
    
    msg.int_single = int_single;
    
    
    rc = MB_AddMessage(b_m_sub_3, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'm_sub_3' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_3' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_3' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_m_sub_3* getInternalMessage_m_sub_3(void)
{
    static m_m_sub_3 *msg_prev = NULL;
    union pu_m_sub_3 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_m_sub_3); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'm_sub_3' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'm_sub_3' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_m_sub_3, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'm_sub_3' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_3' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_m_sub_3 * get_first_m_sub_3_message()
 * \brief Get the first m_sub_3 message in the m_sub_3 message list.
 * \return The first message in the list.
 */
m_m_sub_3 * get_first_m_sub_3_message()
{
	return getInternalMessage_m_sub_3();
}

/** \fn xmachine_message_m_sub_3 * get_next_m_sub_3_message(xmachine_message_m_sub_3 * current)
 * \brief Get the next m_sub_3 message in the m_sub_3 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_m_sub_3 * get_next_m_sub_3_message(m_m_sub_3 * current)
{
	return getInternalMessage_m_sub_3();
}


/* Box filtering functions */




union pu_m_sub_4 
{
    m_m_sub_4 *ptr;
    void *ptr_anon;
};

/** \fn void add_m_sub_4_message(int int_single)
 * \brief Add m_sub_4 message by calling internal and processing.
 * \param int_single Message variable.
 */
void add_m_sub_4_message(int int_single)
{
    int rc;
	m_m_sub_4 msg;
    
    msg.int_single = int_single;
    
    
    rc = MB_AddMessage(b_m_sub_4, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'm_sub_4' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_4' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_4' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_m_sub_4* getInternalMessage_m_sub_4(void)
{
    static m_m_sub_4 *msg_prev = NULL;
    union pu_m_sub_4 msg_pu;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_m_sub_4); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'm_sub_4' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'm_sub_4' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_m_sub_4, &(msg_pu.ptr_anon));
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'm_sub_4' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_4' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg_pu.ptr;
    
    return msg_pu.ptr;
}

/** \fn xmachine_message_m_sub_4 * get_first_m_sub_4_message()
 * \brief Get the first m_sub_4 message in the m_sub_4 message list.
 * \return The first message in the list.
 */
m_m_sub_4 * get_first_m_sub_4_message()
{
	return getInternalMessage_m_sub_4();
}

/** \fn xmachine_message_m_sub_4 * get_next_m_sub_4_message(xmachine_message_m_sub_4 * current)
 * \brief Get the next m_sub_4 message in the m_sub_4 message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_m_sub_4 * get_next_m_sub_4_message(m_m_sub_4 * current)
{
	return getInternalMessage_m_sub_4();
}

