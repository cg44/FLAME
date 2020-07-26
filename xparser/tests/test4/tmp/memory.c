/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"


void unittest_agent_a_1_start_middle1()
{
	
	
	//return agent_a_1();
}

void unittest_agent_a_2_middle1_middle2()
{
	int rc;
	
	rc = MB_Iterator_CreateFiltered(b_m_sub_1, &i_m_sub_1, &FLAME_filter_agent_a_agent_a_2_middle1_middle2_m_sub_1, current_xmachine_agent_a);
	
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'm_sub_1'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'm_sub_1' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_1' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return agent_a_2();
}

void unittest_agent_a_3_middle2_middle3()
{
	
	
	//return agent_a_3();
}

void unittest_agent_a_4_middle3_middle4()
{
	int rc;
	
	rc = MB_Iterator_CreateFiltered(b_m_sub_3, &i_m_sub_3, &FLAME_filter_agent_a_agent_a_4_middle3_middle4_m_sub_3, current_xmachine_agent_a);
	
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'm_sub_3'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'm_sub_3' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_3' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return agent_a_4();
}

void unittest_agent_a_5_middle4_end()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_m_sub_3, &i_m_sub_3);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'm_sub_3'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'm_sub_3' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_3' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	rc = MB_Iterator_CreateFiltered(b_m_sub_4, &i_m_sub_4, &FLAME_filter_agent_a_agent_a_5_middle4_end_m_sub_4, current_xmachine_agent_a);
	
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'm_sub_4'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'm_sub_4' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_4' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return agent_a_5();
}

void unittest_agent_b_1_start_middle()
{
	int rc;
	
	rc = MB_Iterator_CreateFiltered(b_m_sub_1, &i_m_sub_1, &FLAME_filter_agent_b_agent_b_1_start_middle_m_sub_1, current_xmachine_agent_b);
	
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'm_sub_1'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'm_sub_1' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_1' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return agent_b_1();
}

void unittest_agent_b_2_middle_end()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_m_sub_2, &i_m_sub_2);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'm_sub_2'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'm_sub_2' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_2' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return agent_b_2();
}


void free_messages()
{
	int rc;
	
	    rc = MB_Clear(b_m_sub_1);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'm_sub_1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'm_sub_1' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'm_sub_1' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_m_sub_2);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'm_sub_2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'm_sub_2' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'm_sub_2' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_m_sub_3);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'm_sub_3' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'm_sub_3' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'm_sub_3' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_m_sub_4);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'm_sub_4' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'm_sub_4' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'm_sub_4' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
}

/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
int rc;

	/* Initialise message sync composite params as NULL */
	FLAME_m_m_sub_1_composite_params = NULL;

	    rc = MB_Create(&b_m_sub_1, sizeof(m_m_sub_1));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'm_sub_1' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_m_sub_2_composite_params = NULL;

	    rc = MB_Create(&b_m_sub_2, sizeof(m_m_sub_2));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'm_sub_2' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_m_sub_3_composite_params = NULL;

	    rc = MB_Create(&b_m_sub_3, sizeof(m_m_sub_3));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'm_sub_3' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_m_sub_4_composite_params = NULL;

	    rc = MB_Create(&b_m_sub_4, sizeof(m_m_sub_4));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'm_sub_4' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	agent_a_end_state = init_agent_a_state();

	agent_a_middle4_state = init_agent_a_state();

	agent_a_middle3_state = init_agent_a_state();

	agent_a_middle2_state = init_agent_a_state();

	agent_a_middle1_state = init_agent_a_state();

	agent_a_start_state = init_agent_a_state();

	agent_b_end_state = init_agent_b_state();

	agent_b_middle_state = init_agent_b_state();

	agent_b_start_state = init_agent_b_state();

	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/** \fn void initialise_unit_testing()
 * \brief Initialises framework for unit testing.
 */
void initialise_unit_testing()
{
	int rc;

	rc = MB_Env_Init();
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Failed to initialise Message Board environment\n");
	   switch(rc) {
	       case MB_ERR_MPI:
	           fprintf(stderr, "\t reason: MPI library not initialised\n");
	           break;
	       case MB_ERR_MEMALLOC:
	           fprintf(stderr, "\t reason: out of memory\n");
	           break;
	       default:
               fprintf(stderr, "\t MB_Env_Init returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);

	}
	#endif

	initialise_pointers();
}

FLAME_output * add_FLAME_output(FLAME_output ** outputs)
{
	FLAME_output * current;

	current = (FLAME_output *)malloc(sizeof(FLAME_output));
	CHECK_POINTER(current);
	current->next = *outputs;
	*outputs = current;

	current->type = -1;
	current->format = -1;
	current->location = NULL;
	current->period = -1;
	current->phase = -1;
	current->flag = 0;

	return current;
}

void free_FLAME_outputs(FLAME_output ** outputs)
{
	FLAME_output * current, * next;

	current = *outputs;
	while(current)
	{
		next = current->next;
		free(current->location);
		free(current);
		current = next;
	}
	*outputs = NULL;
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;

	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}

	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}

	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_location = NULL;
}

void init_int_static_array(/*@out@*/ int * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0;
}

