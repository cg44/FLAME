/* $Id: testing.h 2925 2012-07-20 14:12:17Z lsc $ */
/* 
 * Copyright (c) 2008 STFC Rutherford Appleton Laboratory 
 * Author: Lee-Shawn Chin 
 * Date  : Feb 2008
 * 
 */

#ifndef TESTING_H_
#define TESTING_H_
#include "CUnit/CUnit.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int setup_suite(void);
int teardown_suite(void);

/* Test suite for Pooled List */
CU_ErrorCode testsuite_pl(void);

/* Test suite for Object Mapper */
CU_ErrorCode testsuite_om(void);

/* Test suite for Tag Table */
CU_ErrorCode testsuite_tt(void);

/* Test suite for AVL Binary search tree */
CU_ErrorCode testsuite_avl(void);

/* Test suite for k-d tree */
CU_ErrorCode testsuite_kd(void);

/* Test suite for String Map */
CU_ErrorCode testsuite_sm(void);

/* Test suite for Serial Libmboard */
CU_ErrorCode testsuite_mb_serial(void);

/* Test suite for Communication Queue */
CU_ErrorCode testsuite_commqueue(void);

/* Test suite for Communication Utilities */
CU_ErrorCode testsuite_commutils(void);

/* Test suite for Sync Request Queue */
CU_ErrorCode testsuite_syncqueue(void);

/* Test suite for communication routines (OLD) */
CU_ErrorCode testsuite_commroutines_old(void);

/* Test suite for communication routines (HANDSHAKE) */
CU_ErrorCode testsuite_commroutines_handshake(void);

/* Test suite for Parallel Libmboard */
CU_ErrorCode testsuite_mb_parallel(void);

#endif /*TESTING_H_*/
