/**
 * \file  main.c
 * \brief Holds main function of the program.
 */
#include "header.h"



#define COMPACT_PRINTOUT_P_THRESHOLD 8

/** \fn int main(int argc, char * argv[])
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char * argv[])
{
	/* Timing variables */
	double start, stop, interval;
	FILE *file;
	char data[100];
	char logfilepath[1000];
	char inputpath[1000];
	char * c;
	int lastd = 0;
	int i;
	int rc;
	int iteration_number = 0;
	int iteration_total;
	int * p_iteration_number = &iteration_number;
	//xmachine_memory_agent_a * temp_xmachine_agent_a;
	//xmachine_memory_agent_b * temp_xmachine_agent_b;

	int FLAME_m_sub_1_message_board_write;
	int FLAME_m_sub_1_message_board_read;
	int FLAME_m_sub_2_message_board_write;
	int FLAME_m_sub_2_message_board_read;
	int FLAME_m_sub_3_message_board_write;
	int FLAME_m_sub_3_message_board_read;
	int FLAME_m_sub_4_message_board_write;
	int FLAME_m_sub_4_message_board_read;

	/* Particle cloud data */
	double cloud_data[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
	/* Count to debug function branches */
	int FLAME_debug_count;


/* For partition method. Makes geometric (-g flag) the default but may be overridden with -r for round-robin */
	int partition_method=1;



	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Set random seed */
/*	srand(time(NULL)); */

	

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
    
	/* For backwards compatabilty allocate current_xmachine */
	current_xmachine = (xmachine *)malloc(sizeof(xmachine));
	if(current_xmachine == NULL) {printf("**** ERROR in Memory check current_xmachine\n");exit(EXIT_FAILURE);}
	/*CHECK_POINTER(current_xmachine);*/

	/* Initialise pointers */
	initialise_pointers();


	printf("FLAME Application: test_model_4 \n");


	printf("Debug mode enabled \n");
FLAME_debug_count = 0;
/* Use to stop compiler warnings if not used */
if(FLAME_debug_count == 0) {}




if(argc < 2)
	{

		printf("Usage: %s <number of iterations> [<states_directory>]/<init_state> <partitions> [-f # | -f #+#]\n",argv[0]);
		printf("\t-f\tOutput frequency, 1st # is frequency, 2nd # is the offset if required\n");



		exit(0);
	}
	iteration_total = atoi(argv[1]);
printf("Iterations: %i\n", iteration_total);

	/* Read initial states of x-machines */
	if(argc < 3)
	{
		printf("Need two parameters\n");
		exit(0);
	}
	strcpy(inputpath, argv[2]);
/*printf("Initial states: %s\n", inputpath);*/

	i = 0;
	lastd = -1;
	while(inputpath[i] != '\0')
	{
		/* For windows directories */
		if(inputpath[i] == '\\') lastd=i;
		/* For unix directories */
		if(inputpath[i] == '/') lastd=i;
		i++;
	}
	strcpy(outputpath, inputpath);
	outputpath[lastd+1] = '\0';

/*printf("Ouput dir: %s\n", outputpath);*/


	/* Read number of space partitions (1 by default) */
	totalnodes = 1;
	if(argc > 3)
	{
		totalnodes = atoi(argv[3]);
	}


	i = 3;
	while(argc > i)
	{
		if(strcmp(argv[i],"-f") == 0)
		{
			if(argc > (i+1))
			{
				output_offset = 0;
				/* Find offset, separated by the char '+' */
				c = strchr(argv[(i+1)], '+');
				if(c == NULL)
				{
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d\n", output_frequency);
				}
				else
				{
					output_offset = atoi(argv[(i+1)]+(c-argv[(i+1)])+1);
					argv[(i+1)][c-argv[(i+1)]] = '\0';
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d with offset %d\n", output_frequency, output_offset);
				}

				if(output_frequency == 0)
				{
					printf("Output frequency cannot be zero\n");
					exit(0);
				}

				i++;
			}
			else
			{
				printf("Output frequency number not defined\n");
				exit(0);
			}
		}
		/* Partitioning method: -g = geometric, -r = round-robin */
		if(strcmp(argv[i],"-g") == 0) partition_method = 1;
		if(strcmp(argv[i],"-r") == 0) partition_method = 2;
		i++;
	}


	    /* Read initial data into p_xmachine  */

       //agent_list = p_xmachine;
       readinitialstates(inputpath, outputpath, p_iteration_number, cloud_data, partition_method, 0);
       /* Generate partitions */
       generate_partitions(cloud_data,totalnodes,partition_method);
       save_partition_data();





    /* Partition data */
    /* stc: no partitions in serial */
	//partition_data(totalnodes, agent_list, cloud_data, partition_method);




/* Use MB_IndexMap routines from libmboard v0.2 */
/* For each agent constant (that is used in a filter(?))
 * declare an index map handle */



		/*i = 0;
		current_node = *p_node_info;
		while(current_node)
		{
			printf("No of agents on partition %d: %d\n", current_node->node_id, current_node->agent_total);
			i += current_node->agent_total;
			current_node = current_node->next;
		}
		printf("Agent total check: %d\n", i);*/

        /* restore current_node pointer */
		//current_node = *p_node_info;



	/* Start log file (now so that xvisualiser can read straight away) */

	/* Write log file */
	sprintf(logfilepath, "%slog.xml", outputpath);
	if((file = fopen(logfilepath, "w"))==NULL)
	{
		printf("Error: cannot open file '%s' for writing\n", logfilepath);
		exit(0);
	}
	(void)fputs("<model_run>\n", file);
	(void)fputs("<codetype>", file);
	(void)fputs("serial", file);

	(void)fputs("</codetype>\n", file);
	(void)fputs("<nodes>", file);
	sprintf(data, "%i", totalnodes);
	(void)fputs(data, file);
	(void)fputs("</nodes>\n", file);

	/* print timer into */
	(void)fputs("<!-- <time> unit: milliseconds -->\n", file);

	sprintf(data, "unspecified");
	
	(void)fputs("<!-- <time> timer resolution: ", file);
	(void)fputs(data, file);
	(void)fputs(")-->\n", file);

	start = get_time();
	stop = get_time();
	sprintf(data, "%.2e ms", (stop - start) * 1000.0);
	(void)fputs("<!-- <time> timer overhead: ~", file);
	(void)fputs(data, file);
	(void)fputs(")-->\n", file);


	(void)fclose(file);


	/* For each message check if their exists agents that input/output the message */
	FLAME_m_sub_1_message_board_write = 0;
	FLAME_m_sub_1_message_board_read = 0;
	/* Sending agents */
	if(agent_a_start_state->agents != NULL) FLAME_m_sub_1_message_board_write = 1;
	
	/* Reading agents */
	if(agent_a_start_state->agents != NULL) FLAME_m_sub_1_message_board_read = 1;
	if(agent_b_start_state->agents != NULL) FLAME_m_sub_1_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_m_sub_1_message_board_write == 0 &&
		FLAME_m_sub_1_message_board_read == 0)
			rc = MB_SetAccessMode(b_m_sub_1, MB_MODE_IDLE);
	if(FLAME_m_sub_1_message_board_write == 1 &&
		FLAME_m_sub_1_message_board_read == 0)
			rc = MB_SetAccessMode(b_m_sub_1, MB_MODE_WRITEONLY);
	if(FLAME_m_sub_1_message_board_write == 0 &&
		FLAME_m_sub_1_message_board_read == 1)
			rc = MB_SetAccessMode(b_m_sub_1, MB_MODE_READONLY);
	if(FLAME_m_sub_1_message_board_write == 1 &&
		FLAME_m_sub_1_message_board_read == 1)
			rc = MB_SetAccessMode(b_m_sub_1, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'm_sub_1' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_m_sub_2_message_board_write = 0;
	FLAME_m_sub_2_message_board_read = 0;
	/* Sending agents */
	if(agent_a_start_state->agents != NULL) FLAME_m_sub_2_message_board_write = 1;
	
	/* Reading agents */
	if(agent_b_start_state->agents != NULL) FLAME_m_sub_2_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_m_sub_2_message_board_write == 0 &&
		FLAME_m_sub_2_message_board_read == 0)
			rc = MB_SetAccessMode(b_m_sub_2, MB_MODE_IDLE);
	if(FLAME_m_sub_2_message_board_write == 1 &&
		FLAME_m_sub_2_message_board_read == 0)
			rc = MB_SetAccessMode(b_m_sub_2, MB_MODE_WRITEONLY);
	if(FLAME_m_sub_2_message_board_write == 0 &&
		FLAME_m_sub_2_message_board_read == 1)
			rc = MB_SetAccessMode(b_m_sub_2, MB_MODE_READONLY);
	if(FLAME_m_sub_2_message_board_write == 1 &&
		FLAME_m_sub_2_message_board_read == 1)
			rc = MB_SetAccessMode(b_m_sub_2, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'm_sub_2' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_m_sub_3_message_board_write = 0;
	FLAME_m_sub_3_message_board_read = 0;
	/* Sending agents */
	if(agent_a_start_state->agents != NULL) FLAME_m_sub_3_message_board_write = 1;
	
	/* Reading agents */
	if(agent_a_start_state->agents != NULL) FLAME_m_sub_3_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_m_sub_3_message_board_write == 0 &&
		FLAME_m_sub_3_message_board_read == 0)
			rc = MB_SetAccessMode(b_m_sub_3, MB_MODE_IDLE);
	if(FLAME_m_sub_3_message_board_write == 1 &&
		FLAME_m_sub_3_message_board_read == 0)
			rc = MB_SetAccessMode(b_m_sub_3, MB_MODE_WRITEONLY);
	if(FLAME_m_sub_3_message_board_write == 0 &&
		FLAME_m_sub_3_message_board_read == 1)
			rc = MB_SetAccessMode(b_m_sub_3, MB_MODE_READONLY);
	if(FLAME_m_sub_3_message_board_write == 1 &&
		FLAME_m_sub_3_message_board_read == 1)
			rc = MB_SetAccessMode(b_m_sub_3, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'm_sub_3' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	FLAME_m_sub_4_message_board_write = 0;
	FLAME_m_sub_4_message_board_read = 0;
	/* Sending agents */
	if(agent_a_start_state->agents != NULL) FLAME_m_sub_4_message_board_write = 1;
	
	/* Reading agents */
	if(agent_a_start_state->agents != NULL) FLAME_m_sub_4_message_board_read = 1;
	
	/* Call message board library with details */
	if(FLAME_m_sub_4_message_board_write == 0 &&
		FLAME_m_sub_4_message_board_read == 0)
			rc = MB_SetAccessMode(b_m_sub_4, MB_MODE_IDLE);
	if(FLAME_m_sub_4_message_board_write == 1 &&
		FLAME_m_sub_4_message_board_read == 0)
			rc = MB_SetAccessMode(b_m_sub_4, MB_MODE_WRITEONLY);
	if(FLAME_m_sub_4_message_board_write == 0 &&
		FLAME_m_sub_4_message_board_read == 1)
			rc = MB_SetAccessMode(b_m_sub_4, MB_MODE_READONLY);
	if(FLAME_m_sub_4_message_board_write == 1 &&
		FLAME_m_sub_4_message_board_read == 1)
			rc = MB_SetAccessMode(b_m_sub_4, MB_MODE_READWRITE);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not set access mode of 'm_sub_4' board\n");
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
		   default:
			   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }
		   
		   exit(rc);
	}
	#endif
	