void init_float_static_array(/*@out@*/ float * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_double_static_array(/*@out@*/ double* array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_char_static_array(/*@out@*/ char * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = '\0';
}



void init_my_datatype_1(/*@out@*/ my_datatype_1 * temp)
{
	(*temp).id = 0;
	(*temp).type = 0;

}

void init_my_datatype_1_static_array(/*@out@*/ my_datatype_1 * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_my_datatype_1(&array[i]);
}

void free_my_datatype_1(my_datatype_1 * temp)
{

}

void free_my_datatype_1_static_array(my_datatype_1 * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_my_datatype_1(&array[i]);
}

void copy_my_datatype_1(my_datatype_1 * from, my_datatype_1 * to)
{
	(*to).id = (*from).id;
	(*to).type = (*from).type;
}

void copy_my_datatype_1_static_array(my_datatype_1 * from, my_datatype_1 * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_my_datatype_1(&from[i], &to[i]);
	}
}


void init_my_datatype_2(/*@out@*/ my_datatype_2 * temp)
{
	init_int_static_array((*temp).int_list, 2);
	init_my_datatype_1_static_array((*temp).var_my_datatype_1_list, 2);
	init_my_datatype_1(&(*temp).var_my_datatype_1);

}

void init_my_datatype_2_static_array(/*@out@*/ my_datatype_2 * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_my_datatype_2(&array[i]);
}

void free_my_datatype_2(my_datatype_2 * temp)
{
	free_my_datatype_1_static_array((*temp).var_my_datatype_1_list, 2);
	free_my_datatype_1(&(*temp).var_my_datatype_1);

}

void free_my_datatype_2_static_array(my_datatype_2 * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_my_datatype_2(&array[i]);
}

void copy_my_datatype_2(my_datatype_2 * from, my_datatype_2 * to)
{
	memcpy((*to).int_list, (*from).int_list, 2*sizeof(int));
	copy_my_datatype_1_static_array((*from).var_my_datatype_1_list, (*to).var_my_datatype_1_list, 2);
	copy_my_datatype_1(&(*from).var_my_datatype_1, &(*to).var_my_datatype_1);
}

void copy_my_datatype_2_static_array(my_datatype_2 * from, my_datatype_2 * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_my_datatype_2(&from[i], &to[i]);
	}
}


void init_my_datatype_3(/*@out@*/ my_datatype_3 * temp)
{
	(*temp).int_single = 0;
	(*temp).float_single = 0.0;
	(*temp).double_single = 0.0;
	(*temp).char_single = ' ';
	init_int_static_array((*temp).int_list, 2);
	init_float_static_array((*temp).float_list, 2);
	init_double_static_array((*temp).double_list, 2);
	init_char_static_array((*temp).char_list, 2);
	init_int_array(&(*temp).int_dynamic_list);
	init_float_array(&(*temp).float_dynamic_list);
	init_double_array(&(*temp).double_dynamic_list);
	init_char_array(&(*temp).char_dynamic_list);

}

void init_my_datatype_3_static_array(/*@out@*/ my_datatype_3 * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_my_datatype_3(&array[i]);
}

void free_my_datatype_3(my_datatype_3 * temp)
{
	free_int_array(&(*temp).int_dynamic_list);
	free_float_array(&(*temp).float_dynamic_list);
	free_double_array(&(*temp).double_dynamic_list);
	free_char_array(&(*temp).char_dynamic_list);

}

void free_my_datatype_3_static_array(my_datatype_3 * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_my_datatype_3(&array[i]);
}

void copy_my_datatype_3(my_datatype_3 * from, my_datatype_3 * to)
{
	(*to).int_single = (*from).int_single;
	(*to).float_single = (*from).float_single;
	(*to).double_single = (*from).double_single;
	(*to).char_single = (*from).char_single;
	memcpy((*to).int_list, (*from).int_list, 2*sizeof(int));
	memcpy((*to).float_list, (*from).float_list, 2*sizeof(float));
	memcpy((*to).double_list, (*from).double_list, 2*sizeof(double));
	memcpy((*to).char_list, (*from).char_list, 2*sizeof(char));
	copy_int_array(&(*from).int_dynamic_list, &(*to).int_dynamic_list);
	copy_float_array(&(*from).float_dynamic_list, &(*to).float_dynamic_list);
	copy_double_array(&(*from).double_dynamic_list, &(*to).double_dynamic_list);
	copy_char_array(&(*from).char_dynamic_list, &(*to).char_dynamic_list);
}

void copy_my_datatype_3_static_array(my_datatype_3 * from, my_datatype_3 * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_my_datatype_3(&from[i], &to[i]);
	}
}


void init_data_type_sales(/*@out@*/ data_type_sales * temp)
{
	(*temp).period = 0;
	(*temp).sales = 0.0;

}

void init_data_type_sales_static_array(/*@out@*/ data_type_sales * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_data_type_sales(&array[i]);
}

void free_data_type_sales(data_type_sales * temp)
{

}

void free_data_type_sales_static_array(data_type_sales * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_data_type_sales(&array[i]);
}

void copy_data_type_sales(data_type_sales * from, data_type_sales * to)
{
	(*to).period = (*from).period;
	(*to).sales = (*from).sales;
}

void copy_data_type_sales_static_array(data_type_sales * from, data_type_sales * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_data_type_sales(&from[i], &to[i]);
	}
}


void init_sales_statistics(/*@out@*/ sales_statistics * temp)
{
	(*temp).mall_id = 0;
	init_data_type_sales_array(&(*temp).sales);

}

void init_sales_statistics_static_array(/*@out@*/ sales_statistics * array, int size)
{
	int i;

	for(i = 0; i < size; i++) init_sales_statistics(&array[i]);
}

