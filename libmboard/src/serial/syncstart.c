/* $Id: syncstart.c 2108 2009-09-14 14:14:31Z lsc $ */
/*!
 * \file serial/syncstart.c
 * \code
 *      Author: Lee-Shawn Chin 
 *      Date  : Feb 2008 
 *      Copyright (c) 2008 STFC Rutherford Appleton Laboratory
 * \endcode
 * 
 * \brief Serial implementation of MB_SyncStart()
 * 
 */

#include "mb_serial.h"

/*!
 * \brief Synchronises the content of the board across all processes
 * \ingroup MB_API
 * \param[in] mb MessageBoard Handle
 * 
 * In this serial version, we do nothing anything apart from locking the 
 * message board.
 * 
 * Synchronisation of a null board (::MB_NULL_MBOARD) is valid, and will 
 * return immediately with ::MB_SUCCESS
 * 
 * Possible return codes:
 *  - ::MB_SUCCESS
 *  - ::MB_ERR_INVALID  (Invalid board)
 *  - ::MB_ERR_LOCKED (board is locked)
 */
int MB_SyncStart(MBt_Board mb) {
    
    MBIt_Board *board;
    
    /* Check for NULL message board */
    if (mb == MB_NULL_MBOARD) 
    {
        P_WARNING("Synching null board (MB_NULL_MBOARD)");
        return MB_SUCCESS;
    }
      
    /* get object mapped to mb handle */
    board = (MBIt_Board *)MBI_getMBoardRef(mb);
    if (board == NULL)
    {
        P_FUNCFAIL("Invalide board handle (%d)", (int)mb);
        return MB_ERR_INVALID;
    }

    /* Check if board is locked */
    if (board->locked == MB_TRUE)    
    {
        P_FUNCFAIL("Board (%d) is locked", (int)mb);
        return MB_ERR_LOCKED;
    }
    
    /* lock the board */
    board->locked = MB_TRUE;
    
    /* nothing much to do for serial implementation :) */

    /* return success */
    return MB_SUCCESS;
}