#ifdef START_END	
/* Call initialisation function */
	start_simulation();
#endif

/* Start timing */
	start = get_time();

	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{
#ifdef START_END
/* Start iteration function */
	start_iteration();
#endif
		interval = get_time();

		/* Print out iteration number */
		
		fprintf(stdout, "Iteration - %d\n", iteration_loop);
		(void)fflush(stdout);
        
		/* START OF ITERATION */
		
		/* For each message check if their exists agents that input/output the message */
        FLAME_m_sub_1_message_board_write = 0;
        FLAME_m_sub_1_message_board_read = 0;
        /* Sending agents */
        if(agent_a_start_state->agents != NULL) FLAME_m_sub_1_message_board_write = 1;
        
        /* Reading agents */
        if(agent_a_start_state->agents != NULL) FLAME_m_sub_1_message_board_read = 1;
        if(agent_b_start_state->agents != NULL) FLAME_m_sub_1_message_board_read = 1;
        
        /* Call message board library with details */
        if(FLAME_m_sub_1_message_board_write == 0 &&
            FLAME_m_sub_1_message_board_read == 0)
                rc = MB_SetAccessMode(b_m_sub_1, MB_MODE_IDLE);
        if(FLAME_m_sub_1_message_board_write == 1 &&
            FLAME_m_sub_1_message_board_read == 0)
                rc = MB_SetAccessMode(b_m_sub_1, MB_MODE_WRITEONLY);
        if(FLAME_m_sub_1_message_board_write == 0 &&
            FLAME_m_sub_1_message_board_read == 1)
                rc = MB_SetAccessMode(b_m_sub_1, MB_MODE_READONLY);
        if(FLAME_m_sub_1_message_board_write == 1 &&
            FLAME_m_sub_1_message_board_read == 1)
                rc = MB_SetAccessMode(b_m_sub_1, MB_MODE_READWRITE);
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
           fprintf(stderr, "ERROR: Could not set access mode of 'm_sub_1' board\n");
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
               default:
                   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
           }
               
               exit(rc);
        }
        #endif
        FLAME_m_sub_2_message_board_write = 0;
        FLAME_m_sub_2_message_board_read = 0;
        /* Sending agents */
        if(agent_a_start_state->agents != NULL) FLAME_m_sub_2_message_board_write = 1;
        
        /* Reading agents */
        if(agent_b_start_state->agents != NULL) FLAME_m_sub_2_message_board_read = 1;
        
        /* Call message board library with details */
        if(FLAME_m_sub_2_message_board_write == 0 &&
            FLAME_m_sub_2_message_board_read == 0)
                rc = MB_SetAccessMode(b_m_sub_2, MB_MODE_IDLE);
        if(FLAME_m_sub_2_message_board_write == 1 &&
            FLAME_m_sub_2_message_board_read == 0)
                rc = MB_SetAccessMode(b_m_sub_2, MB_MODE_WRITEONLY);
        if(FLAME_m_sub_2_message_board_write == 0 &&
            FLAME_m_sub_2_message_board_read == 1)
                rc = MB_SetAccessMode(b_m_sub_2, MB_MODE_READONLY);
        if(FLAME_m_sub_2_message_board_write == 1 &&
            FLAME_m_sub_2_message_board_read == 1)
                rc = MB_SetAccessMode(b_m_sub_2, MB_MODE_READWRITE);
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
           fprintf(stderr, "ERROR: Could not set access mode of 'm_sub_2' board\n");
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
               default:
                   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
           }
               
               exit(rc);
        }
        #endif
        FLAME_m_sub_3_message_board_write = 0;
        FLAME_m_sub_3_message_board_read = 0;
        /* Sending agents */
        if(agent_a_start_state->agents != NULL) FLAME_m_sub_3_message_board_write = 1;
        
        /* Reading agents */
        if(agent_a_start_state->agents != NULL) FLAME_m_sub_3_message_board_read = 1;
        
        /* Call message board library with details */
        if(FLAME_m_sub_3_message_board_write == 0 &&
            FLAME_m_sub_3_message_board_read == 0)
                rc = MB_SetAccessMode(b_m_sub_3, MB_MODE_IDLE);
        if(FLAME_m_sub_3_message_board_write == 1 &&
            FLAME_m_sub_3_message_board_read == 0)
                rc = MB_SetAccessMode(b_m_sub_3, MB_MODE_WRITEONLY);
        if(FLAME_m_sub_3_message_board_write == 0 &&
            FLAME_m_sub_3_message_board_read == 1)
                rc = MB_SetAccessMode(b_m_sub_3, MB_MODE_READONLY);
        if(FLAME_m_sub_3_message_board_write == 1 &&
            FLAME_m_sub_3_message_board_read == 1)
                rc = MB_SetAccessMode(b_m_sub_3, MB_MODE_READWRITE);
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
           fprintf(stderr, "ERROR: Could not set access mode of 'm_sub_3' board\n");
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
               default:
                   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
           }
               
               exit(rc);
        }
        #endif
        FLAME_m_sub_4_message_board_write = 0;
        FLAME_m_sub_4_message_board_read = 0;
        /* Sending agents */
        if(agent_a_start_state->agents != NULL) FLAME_m_sub_4_message_board_write = 1;
        
        /* Reading agents */
        if(agent_a_start_state->agents != NULL) FLAME_m_sub_4_message_board_read = 1;
        
        /* Call message board library with details */
        if(FLAME_m_sub_4_message_board_write == 0 &&
            FLAME_m_sub_4_message_board_read == 0)
                rc = MB_SetAccessMode(b_m_sub_4, MB_MODE_IDLE);
        if(FLAME_m_sub_4_message_board_write == 1 &&
            FLAME_m_sub_4_message_board_read == 0)
                rc = MB_SetAccessMode(b_m_sub_4, MB_MODE_WRITEONLY);
        if(FLAME_m_sub_4_message_board_write == 0 &&
            FLAME_m_sub_4_message_board_read == 1)
                rc = MB_SetAccessMode(b_m_sub_4, MB_MODE_READONLY);
        if(FLAME_m_sub_4_message_board_write == 1 &&
            FLAME_m_sub_4_message_board_read == 1)
                rc = MB_SetAccessMode(b_m_sub_4, MB_MODE_READWRITE);
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
           fprintf(stderr, "ERROR: Could not set access mode of 'm_sub_4' board\n");
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
               default:
                   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
           }
               
               exit(rc);
        }
        #endif
        
        
		
		/* Start sync message boards that don't write */
		if(FLAME_m_sub_1_message_board_write == 0)
		{
			/*printf("%d> m_sub_1 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_m_sub_1)\n");
			rc = MB_SyncStart(b_m_sub_1);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_m_sub_1)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'm_sub_1' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_m_sub_2_message_board_write == 0)
		{
			/*printf("%d> m_sub_2 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_m_sub_2)\n");
			rc = MB_SyncStart(b_m_sub_2);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_m_sub_2)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'm_sub_2' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_m_sub_3_message_board_write == 0)
		{
			/*printf("%d> m_sub_3 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_m_sub_3)\n");
			rc = MB_SyncStart(b_m_sub_3);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_m_sub_3)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'm_sub_3' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		/* Start sync message boards that don't write */
		if(FLAME_m_sub_4_message_board_write == 0)
		{
			/*printf("%d> m_sub_4 message board sync start early as no agents sending any messages of this type\n", node_number);*/
			
			/* ********** sync message board here **********  */
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_m_sub_4)\n");
			rc = MB_SyncStart(b_m_sub_4);
			if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_m_sub_4)\n");
			#ifdef ERRCHECK
			if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not start sync of 'm_sub_4' board\n");
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
				   default:
					   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
					   break;
			   }
			   
					   
					   exit(rc);
			   }
			   #endif
		}
		
		

	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start agent_a_1\n");
	current_xmachine_agent_a_holder = agent_a_start_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		current_xmachine_agent_a = current_xmachine_agent_a_holder->agent;
		current_xmachine_agent_a_next_state = agent_a_middle1_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_agent_a = NULL;
		current_xmachine->xmachine_agent_b = NULL;
		current_xmachine->xmachine_agent_a = current_xmachine_agent_a;

		

		

			i = agent_a_1();

		

			if(i == 1)
			{
				free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_start_state);
			}
			else
			{
				transition_agent_a_agent(current_xmachine_agent_a_holder, agent_a_start_state, agent_a_middle1_state);
			}
		

		current_xmachine_agent_a = NULL;

		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish agent_a_1\n");

	if(FLAME_m_sub_1_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_m_sub_1)\n");
		rc = MB_SyncStart(b_m_sub_1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_m_sub_1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'm_sub_1' board\n");
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
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 0 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_m_sub_1_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_m_sub_1)\n");
		rc = MB_SyncComplete(b_m_sub_1);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_m_sub_1)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'm_sub_1' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'm_sub_1' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start agent_a_2\n");
	current_xmachine_agent_a_holder = agent_a_middle1_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		current_xmachine_agent_a = current_xmachine_agent_a_holder->agent;
		current_xmachine_agent_a_next_state = agent_a_middle2_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_agent_a = NULL;
		current_xmachine->xmachine_agent_b = NULL;
		current_xmachine->xmachine_agent_a = current_xmachine_agent_a;

		

		
		
          
                  
          
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = agent_a_2();

		
		    rc = MB_Iterator_Delete(&i_m_sub_1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'm_sub_1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'm_sub_1' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle1_state);
			}
			else
			{
				transition_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle1_state, agent_a_middle2_state);
			}
		

		current_xmachine_agent_a = NULL;

		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish agent_a_2\n");

	if(FLAME_m_sub_2_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_m_sub_2)\n");
		rc = MB_SyncStart(b_m_sub_2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_m_sub_2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'm_sub_2' board\n");
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
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start agent_b_1\n");
	current_xmachine_agent_b_holder = agent_b_start_state->agents;
	while(current_xmachine_agent_b_holder)
	{
		temp_xmachine_agent_b_holder = current_xmachine_agent_b_holder->next;
		current_xmachine_agent_b = current_xmachine_agent_b_holder->agent;
		current_xmachine_agent_b_next_state = agent_b_middle_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_agent_a = NULL;
		current_xmachine->xmachine_agent_b = NULL;
		current_xmachine->xmachine_agent_b = current_xmachine_agent_b;

		

		
		
          
                  
          
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = agent_b_1();

		
		    rc = MB_Iterator_Delete(&i_m_sub_1);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'm_sub_1' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'm_sub_1' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_agent_b_agent(current_xmachine_agent_b_holder, agent_b_start_state);
			}
			else
			{
				transition_agent_b_agent(current_xmachine_agent_b_holder, agent_b_start_state, agent_b_middle_state);
			}
		

		current_xmachine_agent_b = NULL;

		current_xmachine_agent_b_holder = temp_xmachine_agent_b_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish agent_b_1\n");


/* End of layer number 1 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_m_sub_1_message_board_read == 0)
{
	/*printf("%d> m_sub_1 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_m_sub_1)\n");
	rc = MB_SyncComplete(b_m_sub_1);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_m_sub_1)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'm_sub_1' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'm_sub_1' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

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


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start agent_a_3\n");
	current_xmachine_agent_a_holder = agent_a_middle2_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		current_xmachine_agent_a = current_xmachine_agent_a_holder->agent;
		current_xmachine_agent_a_next_state = agent_a_middle3_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_agent_a = NULL;
		current_xmachine->xmachine_agent_b = NULL;
		current_xmachine->xmachine_agent_a = current_xmachine_agent_a;

		

		

			i = agent_a_3();

		

			if(i == 1)
			{
				free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle2_state);
			}
			else
			{
				transition_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle2_state, agent_a_middle3_state);
			}
		

		current_xmachine_agent_a = NULL;

		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish agent_a_3\n");

	if(FLAME_m_sub_3_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_m_sub_3)\n");
		rc = MB_SyncStart(b_m_sub_3);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_m_sub_3)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'm_sub_3' board\n");
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
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_m_sub_2_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_m_sub_2)\n");
		rc = MB_SyncComplete(b_m_sub_2);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_m_sub_2)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'm_sub_2' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'm_sub_2' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start agent_b_2\n");
	current_xmachine_agent_b_holder = agent_b_middle_state->agents;
	while(current_xmachine_agent_b_holder)
	{
		temp_xmachine_agent_b_holder = current_xmachine_agent_b_holder->next;
		current_xmachine_agent_b = current_xmachine_agent_b_holder->agent;
		current_xmachine_agent_b_next_state = agent_b_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_agent_a = NULL;
		current_xmachine->xmachine_agent_b = NULL;
		current_xmachine->xmachine_agent_b = current_xmachine_agent_b;

		

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = agent_b_2();

		
		    rc = MB_Iterator_Delete(&i_m_sub_2);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'm_sub_2' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'm_sub_2' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_agent_b_agent(current_xmachine_agent_b_holder, agent_b_middle_state);
			}
			else
			{
				transition_agent_b_agent(current_xmachine_agent_b_holder, agent_b_middle_state, agent_b_end_state);
			}
		

		current_xmachine_agent_b = NULL;

		current_xmachine_agent_b_holder = temp_xmachine_agent_b_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish agent_b_2\n");


/* End of layer number 2 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_m_sub_2_message_board_read == 0)
{
	/*printf("%d> m_sub_2 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_m_sub_2)\n");
	rc = MB_SyncComplete(b_m_sub_2);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_m_sub_2)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'm_sub_2' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'm_sub_2' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

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


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_m_sub_3_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_m_sub_3)\n");
		rc = MB_SyncComplete(b_m_sub_3);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_m_sub_3)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'm_sub_3' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'm_sub_3' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start agent_a_4\n");
	current_xmachine_agent_a_holder = agent_a_middle3_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		current_xmachine_agent_a = current_xmachine_agent_a_holder->agent;
		current_xmachine_agent_a_next_state = agent_a_middle4_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_agent_a = NULL;
		current_xmachine->xmachine_agent_b = NULL;
		current_xmachine->xmachine_agent_a = current_xmachine_agent_a;

		

		
		
          
                  
          
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = agent_a_4();

		
		    rc = MB_Iterator_Delete(&i_m_sub_3);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'm_sub_3' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'm_sub_3' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle3_state);
			}
			else
			{
				transition_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle3_state, agent_a_middle4_state);
			}
		

		current_xmachine_agent_a = NULL;

		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish agent_a_4\n");

	if(FLAME_m_sub_4_message_board_write == 1)
	{

		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_m_sub_4)\n");
		rc = MB_SyncStart(b_m_sub_4);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_m_sub_4)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not start sync of 'm_sub_4' board\n");
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
			   default:
				   fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }

			
			exit(rc);
		}
		#endif
    }
    


/* End of layer number 3 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */


	/* If mb is not read then leave sync complete until last possible moment */
	if(FLAME_m_sub_4_message_board_read == 1)
	{
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_m_sub_4)\n");
		rc = MB_SyncComplete(b_m_sub_4);
		if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_m_sub_4)\n");
		#ifdef ERRCHECK
		if (rc != MB_SUCCESS)
		{
		   fprintf(stderr, "ERROR: Could not complete sync of 'm_sub_4' board\n");
		   switch(rc) {
				case MB_ERR_INVALID:
				   fprintf(stderr, "\t reason: 'm_sub_4' board is invalid\n");
				   break;
			   case MB_ERR_MEMALLOC:
				   fprintf(stderr, "\t reason: out of memory\n");
				   break;
			   case MB_ERR_INTERNAL:
				   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
				   break;
			   default:
				   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
				   break;
		   }
	
		   
		   exit(rc);
		}
		#endif
    
    
    
	}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start agent_a_5\n");
	current_xmachine_agent_a_holder = agent_a_middle4_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		current_xmachine_agent_a = current_xmachine_agent_a_holder->agent;
		current_xmachine_agent_a_next_state = agent_a_end_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_agent_a = NULL;
		current_xmachine->xmachine_agent_b = NULL;
		current_xmachine->xmachine_agent_a = current_xmachine_agent_a;

		

		
		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
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
	           default:
	           
                   fprintf(stderr, "\t MB_Iterator_CreateFiltered returned error code: %d (see libmboard docs for details)\n", rc);
               
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = agent_a_5();

		
		    rc = MB_Iterator_Delete(&i_m_sub_3);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'm_sub_3' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'm_sub_3' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_m_sub_4);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'm_sub_4' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'm_sub_4' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle4_state);
			}
			else
			{
				transition_agent_a_agent(current_xmachine_agent_a_holder, agent_a_middle4_state, agent_a_end_state);
			}
		

		current_xmachine_agent_a = NULL;

		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish agent_a_5\n");