void free_sales_statistics(sales_statistics * temp)
{
	free_data_type_sales_array(&(*temp).sales);

}

void free_sales_statistics_static_array(sales_statistics * array, int size)
{
	int i;

	for(i = 0; i < size; i++) free_sales_statistics(&array[i]);
}

void copy_sales_statistics(sales_statistics * from, sales_statistics * to)
{
	(*to).mall_id = (*from).mall_id;
	copy_data_type_sales_array(&(*from).sales, &(*to).sales);
}

void copy_sales_statistics_static_array(sales_statistics * from, sales_statistics * to, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		copy_sales_statistics(&from[i], &to[i]);
	}
}



xmachine_memory_agent_a_state * init_agent_a_state()
{
	xmachine_memory_agent_a_state * current = (xmachine_memory_agent_a_state *)malloc(sizeof(xmachine_memory_agent_a_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_agent_a * init_agent_a_agent()
{
	xmachine_memory_agent_a * current = (xmachine_memory_agent_a *)malloc(sizeof(xmachine_memory_agent_a));
	CHECK_POINTER(current);

	current->int_single = 0;
	current->int_single_2 = 0;
	current->float_single = 0.0;
	current->double_single = 0.0;
	current->char_single = ' ';
	init_int_static_array(current->int_list, 2);
	init_float_static_array(current->float_list, 2);
	init_double_static_array(current->double_list, 2);
	init_char_static_array(current->char_list, 2);

	return current;
}

void free_agent_a_agent(xmachine_memory_agent_a_holder * tmp, xmachine_memory_agent_a_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_agent_a_agent()
{
	current_xmachine_agent_a = (xmachine_memory_agent_a *)malloc(sizeof(xmachine_memory_agent_a));
	CHECK_POINTER(current);

		current_xmachine_agent_a->int_single = 0;
		current_xmachine_agent_a->int_single_2 = 0;
		current_xmachine_agent_a->float_single = 0.0;
		current_xmachine_agent_a->double_single = 0.0;
		current_xmachine_agent_a->char_single = ' ';
		init_int_static_array(current_xmachine_agent_a->int_list, 2);
		init_float_static_array(current_xmachine_agent_a->float_list, 2);
		init_double_static_array(current_xmachine_agent_a->double_list, 2);
		init_char_static_array(current_xmachine_agent_a->char_list, 2);
	
}

void unittest_free_agent_a_agent()
{
	
	free(current_xmachine_agent_a);
}

void free_agent_a_agents()
{
	current_xmachine_agent_a_holder = agent_a_end_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_end_state);
		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	agent_a_end_state->count = 0;
	current_xmachine_agent_a_holder = agent_a_middle4_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle4_state);
		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	agent_a_middle4_state->count = 0;
	current_xmachine_agent_a_holder = agent_a_middle3_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle3_state);
		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	agent_a_middle3_state->count = 0;
	current_xmachine_agent_a_holder = agent_a_middle2_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle2_state);
		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	agent_a_middle2_state->count = 0;
	current_xmachine_agent_a_holder = agent_a_middle1_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle1_state);
		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	agent_a_middle1_state->count = 0;
	current_xmachine_agent_a_holder = agent_a_start_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_start_state);
		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	agent_a_start_state->count = 0;
}

void free_agent_a_states()
{
	free(agent_a_end_state);
	free(agent_a_middle4_state);
	free(agent_a_middle3_state);
	free(agent_a_middle2_state);
	free(agent_a_middle1_state);
	free(agent_a_start_state);
}

void transition_agent_a_agent(xmachine_memory_agent_a_holder * tmp, xmachine_memory_agent_a_state * from_state, xmachine_memory_agent_a_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_agent_a_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_agent_a_agent_internal(xmachine_memory_agent_a * agent, xmachine_memory_agent_a_state * state)
{
	xmachine_memory_agent_a_holder * current = (xmachine_memory_agent_a_holder *)malloc(sizeof(xmachine_memory_agent_a_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_agent_a_agent(int int_single, int int_single_2, float float_single, double double_single, char char_single, int int_list[], float float_list[], double double_list[], char char_list[])
 * \brief Add agent_a X-machine to the current being used X-machine list.
 * \param int_single Variable for the X-machine memory.
 * \param int_single_2 Variable for the X-machine memory.
 * \param float_single Variable for the X-machine memory.
 * \param double_single Variable for the X-machine memory.
 * \param char_single Variable for the X-machine memory.
 * \param int_list Variable for the X-machine memory.
 * \param float_list Variable for the X-machine memory.
 * \param double_list Variable for the X-machine memory.
 * \param char_list Variable for the X-machine memory.
 */
void add_agent_a_agent(int int_single, int int_single_2, float float_single, double double_single, char char_single, int int_list[], float float_list[], double double_list[], char char_list[])
{
	xmachine_memory_agent_a * current;

	current = init_agent_a_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_agent_a_next_state = agent_a_start_state;
	add_agent_a_agent_internal(current, current_xmachine_agent_a_next_state);

	current->int_single = int_single;
	current->int_single_2 = int_single_2;
	current->float_single = float_single;
	current->double_single = double_single;
	current->char_single = char_single;
	memcpy(current->int_list, int_list, 2*sizeof(int));
	memcpy(current->float_list, float_list, 2*sizeof(float));
	memcpy(current->double_list, double_list, 2*sizeof(double));
	memcpy(current->char_list, char_list, 2*sizeof(char));
}

xmachine_memory_agent_b_state * init_agent_b_state()
{
	xmachine_memory_agent_b_state * current = (xmachine_memory_agent_b_state *)malloc(sizeof(xmachine_memory_agent_b_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_agent_b * init_agent_b_agent()
{
	xmachine_memory_agent_b * current = (xmachine_memory_agent_b *)malloc(sizeof(xmachine_memory_agent_b));
	CHECK_POINTER(current);

	current->int_single = 0;

	return current;
}

void free_agent_b_agent(xmachine_memory_agent_b_holder * tmp, xmachine_memory_agent_b_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_agent_b_agent()
{
	current_xmachine_agent_b = (xmachine_memory_agent_b *)malloc(sizeof(xmachine_memory_agent_b));
	CHECK_POINTER(current);

		current_xmachine_agent_b->int_single = 0;
	
}

void unittest_free_agent_b_agent()
{
	
	free(current_xmachine_agent_b);
}

void free_agent_b_agents()
{
	current_xmachine_agent_b_holder = agent_b_end_state->agents;
	while(current_xmachine_agent_b_holder)
	{
		temp_xmachine_agent_b_holder = current_xmachine_agent_b_holder->next;
		free_agent_b_agent(current_xmachine_agent_b_holder, agent_b_end_state);
		current_xmachine_agent_b_holder = temp_xmachine_agent_b_holder;
	}
	agent_b_end_state->count = 0;
	current_xmachine_agent_b_holder = agent_b_middle_state->agents;
	while(current_xmachine_agent_b_holder)
	{
		temp_xmachine_agent_b_holder = current_xmachine_agent_b_holder->next;
		free_agent_b_agent(current_xmachine_agent_b_holder, agent_b_middle_state);
		current_xmachine_agent_b_holder = temp_xmachine_agent_b_holder;
	}
	agent_b_middle_state->count = 0;
	current_xmachine_agent_b_holder = agent_b_start_state->agents;
	while(current_xmachine_agent_b_holder)
	{
		temp_xmachine_agent_b_holder = current_xmachine_agent_b_holder->next;
		free_agent_b_agent(current_xmachine_agent_b_holder, agent_b_start_state);
		current_xmachine_agent_b_holder = temp_xmachine_agent_b_holder;
	}
	agent_b_start_state->count = 0;
}

void free_agent_b_states()
{
	free(agent_b_end_state);
	free(agent_b_middle_state);
	free(agent_b_start_state);
}

void transition_agent_b_agent(xmachine_memory_agent_b_holder * tmp, xmachine_memory_agent_b_state * from_state, xmachine_memory_agent_b_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_agent_b_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_agent_b_agent_internal(xmachine_memory_agent_b * agent, xmachine_memory_agent_b_state * state)
{
	xmachine_memory_agent_b_holder * current = (xmachine_memory_agent_b_holder *)malloc(sizeof(xmachine_memory_agent_b_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_agent_b_agent(int int_single)
 * \brief Add agent_b X-machine to the current being used X-machine list.
 * \param int_single Variable for the X-machine memory.
 */
void add_agent_b_agent(int int_single)
{
	xmachine_memory_agent_b * current;

	current = init_agent_b_agent();
	/* new line added to handle dynamic agent creation*/
	current_xmachine_agent_b_next_state = agent_b_start_state;
	add_agent_b_agent_internal(current, current_xmachine_agent_b_next_state);

	current->int_single = int_single;
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_agent_a_agents();
	free_agent_b_agents();
	
}


/** \fn void set_int_single(int int_single)
 * \brief Set int_single memory variable for current X-machine.
 * \param int_single New value for variable.
 */
void set_int_single(int int_single)
{
	if(current_xmachine->xmachine_agent_a) (*current_xmachine->xmachine_agent_a).int_single = int_single;
	if(current_xmachine->xmachine_agent_b) (*current_xmachine->xmachine_agent_b).int_single = int_single;
}

/** \fn int get_int_single()
 * \brief Get int_single memory variable from current X-machine.
 * \return Value for variable.
 */
int get_int_single()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).int_single;
	if(current_xmachine->xmachine_agent_b) return (*current_xmachine->xmachine_agent_b).int_single;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_int_single_2(int int_single_2)
 * \brief Set int_single_2 memory variable for current X-machine.
 * \param int_single_2 New value for variable.
 */
void set_int_single_2(int int_single_2)
{
	if(current_xmachine->xmachine_agent_a) (*current_xmachine->xmachine_agent_a).int_single_2 = int_single_2;
}

/** \fn int get_int_single_2()
 * \brief Get int_single_2 memory variable from current X-machine.
 * \return Value for variable.
 */
int get_int_single_2()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).int_single_2;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_float_single(float float_single)
 * \brief Set float_single memory variable for current X-machine.
 * \param float_single New value for variable.
 */
void set_float_single(float float_single)
{
	if(current_xmachine->xmachine_agent_a) (*current_xmachine->xmachine_agent_a).float_single = float_single;
}

/** \fn float get_float_single()
 * \brief Get float_single memory variable from current X-machine.
 * \return Value for variable.
 */
float get_float_single()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).float_single;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (float)0;
}

/** \fn void set_double_single(double double_single)
 * \brief Set double_single memory variable for current X-machine.
 * \param double_single New value for variable.
 */
void set_double_single(double double_single)
{
	if(current_xmachine->xmachine_agent_a) (*current_xmachine->xmachine_agent_a).double_single = double_single;
}

/** \fn double get_double_single()
 * \brief Get double_single memory variable from current X-machine.
 * \return Value for variable.
 */
double get_double_single()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).double_single;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_char_single(char char_single)
 * \brief Set char_single memory variable for current X-machine.
 * \param char_single New value for variable.
 */
void set_char_single(char char_single)
{
	if(current_xmachine->xmachine_agent_a) (*current_xmachine->xmachine_agent_a).char_single = char_single;
}

/** \fn char get_char_single()
 * \brief Get char_single memory variable from current X-machine.
 * \return Value for variable.
 */
char get_char_single()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).char_single;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (char)0;
}

/** \fn int get_int_list()
 * \brief Get int_list memory variable from current X-machine.
 * \return Value for variable.
 */
int * get_int_list()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).int_list;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn float get_float_list()
 * \brief Get float_list memory variable from current X-machine.
 * \return Value for variable.
 */
float * get_float_list()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).float_list;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn double get_double_list()
 * \brief Get double_list memory variable from current X-machine.
 * \return Value for variable.
 */
double * get_double_list()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).double_list;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}

/** \fn char get_char_list()
 * \brief Get char_list memory variable from current X-machine.
 * \return Value for variable.
 */
char * get_char_list()
{
	if(current_xmachine->xmachine_agent_a) return (*current_xmachine->xmachine_agent_a).char_list;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return NULL;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_agent_a) value = current_xmachine->xmachine_agent_a->;*/
    /*if (current_xmachine->xmachine_agent_b) value = current_xmachine->xmachine_agent_b->;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_agent_a) value = current_xmachine->xmachine_agent_a->;*/
    /*if (current_xmachine->xmachine_agent_b) value = current_xmachine->xmachine_agent_b->;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_agent_a) value = current_xmachine->xmachine_agent_a->0.0;*/
    /*if (current_xmachine->xmachine_agent_b) value = current_xmachine->xmachine_agent_b->0.0;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_agent_a) value = current_xmachine->xmachine_agent_a->0.0;*/
    /*if (current_xmachine->xmachine_agent_b) value = current_xmachine->xmachine_agent_b->0.0;*/

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}