/* End of layer number 4 */

/* Clear message boards that have finished being used
 * and sync complete if doing late sync complete */

if(FLAME_m_sub_3_message_board_read == 0)
{
	/*printf("%d> m_sub_3 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_m_sub_3)\n");
	rc = MB_SyncComplete(b_m_sub_3);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_m_sub_3)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'm_sub_3' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'm_sub_3' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

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

if(FLAME_m_sub_4_message_board_read == 0)
{
	/*printf("%d> m_sub_4 message board sync complete late as no agents reading any messages of this type\n", node_number);*/
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_m_sub_4)\n");
	rc = MB_SyncComplete(b_m_sub_4);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_m_sub_4)\n");
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not complete sync of 'm_sub_4' board\n");
	   switch(rc) {
			case MB_ERR_INVALID:
			   fprintf(stderr, "\t reason: 'm_sub_4' board is invalid\n");
			   break;
		   case MB_ERR_MEMALLOC:
			   fprintf(stderr, "\t reason: out of memory\n");
			   break;
		   case MB_ERR_INTERNAL:
			   fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
			   break;
		   default:
			   fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
			   break;
	   }

	   
	   exit(rc);
	}
	#endif
}

    /* Delete any search trees */

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


	if(iteration_loop%output_frequency == output_offset)
	{
		saveiterationdata(iteration_loop);
	}

	/*printf("agent_a_end_state->count = %d\n", agent_a_end_state->count);*/
	agent_a_end_state->count = 0;

	/*printf("agent_a_middle4_state->count = %d\n", agent_a_middle4_state->count);*/
	agent_a_middle4_state->count = 0;

	/*printf("agent_a_middle3_state->count = %d\n", agent_a_middle3_state->count);*/
	agent_a_middle3_state->count = 0;

	/*printf("agent_a_middle2_state->count = %d\n", agent_a_middle2_state->count);*/
	agent_a_middle2_state->count = 0;

	/*printf("agent_a_middle1_state->count = %d\n", agent_a_middle1_state->count);*/
	agent_a_middle1_state->count = 0;

	/*printf("agent_a_start_state->count = %d\n", agent_a_start_state->count);*/
	agent_a_start_state->count = 0;

	/*printf("agent_b_end_state->count = %d\n", agent_b_end_state->count);*/
	agent_b_end_state->count = 0;

	/*printf("agent_b_middle_state->count = %d\n", agent_b_middle_state->count);*/
	agent_b_middle_state->count = 0;

	/*printf("agent_b_start_state->count = %d\n", agent_b_start_state->count);*/
	agent_b_start_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_agent_a_holder = agent_a_end_state->agents;
	while(current_xmachine_agent_a_holder)
	{
		temp_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
		transition_agent_a_agent(current_xmachine_agent_a_holder, agent_a_end_state, agent_a_start_state);

		current_xmachine_agent_a_holder = temp_xmachine_agent_a_holder;
	}

	current_xmachine_agent_b_holder = agent_b_end_state->agents;
	while(current_xmachine_agent_b_holder)
	{
		temp_xmachine_agent_b_holder = current_xmachine_agent_b_holder->next;
		transition_agent_b_agent(current_xmachine_agent_b_holder, agent_b_end_state, agent_b_start_state);

		current_xmachine_agent_b_holder = temp_xmachine_agent_b_holder;
	}

    if(iteration_loop%output_frequency == output_offset)
    {
        saveiterationdata(iteration_loop);
    }

		/* Calculate if any agents need to jump S.P. */
		/* propagate_agents(); */
	/* Save iteration time to log file */

		if((file = fopen(logfilepath, "a"))==NULL)
		{
			printf("Error: cannot open file '%s' for writing\n", logfilepath);
			exit(0);
		}
		(void)fputs("<iteration><no>", file);
		sprintf(data, "%i", iteration_loop);
		(void)fputs(data, file);
		(void)fputs("</no><time>", file);
		sprintf(data, "%d", (int)((get_time() - interval) * 1000) );
		(void)fputs(data, file);
		(void)fputs("</time></iteration>\n", file);
		(void)fclose(file);


#ifdef START_END
/* End iteration function */
	end_iteration();
#endif
	}

#ifdef START_END
/* End simualtion function */
	end_simulation();
#endif

    



	/* Stop timing and print total time */
	stop = get_time();
	total_time = stop - start;
	printf("Execution time - %d:%02d:%03d [mins:secs:msecs]\n",
       (int)(total_time/60), ((int)total_time)%60, (((int)(total_time * 1000.0)) % 1000));

	clean_up(0);

	/* Exit successfully by returning zero to Operating System */
	return 0;
}