/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;

	while(current)
	{
		tmp = current;
		current = current->next;
	}

	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}

	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->m_sub_1_messages = NULL;
	current->m_sub_2_messages = NULL;
	current->m_sub_3_messages = NULL;
	current->m_sub_4_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_node_info = NULL;
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
    int rc;
	FILE *file;
	char data[100];

	free(current_xmachine);
	/* Free x-machine memory */
	freexmachines();
	/* Free space partitions linked list */
	free_node_info();
	/* Free output list */
	free_FLAME_outputs(&FLAME_outputs);
	/* Free agent states */
	free_agent_a_states();
	free_agent_b_states();


	/* Free index maps */


	/* Free message boards */

	rc = MB_Delete(&b_m_sub_1);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'm_sub_1' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_1' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_1' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_m_sub_2);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'm_sub_2' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_2' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_2' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_m_sub_3);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'm_sub_3' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_3' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_3' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_m_sub_4);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'm_sub_4' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'm_sub_4' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'm_sub_4' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif


    rc = MB_Env_Finalise();
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not finalise MB environment\n");
       switch(rc) {
           case MB_ERR_ENV:
               fprintf(stderr, "\t reason: MB environment not yet started?\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Env_Finalise returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif



	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<!-- <totaltime> unit: seconds -->\n", file);
	fputs("<totaltime>", file);
	sprintf(data, "%.3f", total_time);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);


	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");

		printf(" ***");
		exit(0);
	}
}



/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
void init_int_array(int_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	(*array).size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free((*array).array);
}

void copy_int_array(int_array * from, int_array * to)
{
	int i;
	//to = init_int_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_int(to, (*from).array[i]);
	}
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
/*void sort_int_array(int_array * array)
{
	int i, j, temp;

	for(i=0; i<((*array).size-1); i++)
	{
		for(j=0; j<((*array).size-1)-i; j++)
		{
			if(*((*array).array+j+1) < *((*array).array+j))
			{
                temp = *((*array).(*array)+j);
                *((*array).array+j) = *((*array).array+j+1);
                *((*array).array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_int(int array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (int *)realloc((*array).array, ((*array).total_size * sizeof(int)));
	}
	(*array).array[(*array).size] = new_int;
	(*array).size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;

	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %d", i, (*array).array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
void init_float_array(float_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	(*array).size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free((*array).array);
}

void copy_float_array(float_array * from, float_array * to)
{
	int i;
	//to = init_float_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_float(to, (*from).array[i]);
	}
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
/*void sort_float_array(float_array array)
{
	int i, j;
	float temp;
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_float(float array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (float *)realloc((*array).array, ((*array).total_size * sizeof(float)));
	}
	(*array).array[(*array).size] = new_float;
	(*array).size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;

	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
void init_double_array(double_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	(*array).size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free((*array).array);
}

void copy_double_array(double_array * from, double_array * to)
{
	int i;
	//to = init_double_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_double(to, (*from).array[i]);
	}
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
/*void sort_double_array(double_array array)
{
	int i, j;
	double temp;

	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_double(double array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (double *)realloc((*array).array, ((*array).total_size * sizeof(double)));
	}
	(*array).array[(*array).size] = new_double;
	(*array).size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
void init_char_array(char_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
	CHECK_POINTER((*array).array);
	(*array).array[0] = '\0';
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	(*array).size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free((*array).array);
}

void copy_char_array(char_array * from, char_array * to)
{
	int i;

	for (i = 0; i < (*from).size; i++)
	{
		add_char(to, (*from).array[i]);
	}
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if((*array).size + 1 == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (char *)realloc((*array).array, ((*array).total_size * sizeof(char)));
	}
	(*array).array[(*array).size] = new_char;
	(*array).array[(*array).size + 1] = '\0';
	(*array).size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index < (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( ((*array).size + 1) * sizeof(char));
	CHECK_POINTER(new_string);
	return strcpy(new_string, (*array).array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", (*array).array);
}

/* Functions for the my_datatype_1 datatype */
/** \fn my_datatype_1_array * init_my_datatype_1_array()
 * \brief Allocate memory for a dynamic my_datatype_1 array.
 * \return my_datatype_1_array Pointer to the new dynamic my_datatype_1 array.
 */
void init_my_datatype_1_array(my_datatype_1_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (my_datatype_1 *)malloc(ARRAY_BLOCK_SIZE * sizeof(my_datatype_1));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_my_datatype_1_array(my_datatype_1_array* array)
* \brief Reset the my_datatype_1 array to hold nothing.
* \param array Pointer to the dynamic my_datatype_1 array.
*/
void reset_my_datatype_1_array(my_datatype_1_array * array)
{
	(*array).size = 0;
}

/** \fn void free_my_datatype_1_array(my_datatype_1_array * array)
* \brief Free the memory of a dynamic my_datatype_1 array.
* \param array Pointer to the dynamic my_datatype_1 array.
*/
void free_my_datatype_1_array(my_datatype_1_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_my_datatype_1(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_my_datatype_1_array(my_datatype_1_array * from, my_datatype_1_array * to)
{
	int i;

	//to = init_my_datatype_1_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_my_datatype_1(to, (*from).array[i].id, (*from).array[i].type);
	}
}

/** \fn void add_my_datatype_1(my_datatype_1_array * array, int id, int type)
* \brief Add an my_datatype_1 to the dynamic my_datatype_1 array.
* \param array Pointer to the dynamic my_datatype_1 array.
* \param new_int The my_datatype_1 to add
*/
void add_my_datatype_1(my_datatype_1_array * array,  int id,  int type)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (my_datatype_1 *)realloc((*array).array, ((*array).total_size * sizeof(my_datatype_1)));
	}
	init_my_datatype_1(&(*array).array[(*array).size]);
	(*array).array[(*array).size].id = id;
	(*array).array[(*array).size].type = type;

	(*array).size++;
}

/** \fn void remove_my_datatype_1(my_datatype_1_array * array, int index)
 * \brief Remove an my_datatype_1 from a dynamic my_datatype_1 array.
 * \param array Pointer to the dynamic my_datatype_1 array.
 * \param index The index of the my_datatype_1 to remove.
 */
void remove_my_datatype_1(my_datatype_1_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_my_datatype_1(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_my_datatype_1(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the my_datatype_2 datatype */
/** \fn my_datatype_2_array * init_my_datatype_2_array()
 * \brief Allocate memory for a dynamic my_datatype_2 array.
 * \return my_datatype_2_array Pointer to the new dynamic my_datatype_2 array.
 */
void init_my_datatype_2_array(my_datatype_2_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (my_datatype_2 *)malloc(ARRAY_BLOCK_SIZE * sizeof(my_datatype_2));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_my_datatype_2_array(my_datatype_2_array* array)
* \brief Reset the my_datatype_2 array to hold nothing.
* \param array Pointer to the dynamic my_datatype_2 array.
*/
void reset_my_datatype_2_array(my_datatype_2_array * array)
{
	(*array).size = 0;
}

/** \fn void free_my_datatype_2_array(my_datatype_2_array * array)
* \brief Free the memory of a dynamic my_datatype_2 array.
* \param array Pointer to the dynamic my_datatype_2 array.
*/
void free_my_datatype_2_array(my_datatype_2_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_my_datatype_2(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_my_datatype_2_array(my_datatype_2_array * from, my_datatype_2_array * to)
{
	int i;

	//to = init_my_datatype_2_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_my_datatype_2(to, (*from).array[i].int_list, (*from).array[i].var_my_datatype_1_list, &(*from).array[i].var_my_datatype_1);
	}
}

/** \fn void add_my_datatype_2(my_datatype_2_array * array, int int_list, my_datatype_1 * var_my_datatype_1_list, my_datatype_1 * var_my_datatype_1)
* \brief Add an my_datatype_2 to the dynamic my_datatype_2 array.
* \param array Pointer to the dynamic my_datatype_2 array.
* \param new_int The my_datatype_2 to add
*/
void add_my_datatype_2(my_datatype_2_array * array, /*@out@*/ int * int_list, /*@out@*/ my_datatype_1 * var_my_datatype_1_list, /*@out@*/ my_datatype_1 * var_my_datatype_1)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (my_datatype_2 *)realloc((*array).array, ((*array).total_size * sizeof(my_datatype_2)));
	}
	init_my_datatype_2(&(*array).array[(*array).size]);
	if(int_list != NULL) memcpy((*array).array[(*array).size].int_list, int_list, 2*sizeof(int));
	if(var_my_datatype_1_list != NULL) copy_my_datatype_1_static_array(var_my_datatype_1_list, (*array).array[(*array).size].var_my_datatype_1_list, 2);
	copy_my_datatype_1(var_my_datatype_1, &(*array).array[(*array).size].var_my_datatype_1);

	(*array).size++;
}

/** \fn void remove_my_datatype_2(my_datatype_2_array * array, int index)
 * \brief Remove an my_datatype_2 from a dynamic my_datatype_2 array.
 * \param array Pointer to the dynamic my_datatype_2 array.
 * \param index The index of the my_datatype_2 to remove.
 */
void remove_my_datatype_2(my_datatype_2_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_my_datatype_2(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_my_datatype_2(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the my_datatype_3 datatype */
/** \fn my_datatype_3_array * init_my_datatype_3_array()
 * \brief Allocate memory for a dynamic my_datatype_3 array.
 * \return my_datatype_3_array Pointer to the new dynamic my_datatype_3 array.
 */
void init_my_datatype_3_array(my_datatype_3_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (my_datatype_3 *)malloc(ARRAY_BLOCK_SIZE * sizeof(my_datatype_3));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_my_datatype_3_array(my_datatype_3_array* array)
* \brief Reset the my_datatype_3 array to hold nothing.
* \param array Pointer to the dynamic my_datatype_3 array.
*/
void reset_my_datatype_3_array(my_datatype_3_array * array)
{
	(*array).size = 0;
}

/** \fn void free_my_datatype_3_array(my_datatype_3_array * array)
* \brief Free the memory of a dynamic my_datatype_3 array.
* \param array Pointer to the dynamic my_datatype_3 array.
*/
void free_my_datatype_3_array(my_datatype_3_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_my_datatype_3(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_my_datatype_3_array(my_datatype_3_array * from, my_datatype_3_array * to)
{
	int i;

	//to = init_my_datatype_3_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_my_datatype_3(to, (*from).array[i].int_single, (*from).array[i].float_single, (*from).array[i].double_single, (*from).array[i].char_single, (*from).array[i].int_list, (*from).array[i].float_list, (*from).array[i].double_list, (*from).array[i].char_list, &(*from).array[i].int_dynamic_list, &(*from).array[i].float_dynamic_list, &(*from).array[i].double_dynamic_list, &(*from).array[i].char_dynamic_list);
	}
}

/** \fn void add_my_datatype_3(my_datatype_3_array * array, int int_single, float float_single, double double_single, char char_single, int int_list, float float_list, double double_list, char char_list, int_array int_dynamic_list, float_array float_dynamic_list, double_array double_dynamic_list, char_array char_dynamic_list)
* \brief Add an my_datatype_3 to the dynamic my_datatype_3 array.
* \param array Pointer to the dynamic my_datatype_3 array.
* \param new_int The my_datatype_3 to add
*/
void add_my_datatype_3(my_datatype_3_array * array,  int int_single,  float float_single,  double double_single,  char char_single, /*@out@*/ int * int_list, /*@out@*/ float * float_list, /*@out@*/ double * double_list, /*@out@*/ char * char_list, /*@out@*/ int_array * int_dynamic_list, /*@out@*/ float_array * float_dynamic_list, /*@out@*/ double_array * double_dynamic_list, /*@out@*/ char_array * char_dynamic_list)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (my_datatype_3 *)realloc((*array).array, ((*array).total_size * sizeof(my_datatype_3)));
	}
	init_my_datatype_3(&(*array).array[(*array).size]);
	(*array).array[(*array).size].int_single = int_single;
	(*array).array[(*array).size].float_single = float_single;
	(*array).array[(*array).size].double_single = double_single;
	(*array).array[(*array).size].char_single = char_single;
	if(int_list != NULL) memcpy((*array).array[(*array).size].int_list, int_list, 2*sizeof(int));
	if(float_list != NULL) memcpy((*array).array[(*array).size].float_list, float_list, 2*sizeof(float));
	if(double_list != NULL) memcpy((*array).array[(*array).size].double_list, double_list, 2*sizeof(double));
	if(char_list != NULL) memcpy((*array).array[(*array).size].char_list, char_list, 2*sizeof(char));
	if(int_dynamic_list != NULL) copy_int_array(int_dynamic_list, &(*array).array[(*array).size].int_dynamic_list);
	if(float_dynamic_list != NULL) copy_float_array(float_dynamic_list, &(*array).array[(*array).size].float_dynamic_list);
	if(double_dynamic_list != NULL) copy_double_array(double_dynamic_list, &(*array).array[(*array).size].double_dynamic_list);
	if(char_dynamic_list != NULL) copy_char_array(char_dynamic_list, &(*array).array[(*array).size].char_dynamic_list);

	(*array).size++;
}

/** \fn void remove_my_datatype_3(my_datatype_3_array * array, int index)
 * \brief Remove an my_datatype_3 from a dynamic my_datatype_3 array.
 * \param array Pointer to the dynamic my_datatype_3 array.
 * \param index The index of the my_datatype_3 to remove.
 */
void remove_my_datatype_3(my_datatype_3_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_my_datatype_3(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_my_datatype_3(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the data_type_sales datatype */
/** \fn data_type_sales_array * init_data_type_sales_array()
 * \brief Allocate memory for a dynamic data_type_sales array.
 * \return data_type_sales_array Pointer to the new dynamic data_type_sales array.
 */
void init_data_type_sales_array(data_type_sales_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (data_type_sales *)malloc(ARRAY_BLOCK_SIZE * sizeof(data_type_sales));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_data_type_sales_array(data_type_sales_array* array)
* \brief Reset the data_type_sales array to hold nothing.
* \param array Pointer to the dynamic data_type_sales array.
*/
void reset_data_type_sales_array(data_type_sales_array * array)
{
	(*array).size = 0;
}

/** \fn void free_data_type_sales_array(data_type_sales_array * array)
* \brief Free the memory of a dynamic data_type_sales array.
* \param array Pointer to the dynamic data_type_sales array.
*/
void free_data_type_sales_array(data_type_sales_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_data_type_sales(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_data_type_sales_array(data_type_sales_array * from, data_type_sales_array * to)
{
	int i;

	//to = init_data_type_sales_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_data_type_sales(to, (*from).array[i].period, (*from).array[i].sales);
	}
}

/** \fn void add_data_type_sales(data_type_sales_array * array, int period, double sales)
* \brief Add an data_type_sales to the dynamic data_type_sales array.
* \param array Pointer to the dynamic data_type_sales array.
* \param new_int The data_type_sales to add
*/
void add_data_type_sales(data_type_sales_array * array,  int period,  double sales)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (data_type_sales *)realloc((*array).array, ((*array).total_size * sizeof(data_type_sales)));
	}
	init_data_type_sales(&(*array).array[(*array).size]);
	(*array).array[(*array).size].period = period;
	(*array).array[(*array).size].sales = sales;

	(*array).size++;
}

/** \fn void remove_data_type_sales(data_type_sales_array * array, int index)
 * \brief Remove an data_type_sales from a dynamic data_type_sales array.
 * \param array Pointer to the dynamic data_type_sales array.
 * \param index The index of the data_type_sales to remove.
 */
void remove_data_type_sales(data_type_sales_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_data_type_sales(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_data_type_sales(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}
/* Functions for the sales_statistics datatype */
/** \fn sales_statistics_array * init_sales_statistics_array()
 * \brief Allocate memory for a dynamic sales_statistics array.
 * \return sales_statistics_array Pointer to the new dynamic sales_statistics array.
 */
void init_sales_statistics_array(sales_statistics_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (sales_statistics *)malloc(ARRAY_BLOCK_SIZE * sizeof(sales_statistics));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_sales_statistics_array(sales_statistics_array* array)
* \brief Reset the sales_statistics array to hold nothing.
* \param array Pointer to the dynamic sales_statistics array.
*/
void reset_sales_statistics_array(sales_statistics_array * array)
{
	(*array).size = 0;
}

/** \fn void free_sales_statistics_array(sales_statistics_array * array)
* \brief Free the memory of a dynamic sales_statistics array.
* \param array Pointer to the dynamic sales_statistics array.
*/
void free_sales_statistics_array(sales_statistics_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_sales_statistics(&(*array).array[i]);
	}
	
	free((*array).array);
}

void copy_sales_statistics_array(sales_statistics_array * from, sales_statistics_array * to)
{
	int i;

	//to = init_sales_statistics_array();

	for(i = 0; i < (*from).size; i++)
	{
		add_sales_statistics(to, (*from).array[i].mall_id, &(*from).array[i].sales);
	}
}

/** \fn void add_sales_statistics(sales_statistics_array * array, int mall_id, data_type_sales_array * sales)
* \brief Add an sales_statistics to the dynamic sales_statistics array.
* \param array Pointer to the dynamic sales_statistics array.
* \param new_int The sales_statistics to add
*/
void add_sales_statistics(sales_statistics_array * array,  int mall_id, /*@out@*/ data_type_sales_array * sales)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (int)((*array).total_size * ARRAY_GROWTH_RATE);
		(*array).array = (sales_statistics *)realloc((*array).array, ((*array).total_size * sizeof(sales_statistics)));
	}
	init_sales_statistics(&(*array).array[(*array).size]);
	(*array).array[(*array).size].mall_id = mall_id;
	if(sales != NULL) copy_data_type_sales_array(sales, &(*array).array[(*array).size].sales);

	(*array).size++;
}

/** \fn void remove_sales_statistics(sales_statistics_array * array, int index)
 * \brief Remove an sales_statistics from a dynamic sales_statistics array.
 * \param array Pointer to the dynamic sales_statistics array.
 * \param index The index of the sales_statistics to remove.
 */
void remove_sales_statistics(sales_statistics_array * array, int index)
{
	int i;

	/* Free element at index index */
	free_sales_statistics(&(*array).array[index]);

	/* Copy all elements up by one */
	if(index < (*array).size)
	{
		for(i = index; i < (*array).size - 1; i++)
		{
			copy_sales_statistics(&(*array).array[i+1], &(*array).array[i]);
		}
		(*array).size--;
	}
}

/** \fn int idle()
 * \brief an idle function for use by agents.
 */
int idle()
{
	return 0;
}

int FLAME_get_environment_variable_env_int()
{
	return FLAME_environment_variable_env_int;
}
float FLAME_get_environment_variable_env_float()
{
	return FLAME_environment_variable_env_float;
}
double FLAME_get_environment_variable_env_double()
{
	return FLAME_environment_variable_env_double;
}
char FLAME_get_environment_variable_env_char()
{
	return FLAME_environment_variable_env_char;
}


