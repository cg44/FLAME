/**
 * \file  xml.c
 * \brief Holds xml reading and writing functions.
 */

#include "header.h"

/** \fn void read_int_static_array(char * buffer, int * j, int ** int_static_array)
 * \brief Reads integer static array.
 */
int read_int_static_array(char * buffer, int /*@unused@*/ buffer_size, int * j, int * int_static_array, int /*@unused@*/ size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		if (arraycount < size) int_static_array[arraycount] = atoi(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	if (arraycount > size)
	{
				fprintf(stderr, "WARNING: %d 'int' values provided for static array of size %d. Surplus values ignored.\n",
				arraycount, size);
	}
	
	(*j)++;
	return 0;
}

/** \fn void read_float_static_array(char * buffer, int * (*j), int ** float_static_array)
 * \brief Reads float static array.
 */
int read_float_static_array(char * buffer, int /*@unused@*/ buffer_size, int * j, float * float_static_array, int /*@unused@*/ size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		if (arraycount < size) float_static_array[arraycount] = (float)atof(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	if (arraycount > size)
	{
				fprintf(stderr, "WARNING: %d 'float' values provided for static array of size %d. Surplus values ignored.\n",
				arraycount, size);
	}
	
	(*j)++;
	return 0;
}

/** \fn void read_double_static_array(char * buffer, int * (*j), int ** double_static_array)
 * \brief Reads double static array.
 */
int read_double_static_array(char * buffer, int /*@unused@*/ buffer_size, int * j, double * double_static_array, int /*@unused@*/ size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		if (arraycount < size) double_static_array[arraycount] = atof(arraydata);		
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	if (arraycount > size)
	{
		fprintf(stderr, "WARNING: %d 'double' values provided for static array of size %d. Surplus values ignored.\n",
				arraycount, size);
	}
	
	(*j)++;
	return 0;
}

/** \fn void read_char_static_array(char * buffer, int * (*j), int ** char_static_array)
 * \brief Reads char static array.
 */
int read_char_static_array(char * buffer, int /*@unused@*/ buffer_size, int * j, char * char_static_array, int size)
{
	int arraycount;
	
	while(buffer[(*j)] == ' ')
	{
		(*j)++;
	}
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		char_static_array[arraycount] = buffer[(*j)];
		(*j)++;
	}

	//(*j)++;
	return 0;
}

/** \fn void read_int_dynamic_array(char * buffer, int * (*j), int ** int_dynamic_array)
 * \brief Reads integer dynamic array.
 */
int read_int_dynamic_array(char * buffer, int /*@unused@*/ buffer_size, int * j, int_array * int_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		add_int(int_dynamic_array, atoi(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_float_dynamic_array(char * buffer, int * (*j), int ** float_dynamic_array)
 * \brief Reads float dynamic array.
 */
int read_float_dynamic_array(char * buffer, int /*@unused@*/ buffer_size, int * j, float_array * float_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		add_float(float_dynamic_array, (float)atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_double_dynamic_array(char * buffer, int * (*j), int ** double_dynamic_array)
 * \brief Reads double dynamic array.
 */
int read_double_dynamic_array(char * buffer, int /*@unused@*/ buffer_size, int * j, double_array * double_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[100000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = '\0';
		add_double(double_dynamic_array, atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_char_dynamic_array(char * buffer, int * (*j), int ** char_dynamic_array)
 * \brief Reads char dynamic array.
 */
int read_char_dynamic_array(char * buffer, int /*@unused@*/ buffer_size, int * j, char_array * char_dynamic_array)
{
	if(*j > buffer_size) return -1;
	
	while(buffer[(*j)] == ' ')
	{
		(*j)++;
	}
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != ',' && buffer[(*j)] != '}')
	{
		add_char(char_dynamic_array, buffer[(*j)]);
		(*j)++;
	}
	
	return 0;
}


/** \fn void read_my_datatype_1(char * buffer, int * j, my_datatype_1 * temp_datatype)
 * \brief Reads my_datatype_1 datatype.
 */
int read_my_datatype_1(char * buffer, int /*@unused@*/ buffer_size, int * j, my_datatype_1 * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).type = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).type = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_my_datatype_1_dynamic_array(char * buffer, int buffer_size, int * j, my_datatype_1_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_my_datatype_1(temp_datatype_array, 0, 0);
			rc = read_my_datatype_1(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'my_datatype_1' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_my_datatype_1_static_array(char * buffer, int buffer_size, int * j, my_datatype_1 * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_my_datatype_1(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'my_datatype_1' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_my_datatype_2(char * buffer, int * j, my_datatype_2 * temp_datatype)
 * \brief Reads my_datatype_2 datatype.
 */
int read_my_datatype_2(char * buffer, int /*@unused@*/ buffer_size, int * j, my_datatype_2 * temp_datatype)
{
	
	int rc;
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;


	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		rc = read_int_static_array(buffer, buffer_size, j, (*temp_datatype).int_list, 2);
		if(rc != 0) { printf("Error: reading variable 'int_list' of type 'int'\n"); return -1; }
	}
	
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	rc = read_my_datatype_1_static_array(buffer, buffer_size, j, (*temp_datatype).var_my_datatype_1_list, 2);
	if(rc != 0) return -1;
	
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	rc = read_my_datatype_1(buffer, buffer_size, j, &(*temp_datatype).var_my_datatype_1);
	if(rc != 0) return -1;
	(*j)++;

	return 0;
}

int read_my_datatype_2_dynamic_array(char * buffer, int buffer_size, int * j, my_datatype_2_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	int int_list[2];
# ifndef S_SPLINT_S
	init_int_static_array(int_list, 2);
# endif
	
	my_datatype_1 var_my_datatype_1_list[2];
# ifndef S_SPLINT_S
	init_my_datatype_1_static_array(var_my_datatype_1_list, 2);
# endif
	my_datatype_1 var_my_datatype_1;
# ifndef S_SPLINT_S
	init_my_datatype_1(&var_my_datatype_1);
# endif
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_my_datatype_2(temp_datatype_array, int_list, var_my_datatype_1_list, &var_my_datatype_1);
			rc = read_my_datatype_2(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'my_datatype_2' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_my_datatype_2_static_array(char * buffer, int buffer_size, int * j, my_datatype_2 * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_my_datatype_2(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'my_datatype_2' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_my_datatype_3(char * buffer, int * j, my_datatype_3 * temp_datatype)
 * \brief Reads my_datatype_3 datatype.
 */
int read_my_datatype_3(char * buffer, int /*@unused@*/ buffer_size, int * j, my_datatype_3 * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	int rc;
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).int_single = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).int_single = atoi(arraydata);
	(*j)++;
	(*temp_datatype).float_single = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).float_single = atof(arraydata);
	(*j)++;
	(*temp_datatype).double_single = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).double_single = atof(arraydata);
	(*j)++;
	(*temp_datatype).char_single = ' ';
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).char_single = (arraydata[array_k-1]);
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		rc = read_int_static_array(buffer, buffer_size, j, (*temp_datatype).int_list, 2);
		if(rc != 0) { printf("Error: reading variable 'int_list' of type 'int'\n"); return -1; }
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		rc = read_float_static_array(buffer, buffer_size, j, (*temp_datatype).float_list, 2);
		if(rc != 0) { printf("Error: reading variable 'float_list' of type 'float'\n"); return -1; }
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		rc = read_double_static_array(buffer, buffer_size, j, (*temp_datatype).double_list, 2);
		if(rc != 0) { printf("Error: reading variable 'double_list' of type 'double'\n"); return -1; }
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		
		rc = read_char_static_array(buffer, buffer_size, j, (*temp_datatype).char_list, 2);
		if(rc != 0) { printf("Error: reading variable 'char_list' of type 'char'\n"); return -1; }
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		
		rc = read_int_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).int_dynamic_list);
		if(rc != 0) { printf("Error: reading variable 'int_dynamic_list' of type 'int_array'\n"); return -1; }
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		
		rc = read_float_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).float_dynamic_list);
		if(rc != 0) { printf("Error: reading variable 'float_dynamic_list' of type 'float_array'\n"); return -1; }
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		
		rc = read_double_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).double_dynamic_list);
		if(rc != 0) { printf("Error: reading variable 'double_dynamic_list' of type 'double_array'\n"); return -1; }
	}
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		
		
		rc = read_char_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).char_dynamic_list);
		if(rc != 0) { printf("Error: reading variable 'char_dynamic_list' of type 'char_array'\n"); return -1; }
	}
	
	(*j)++;

	return 0;
}

int read_my_datatype_3_dynamic_array(char * buffer, int buffer_size, int * j, my_datatype_3_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	int int_list[2];
# ifndef S_SPLINT_S
	init_int_static_array(int_list, 2);
# endif
	
	float float_list[2];
# ifndef S_SPLINT_S
	init_float_static_array(float_list, 2);
# endif
	
	double double_list[2];
# ifndef S_SPLINT_S
	init_double_static_array(double_list, 2);
# endif
	
	char char_list[2];
# ifndef S_SPLINT_S
	init_char_static_array(char_list, 2);
# endif
	
	
	int_array int_dynamic_list;
# ifndef S_SPLINT_S
	init_int_array(&int_dynamic_list);
# endif
	
	float_array float_dynamic_list;
# ifndef S_SPLINT_S
	init_float_array(&float_dynamic_list);
# endif
	
	double_array double_dynamic_list;
# ifndef S_SPLINT_S
	init_double_array(&double_dynamic_list);
# endif
	
	char_array char_dynamic_list;
# ifndef S_SPLINT_S
	init_char_array(&char_dynamic_list);
# endif

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_my_datatype_3(temp_datatype_array, 0, 0.0, 0.0, ' ', int_list, float_list, double_list, char_list, &int_dynamic_list, &float_dynamic_list, &double_dynamic_list, &char_dynamic_list);
			rc = read_my_datatype_3(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'my_datatype_3' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	free_int_array(&int_dynamic_list);
	free_float_array(&float_dynamic_list);
	free_double_array(&double_dynamic_list);
	free_char_array(&char_dynamic_list);
	
	
	return 0;
}

int read_my_datatype_3_static_array(char * buffer, int buffer_size, int * j, my_datatype_3 * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_my_datatype_3(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'my_datatype_3' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_data_type_sales(char * buffer, int * j, data_type_sales * temp_datatype)
 * \brief Reads data_type_sales datatype.
 */
int read_data_type_sales(char * buffer, int /*@unused@*/ buffer_size, int * j, data_type_sales * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).period = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).period = atoi(arraydata);
	(*j)++;
	(*temp_datatype).sales = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).sales = atof(arraydata);
	(*j)++;

	return 0;
}

int read_data_type_sales_dynamic_array(char * buffer, int buffer_size, int * j, data_type_sales_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_data_type_sales(temp_datatype_array, 0, 0.0);
			rc = read_data_type_sales(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'data_type_sales' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	
	
	return 0;
}

int read_data_type_sales_static_array(char * buffer, int buffer_size, int * j, data_type_sales * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_data_type_sales(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'data_type_sales' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_sales_statistics(char * buffer, int * j, sales_statistics * temp_datatype)
 * \brief Reads sales_statistics datatype.
 */
int read_sales_statistics(char * buffer, int /*@unused@*/ buffer_size, int * j, sales_statistics * temp_datatype)
{
	int array_k;
	char arraydata[100000];
	int rc;
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).mall_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = '\0';
	(*temp_datatype).mall_id = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	rc = read_data_type_sales_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).sales);
	if(rc != 0) return -1;
	
	(*j)++;

	return 0;
}

int read_sales_statistics_dynamic_array(char * buffer, int buffer_size, int * j, sales_statistics_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	data_type_sales_array sales;
# ifndef S_SPLINT_S
	init_data_type_sales_array(&sales);
# endif

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_sales_statistics(temp_datatype_array, 0, &sales);
			rc = read_sales_statistics(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'sales_statistics' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	free_data_type_sales_array(&sales);
	
	
	return 0;
}

int read_sales_statistics_static_array(char * buffer, int buffer_size, int * j, sales_statistics * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_sales_statistics(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'sales_statistics' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}



int readEnvironmentXML(char * location)
{
	FILE * file;
	char c = '\0';
	char buffer[100000];
	int index = 0;
	int in_environment = 0;
	int in_env_int = 0;
	int in_env_float = 0;
	int in_env_double = 0;
	int in_env_char = 0;
	

	buffer[0] = '\0';

	/* Open file */
	if((file = fopen(location, "r"))==NULL)
	{
		printf("Error: cannot open import xml file '%s'\n", location);
		exit(0);
	}
	printf("Reading environment data from: %s\n", location);
	/* Keep reading file until EOF */
	while(c != (char)EOF)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		if(c == '>')
		{
			buffer[index] = '\0';
			if(strcmp(buffer, "environment") == 0) in_environment = 1;
			if(strcmp(buffer, "/environment") == 0) in_environment = 0;
			if(strcmp(buffer, "env_int") == 0) in_env_int = 1;
			if(strcmp(buffer, "/env_int") == 0) in_env_int = 0;
			if(strcmp(buffer, "env_float") == 0) in_env_float = 1;
			if(strcmp(buffer, "/env_float") == 0) in_env_float = 0;
			if(strcmp(buffer, "env_double") == 0) in_env_double = 1;
			if(strcmp(buffer, "/env_double") == 0) in_env_double = 0;
			if(strcmp(buffer, "env_char") == 0) in_env_char = 1;
			if(strcmp(buffer, "/env_char") == 0) in_env_char = 0;
			
			index = 0;
			buffer[index] = '\0';
		}
		else if(c == '<')
		{
			buffer[index] = '\0';
			if(in_environment == 1)
			{
				if(in_env_int == 1) { FLAME_environment_variable_env_int = atoi(buffer); }
				if(in_env_float == 1) { FLAME_environment_variable_env_float = (float)atof(buffer); }
				if(in_env_double == 1) { FLAME_environment_variable_env_double = atof(buffer); }
				if(in_env_char == 1) { FLAME_environment_variable_env_char = (buffer[0]); }
				
			}
			index = 0;
			buffer[index] = '\0';
		}
		else
		{
			buffer[index] = c;
			if(index < 999) index++;
		}
	}
	/* Close file */
	(void)fclose(file);

	return 0;
}

int readAgentXML(char * location,
				double cloud_data[],
				int partition_method,
				int flag,
				int number_partitions,
				int agent_count,
				int * itno)
{
	FILE * file;
	char c = '\0';
	char buffer[100000];
	char agentname[10000];
	int index = 0;
	int j; /* Index for reading arrays */
	int rc;
	int in_itno = 0;
	int FLAME_in_xagent = 0;
	int FLAME_in_name = 0;
	int in_agent_a_agent = 0;
	int in_agent_b_agent = 0;
	
	int in_int_single = 0;
	int in_int_single_2 = 0;
	int in_float_single = 0;
	int in_double_single = 0;
	int in_char_single = 0;
	int in_int_list = 0;
	int in_float_list = 0;
	int in_double_list = 0;
	int in_char_list = 0;
	
	xmachine_memory_agent_a * current_agent_a_agent = NULL;
	xmachine_memory_agent_b * current_agent_b_agent = NULL;
	
	/* Things for round-robin partitioning */
	int geometric = 1;
	int other = 2;
	double posx=0.0, posy=0.0, posz=0.0;

	j = 0;
	rc = 0;
	
	/* Use j and rc to stop compiler warnings if not used */
	if(j == 0 && rc == 0) {}
	
	agentname[0] = '\0';
	buffer[0] = '\0';

	/* Open file */
	if((file = fopen(location, "r"))==NULL)
	{
		printf("Error: cannot open import xml file '%s'\n", location);
		exit(0);
	}
	printf("Reading agent data from: %s\n", location);
	/* Keep reading file until EOF */
	while(c != (char)EOF)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		if(c == '>')
		{
			buffer[index] = '\0';
			if(strcmp(buffer, "itno") == 0) in_itno = 1;
			if(strcmp(buffer, "/itno") == 0) in_itno = 0;
			if(strcmp(buffer, "xagent") == 0)
			{
				FLAME_in_xagent = 1;
				agentname[0] = '\0';
			}
			if(strcmp(buffer, "/xagent") == 0)
			{	
				if(strcmp(agentname, "agent_a") == 0)
				{
					if(current_agent_a_agent == NULL) { printf("Memory error reading agent_a agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_agent_a_agent_internal(current_agent_a_agent, agent_a_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_agent_a_agent_internal(current_agent_a_agent, agent_a_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_agent_a_agent_internal(current_agent_a_agent, agent_a_start_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "agent_b") == 0)
				{
					if(current_agent_b_agent == NULL) { printf("Memory error reading agent_b agent\n"); exit(0); }
					
					posx = (double)0.0;
					posy = (double)0.0;
					posz = (double)0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_agent_b_agent_internal(current_agent_b_agent, agent_b_start_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_agent_b_agent_internal(current_agent_b_agent, agent_b_start_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								add_agent_b_agent_internal(current_agent_b_agent, agent_b_start_state);
							}
							++agent_count;
						}
					}
				}
				else
				{
					printf("Warning: agent name undefined - '%s'\n", agentname);
					exit(0);
				}
				agentname[0] = '\0';
				FLAME_in_xagent = 0;
				in_agent_a_agent = 0;
				in_agent_b_agent = 0;
				
			}
			if(strcmp(buffer, "name") == 0) FLAME_in_name = 1;
			if(strcmp(buffer, "/name") == 0) FLAME_in_name = 0;
			if(strcmp(buffer, "int_single") == 0) { in_int_single = 1; }
			if(strcmp(buffer, "/int_single") == 0) { in_int_single = 0; }
			if(strcmp(buffer, "int_single_2") == 0) { in_int_single_2 = 1; }
			if(strcmp(buffer, "/int_single_2") == 0) { in_int_single_2 = 0; }
			if(strcmp(buffer, "float_single") == 0) { in_float_single = 1; }
			if(strcmp(buffer, "/float_single") == 0) { in_float_single = 0; }
			if(strcmp(buffer, "double_single") == 0) { in_double_single = 1; }
			if(strcmp(buffer, "/double_single") == 0) { in_double_single = 0; }
			if(strcmp(buffer, "char_single") == 0) { in_char_single = 1; }
			if(strcmp(buffer, "/char_single") == 0) { in_char_single = 0; }
			if(strcmp(buffer, "int_list") == 0) { in_int_list = 1; }
			if(strcmp(buffer, "/int_list") == 0) { in_int_list = 0; }
			if(strcmp(buffer, "float_list") == 0) { in_float_list = 1; }
			if(strcmp(buffer, "/float_list") == 0) { in_float_list = 0; }
			if(strcmp(buffer, "double_list") == 0) { in_double_list = 1; }
			if(strcmp(buffer, "/double_list") == 0) { in_double_list = 0; }
			if(strcmp(buffer, "char_list") == 0) { in_char_list = 1; }
			if(strcmp(buffer, "/char_list") == 0) { in_char_list = 0; }
			
			index = 0;
			buffer[index] = '\0';
		}
		else if(c == '<')
		{
			buffer[index] = '\0';
			
			if(in_itno && FLAME_in_xagent == 0) *itno = atoi(buffer);
			if(FLAME_in_xagent == 1)
			{
				if(FLAME_in_name == 1)
				{
					strcpy(agentname, buffer);

					if(strcmp(agentname, "agent_a") == 0)
					{
						current_agent_a_agent = init_agent_a_agent();
						in_agent_a_agent = 1;
					}
					else if(strcmp(agentname, "agent_b") == 0)
					{
						current_agent_b_agent = init_agent_b_agent();
						in_agent_b_agent = 1;
					}
					else
					{
						printf("Warning: agent name undefined - '%s'\n", agentname);
						exit(0);
					}
				}
				else if(in_agent_a_agent == 1)
				{
					if(in_int_single) { current_agent_a_agent->int_single = atoi(buffer); }
					if(in_int_single_2) { current_agent_a_agent->int_single_2 = atoi(buffer); }
					if(in_float_single) { current_agent_a_agent->float_single = atof(buffer); }
					if(in_double_single) { current_agent_a_agent->double_single = atof(buffer); }
					if(in_char_single) { current_agent_a_agent->char_single = (buffer[0]); }
					if(in_int_list) { j = 0;
						rc = read_int_static_array(buffer, index, &j, current_agent_a_agent->int_list, 2);
						if(rc != 0) { printf("Error: reading 'agent_a' agent variable 'int_list' of type 'int'\n"); exit(0); } }
					if(in_float_list) { j = 0;
						rc = read_float_static_array(buffer, index, &j, current_agent_a_agent->float_list, 2);
						if(rc != 0) { printf("Error: reading 'agent_a' agent variable 'float_list' of type 'float'\n"); exit(0); } }
					if(in_double_list) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_agent_a_agent->double_list, 2);
						if(rc != 0) { printf("Error: reading 'agent_a' agent variable 'double_list' of type 'double'\n"); exit(0); } }
					if(in_char_list) { j = 0;
						rc = read_char_static_array(buffer, index, &j, current_agent_a_agent->char_list, 2);
						if(rc != 0) { printf("Error: reading 'agent_a' agent variable 'char_list' of type 'char'\n"); exit(0); } }
				 }else if(in_agent_b_agent == 1)
				{
					if(in_int_single) { current_agent_b_agent->int_single = atoi(buffer); }
				 }
			}
			index = 0;
			buffer[index] = '\0';
		}
		else
		{
			buffer[index] = c;
			if(index < 99999) index++;
			else
			{
				printf("Error: agent reading buffer too small\n");
				printf("%s\n", buffer);
				exit(0);
			}
		}
	}
	/* Close file */
	(void)fclose(file);

	return 0;
}

/** \fn void check_location_exists(char * location)
 * \brief Check that a directory exists.
 * \param location The directory location to check.
 */
int check_location_exists(char * location)
{
	/* Save a dummy file to directory and remove.
	 * This checks directory exists and is writable */
	FILE * file;
	char * buffer;

	buffer = (char *)malloc( (strlen(location) + strlen("dummy.temp") + 1) * sizeof(char));
	strcpy(buffer, location);
	strcat(buffer, "dummy.temp");

	if((file = fopen(buffer, "w")) == NULL) return 0;

	(void)fclose(file);
	/* Remove dummy file */
	remove(buffer);

	return 1;
}


/** \fn void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
 * \brief Read initial X-machine memory starting values from a file.
 * \param filename The path to the file.
 * \param filelocation The directory of the location
 * \param itno Pointer to the iteration number.
 * \param agent_list List of agents in the model to be constructed by this function.
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param partition_method Identifies partitioning method: 1 = geometric, 2 = round-robin
 * \param flag Flag for whether to check space partitions.
 */
void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[],
					   int partition_method, int flag)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = '\0';
	char buffer[100000];
	char FLAME_location[10000];
	char FLAME_format[10000];
	char FLAME_type[10000];
	FLAME_output * current_FLAME_output = NULL;

	/* Things for round-robin partitioning */
	int agent_count = 0;
	int number_partitions = 0;
	int geometric=1;
	int other=2;
	

	/* Cloud data array initialisation */
	# ifndef S_SPLINT_S
	cloud_data[0] = SPINF;
	cloud_data[1] = -SPINF;
	cloud_data[2] = SPINF;
	cloud_data[3] = -SPINF;
	cloud_data[4] = SPINF;
	cloud_data[5] = -SPINF;
	# endif

	/* Temporary node and head of associated agent list to allow adding agents */
	node_information temp_node;

	/* Pointer to x-memory for initial state data */
	/*xmachine * current_xmachine;*/
	/* Variables for checking tags */
	int reading = 1;
	int i = 0;
	int rc;
	int in_tag = 0;
	int in_itno = 0;
	int FLAME_in_imports = 0;
	int FLAME_in_import = 0;
	int FLAME_in_outputs = 0;
	int FLAME_in_output = 0;
	int FLAME_in_location = 0;
	int FLAME_in_format = 0;
	int FLAME_in_type = 0;
	int FLAME_in_time = 0;
	int FLAME_in_period = 0;
	int FLAME_in_phase = 0;
	int FLAME_in_name = 0;

	/* Initialise environment vars */
	FLAME_environment_variable_env_int = 0;
	FLAME_environment_variable_env_float = 0.0;
	FLAME_environment_variable_env_double = 0.0;
	FLAME_environment_variable_env_char = ' ';
	

	/* Open config file to read-only */
	if((file = fopen(filename, "r"))==NULL)
	{
		printf("Error: opening initial states '%s'\n", filename);
		exit(0);
	}
	
	/* Initialise variables */
    *itno = 0;





	if(partition_method==geometric) printf("xml: Geometric partitioning\n");
	else if(partition_method==other) printf("xml: Round-robin partitioning\n");
	else printf("xml: Error - invalid partitioning method\n");


	/* Set p_xmachine to the agent list passed in then new agents are added to this list
	 * Will be set to agent list for specific node is space partitions are already known (flag=1)
	 */
	/* If we're reading without knowing partitions already then use the dummy current node (it's not in the list of nodes)*/
	if (flag == 0) current_node = &temp_node;

	printf("Reading initial data file: %s\n", filename);
	/* Read file until end of xml */
	while(reading==1)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);

		/* If the end of a tag */
		if(c == '>')
		{
			/* Place 0 at end of buffer to make chars a string */
			buffer[i] = 0;

			if(strcmp(buffer, "states") == 0) reading = 1;
			if(strcmp(buffer, "/states") == 0) reading = 0;
			if(strcmp(buffer, "itno") == 0) in_itno = 1;
			if(strcmp(buffer, "/itno") == 0) in_itno = 0;
			if(strcmp(buffer, "imports") == 0) FLAME_in_imports = 1;
			if(strcmp(buffer, "/imports") == 0) FLAME_in_imports = 0;
			if(strcmp(buffer, "import") == 0)
			{
				/*FLAME_location[0] = '\0';*/
				strcpy(FLAME_location, filelocation);
				FLAME_format[0] = '\0';
				FLAME_type[0] = '\0';

				FLAME_in_import = 1;
			}
			if(strcmp(buffer, "/import") == 0)
			{
				if(strcmp("agent", FLAME_type) == 0 || strcmp("environment", FLAME_type) == 0)
				{
					if(strcmp("xml", FLAME_format) == 0)
					{
						if(strcmp("agent", FLAME_type) == 0) readAgentXML(FLAME_location, cloud_data, partition_method, flag, number_partitions, agent_count, itno);
						if(strcmp("environment", FLAME_type) == 0) readEnvironmentXML(FLAME_location);
					}
					else
					{
						printf("Error: import format '%s' is unsupported\n", FLAME_format);
						exit(0);
					}
				}
				else
				{
					printf("Error: import type '%s' is not agent or environment\n", FLAME_type);
					exit(0);
				}

				FLAME_in_import = 0;
			}
			if(strcmp(buffer, "location") == 0) FLAME_in_location = 1;
			if(strcmp(buffer, "/location") == 0) FLAME_in_location = 0;
			if(strcmp(buffer, "format") == 0) FLAME_in_format = 1;
			if(strcmp(buffer, "/format") == 0) FLAME_in_format = 0;
			if(strcmp(buffer, "type") == 0) FLAME_in_type = 1;
			if(strcmp(buffer, "/type") == 0) FLAME_in_type = 0;
			if(strcmp(buffer, "outputs") == 0) FLAME_in_outputs = 1;
			if(strcmp(buffer, "/outputs") == 0) FLAME_in_outputs = 0;
			if(strcmp(buffer, "output") == 0)
			{
				if(FLAME_in_outputs == 1)
				{
					current_FLAME_output = add_FLAME_output(&FLAME_outputs);
	
					FLAME_in_output = 1;
				}
			}
			if(strcmp(buffer, "/output") == 0)
			{
				if(FLAME_in_outputs == 1)
				{
					if(current_FLAME_output->type == -1)
					{
						printf("Error: an output type has not been set\n");
						exit(0);
					}
					if(current_FLAME_output->format == -1)
					{
						printf("Error: an output format has not been set\n");
						exit(0);
					}
					if(current_FLAME_output->location == NULL)
					{
						printf("Error: an output location has not been set\n");
						exit(0);
					}
					/* If type is xml check if location exists */
					if(current_FLAME_output->type == 0)
					{
						rc = check_location_exists(current_FLAME_output->location);
						if(rc == 0)
						{
							printf("Error: location directory '%s' does not exist\n", current_FLAME_output->location);
							exit(0);
						}
					}
					/* Period has to be larger than 0 */
					if(current_FLAME_output->period < 1)
					{
						printf("Error: output period is less than 1: '%d'\n", current_FLAME_output->period);
						exit(0);
					}
					/* Phase cannot be equal or larger than period */
					if(current_FLAME_output->phase >= current_FLAME_output->period)
					{
						printf("Error: output phase is more or equal to period: '%d'\n", current_FLAME_output->phase);
						exit(0);
					}
	
					FLAME_in_output = 0;
				}
			}
			if(strcmp(buffer, "time") == 0) FLAME_in_time = 1;
			if(strcmp(buffer, "/time") == 0) FLAME_in_time = 0;
			if(strcmp(buffer, "period") == 0) FLAME_in_period = 1;
			if(strcmp(buffer, "/period") == 0) FLAME_in_period = 0;
			if(strcmp(buffer, "phase") == 0) FLAME_in_phase = 1;
			if(strcmp(buffer, "/phase") == 0) FLAME_in_phase = 0;
			if(strcmp(buffer, "name") == 0) FLAME_in_name = 1;
			if(strcmp(buffer, "/name") == 0) FLAME_in_name = 0;

			/* End of tag and reset buffer */
			in_tag = 0;
			i = 0;
		}
		/* If start of tag */
		else if(c == '<')
		{
			/* Place /0 at end of buffer to end numbers */
			buffer[i] = 0;
			/* Flag in tag */
			in_tag = 1;

			if(in_itno) *itno = atoi(buffer);
			if(FLAME_in_imports == 1)
			{
				if(FLAME_in_import == 1)
				{
					if(FLAME_in_location == 1) strcat(FLAME_location, buffer);
					if(FLAME_in_format == 1) strcpy(FLAME_format, buffer);
					if(FLAME_in_type == 1) strcpy(FLAME_type, buffer);
				}
			}
			if(FLAME_in_outputs == 1)
			{
				if(FLAME_in_output == 1)
				{
					if(FLAME_in_type == 1)
					{
						if(strcmp("snapshot", buffer) == 0) current_FLAME_output->type = 0;
						else if(strcmp("agent", buffer) != 0)
						{
							printf("Error: output type is not 'snapshot' or an 'agent': '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_name == 1)
					{
						if(strcmp("agent_a", buffer) == 0) current_FLAME_output->type = 1;
						else if(strcmp("agent_b", buffer) == 0) current_FLAME_output->type = 2;
						else 
						{
							printf("Error: output name is not an agent name: '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_format == 1)
					{
						if(strcmp("xml", buffer) == 0) current_FLAME_output->format = 0;
						else
						{
							printf("Error: output format is unsupported: '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_location == 1)
					{
						current_FLAME_output->location = (char *)malloc( (strlen(filelocation) + strlen(buffer) + 1) * sizeof(char));
						strcpy(current_FLAME_output->location, filelocation);
						strcat(current_FLAME_output->location, buffer);
					}
					if(FLAME_in_time == 1)
					{
						if(FLAME_in_period == 1) current_FLAME_output->period = atoi(buffer);
						if(FLAME_in_phase == 1)  current_FLAME_output->phase = atoi(buffer);
					}
				}
			}
			/* Reset buffer */
			i = 0;
		}
		/* If in tag put read char into buffer */
		else if(in_tag == 1)
		{
			buffer[i] = c;
			i++;
		}
		/* If in data read char into buffer */
		else
		{
			buffer[i] = c;
			i++;
		}
	}

	/* Close the file */
	(void)fclose(file);

	/* Also try and read environment and agents from 0.xml */
	readEnvironmentXML(filename);
	readAgentXML(filename, cloud_data, partition_method, flag, number_partitions, agent_count, itno);

	/* If outputs is empty add default snapshot for every iteration */
	if(FLAME_outputs == NULL)
	{
		current_FLAME_output = add_FLAME_output(&FLAME_outputs);
		current_FLAME_output->type   = 0; /* snapshot */
		current_FLAME_output->format = 0; /* xml */
		current_FLAME_output->location = (char *)malloc( (strlen(filelocation) +  1) * sizeof(char));
		strcpy(current_FLAME_output->location, filelocation); /* location = 0.xml location */
		current_FLAME_output->period = 1; /* every iteration */
		current_FLAME_output->phase  = 0; /* no phase */
	}
	
	/* Print output settings to CLI */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		printf("output: type='");
		if(current_FLAME_output->type == 0) printf("snapshot");
		else if(current_FLAME_output->type == 1) printf("agent' name='agent_a");
		else if(current_FLAME_output->type == 2) printf("agent' name='agent_b");
		else printf("undefined");
		printf("' format='");
		if(current_FLAME_output->format == 0) printf("xml");
		else printf("undefined");
		printf("' location='%s'", current_FLAME_output->location);
		printf(" period='%d' phase='%d'\n", current_FLAME_output->period, current_FLAME_output->phase);
	}

	/* Make sure cloud data makes sense if any of x,y,z coords were all the same */
	if ( partition_method == geometric ) {
		if ( cloud_data[0] == cloud_data[1] ) {
			cloud_data[0] = -SPINF;
			cloud_data[1] = SPINF;
		}
		if ( cloud_data[2] == cloud_data[3] ) {
			cloud_data[2] = -SPINF;
			cloud_data[3] = SPINF;
		}
		if ( cloud_data[4] == cloud_data[5] ) {
			cloud_data[4] = -SPINF;
			cloud_data[5] = SPINF;
		}
	}
}

/** \fn void write_int_static_array(FILE *file, $name * temp)
 * \brief Writes int.
 */
void write_int_static_array(FILE *file, int * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%i", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_static_array(FILE *file, float * temp)
 * \brief Writes float.
 */
void write_float_static_array(FILE *file, float * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_static_array(FILE *file, double * temp)
 * \brief Writes double.
 */
void write_double_static_array(FILE *file, double * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_static_array(FILE *file, char * temp)
 * \brief Writes char.
 */
void write_char_static_array(FILE *file, char * temp, int size)
{
	int i;
	char data[1000];

	//fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%c", temp[i]);
		fputs(data, file);
		//if(i < size-1) fputs(", ", file);
	}
	//fputs("}", file);
}

/** \fn void write_int_dynamic_array(FILE *file, int_array* temp)
 * \brief Writes int.
 */
void write_int_dynamic_array(FILE *file, int_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%i", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_dynamic_array(FILE *file, float_array* temp)
 * \brief Writes float.
 */
void write_float_dynamic_array(FILE *file, float_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_dynamic_array(FILE *file, double_array* temp)
 * \brief Writes double.
 */
void write_double_dynamic_array(FILE *file, double_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_dynamic_array(FILE *file, char_array* temp)
 * \brief Writes char.
 */
void write_char_dynamic_array(FILE *file, char_array * temp)
{
	int i;
	char data[1000];

	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%c", (*temp).array[i]);
		fputs(data, file);
	}
}

/** \fn void write_my_datatype_1(FILE *file, my_datatype_1 * temp_datatype)
 * \brief Writes my_datatype_1 datatype.
 */
void write_my_datatype_1(FILE *file, my_datatype_1 * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).type);
	fputs(data, file);
	fputs("}", file);
}

void write_my_datatype_1_static_array(FILE *file, my_datatype_1 * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_my_datatype_1(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_my_datatype_1_dynamic_array(FILE *file, my_datatype_1_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_my_datatype_1(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_my_datatype_2(FILE *file, my_datatype_2 * temp_datatype)
 * \brief Writes my_datatype_2 datatype.
 */
void write_my_datatype_2(FILE *file, my_datatype_2 * temp_datatype)
{
	

	fputs("{", file);
	write_int_static_array(file, (*temp_datatype).int_list, 2);
	fputs(", ", file);	write_my_datatype_1_static_array(file, (*temp_datatype).var_my_datatype_1_list, 2);
	fputs(", ", file);	write_my_datatype_1(file, &(*temp_datatype).var_my_datatype_1);
	fputs("}", file);
}

void write_my_datatype_2_static_array(FILE *file, my_datatype_2 * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_my_datatype_2(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_my_datatype_2_dynamic_array(FILE *file, my_datatype_2_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_my_datatype_2(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_my_datatype_3(FILE *file, my_datatype_3 * temp_datatype)
 * \brief Writes my_datatype_3 datatype.
 */
void write_my_datatype_3(FILE *file, my_datatype_3 * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).int_single);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).float_single);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).double_single);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%c", (*temp_datatype).char_single);
	fputs(data, file);
	fputs(", ", file);	write_int_static_array(file, (*temp_datatype).int_list, 2);
	fputs(", ", file);	write_float_static_array(file, (*temp_datatype).float_list, 2);
	fputs(", ", file);	write_double_static_array(file, (*temp_datatype).double_list, 2);
	fputs(", ", file);	write_char_static_array(file, (*temp_datatype).char_list, 2);
	fputs(", ", file);	write_int_dynamic_array(file, &(*temp_datatype).int_dynamic_list);
	fputs(", ", file);	write_float_dynamic_array(file, &(*temp_datatype).float_dynamic_list);
	fputs(", ", file);	write_double_dynamic_array(file, &(*temp_datatype).double_dynamic_list);
	fputs(", ", file);	write_char_dynamic_array(file, &(*temp_datatype).char_dynamic_list);
	fputs("}", file);
}

void write_my_datatype_3_static_array(FILE *file, my_datatype_3 * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_my_datatype_3(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_my_datatype_3_dynamic_array(FILE *file, my_datatype_3_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_my_datatype_3(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_data_type_sales(FILE *file, data_type_sales * temp_datatype)
 * \brief Writes data_type_sales datatype.
 */
void write_data_type_sales(FILE *file, data_type_sales * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).period);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).sales);
	fputs(data, file);
	fputs("}", file);
}

void write_data_type_sales_static_array(FILE *file, data_type_sales * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_data_type_sales(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_data_type_sales_dynamic_array(FILE *file, data_type_sales_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_data_type_sales(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_sales_statistics(FILE *file, sales_statistics * temp_datatype)
 * \brief Writes sales_statistics datatype.
 */
void write_sales_statistics(FILE *file, sales_statistics * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).mall_id);
	fputs(data, file);
	fputs(", ", file);	write_data_type_sales_dynamic_array(file, &(*temp_datatype).sales);
	fputs("}", file);
}

void write_sales_statistics_static_array(FILE *file, sales_statistics * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_sales_statistics(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_sales_statistics_dynamic_array(FILE *file, sales_statistics_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_sales_statistics(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}



void write_agent_a_agent(FILE *file, xmachine_memory_agent_a * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>agent_a</name>\n", file);
		fputs("<int_single>", file);
	sprintf(data, "%i", current->int_single);
	fputs(data, file);
	fputs("</int_single>\n", file);
		fputs("<int_single_2>", file);
	sprintf(data, "%i", current->int_single_2);
	fputs(data, file);
	fputs("</int_single_2>\n", file);
		fputs("<float_single>", file);
	sprintf(data, "%f", current->float_single);
	fputs(data, file);
	fputs("</float_single>\n", file);
		fputs("<double_single>", file);
	sprintf(data, "%f", current->double_single);
	fputs(data, file);
	fputs("</double_single>\n", file);
		fputs("<char_single>", file);
	sprintf(data, "%c", current->char_single);
	fputs(data, file);
	fputs("</char_single>\n", file);
		fputs("<int_list>", file);
	write_int_static_array(file, current->int_list, 2);
	fputs("</int_list>\n", file);
		fputs("<float_list>", file);
	write_float_static_array(file, current->float_list, 2);
	fputs("</float_list>\n", file);
		fputs("<double_list>", file);
	write_double_static_array(file, current->double_list, 2);
	fputs("</double_list>\n", file);
		fputs("<char_list>", file);
	write_char_static_array(file, current->char_list, 2);
	fputs("</char_list>\n", file);

	fputs("</xagent>\n", file);
}

void write_agent_b_agent(FILE *file, xmachine_memory_agent_b * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>agent_b</name>\n", file);
		fputs("<int_single>", file);
	sprintf(data, "%i", current->int_single);
	fputs(data, file);
	fputs("</int_single>\n", file);

	fputs("</xagent>\n", file);
}


void FLAME_write_xml(char * location, int iteration_number, int * output_types, int output_type_size)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];
	
		sprintf(data, "%s%i.xml", location, iteration_number);
	
	if((file = fopen(data, "w"))==NULL)
	{
		printf("Error: cannot open file '%s' for writing\n", data);
		exit(0);
	}
	
	
	fputs("<states>\n", file);
	if(FLAME_integer_in_array(0, output_types, output_type_size))
	{
		fputs("<itno>", file);
		sprintf(data, "%i", iteration_number);
		fputs(data, file);
		fputs("</itno>\n", file);
		fputs("<environment>\n" , file);
			fputs("<env_int>", file);
		sprintf(data, "%i", FLAME_environment_variable_env_int);
		fputs(data, file);
		fputs("</env_int>\n", file);
			fputs("<env_float>", file);
		sprintf(data, "%f", FLAME_environment_variable_env_float);
		fputs(data, file);
		fputs("</env_float>\n", file);
			fputs("<env_double>", file);
		sprintf(data, "%f", FLAME_environment_variable_env_double);
		fputs(data, file);
		fputs("</env_double>\n", file);
			fputs("<env_char>", file);
		sprintf(data, "%c", FLAME_environment_variable_env_char);
		fputs(data, file);
		fputs("</env_char>\n", file);
			fputs("</environment>\n" , file);
	}
	
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(1, output_types, output_type_size))
	{
		current_xmachine_agent_a_holder = agent_a_start_state->agents;
			while(current_xmachine_agent_a_holder)
			{
				write_agent_a_agent(file, current_xmachine_agent_a_holder->agent);

				current_xmachine_agent_a_holder = current_xmachine_agent_a_holder->next;
			}
	}
	
	if(FLAME_integer_in_array(0, output_types, output_type_size) || FLAME_integer_in_array(2, output_types, output_type_size))
	{
		current_xmachine_agent_b_holder = agent_b_start_state->agents;
			while(current_xmachine_agent_b_holder)
			{
				write_agent_b_agent(file, current_xmachine_agent_b_holder->agent);

				current_xmachine_agent_b_holder = current_xmachine_agent_b_holder->next;
			}
	}
	
	fputs("</states>\n" , file);

	/* Close the file */
	(void)fclose(file);
}

/** \fn void saveiterationdata(int iteration_number)
 * \brief Save X-machine memory to a file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata(int iteration_number)
{
	FLAME_output * current_FLAME_output;
	FLAME_output * current_FLAME_output2;
	int output_types[1000];
	int output_type_size = 0;

	/* For each output */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		/* If period/phase equates to current iteration */
		if(iteration_number%current_FLAME_output->period == current_FLAME_output->phase)
		{
			/* If output has already been handled */
			if(current_FLAME_output->flag == 0)
			{
				/* Check snapshot */
				if(current_FLAME_output->type == 0)
				{
					//snapshot_location = current_FLAME_output->location;
					output_types[0] = 0;
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, 1);
					/* Set flag to 1 and every output to same location */
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							current_FLAME_output2->flag = 1;
						}
					}
				}
				if(current_FLAME_output->type == 1)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 1;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}if(current_FLAME_output->type == 2)
				{
					/* Reinitialise agent size */
					output_type_size = 0;
					output_types[0] = 2;
					
					current_FLAME_output->flag = 1;
					for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
					{
						if(current_FLAME_output2->flag == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
						{
							output_types[++output_type_size] = current_FLAME_output2->type;
							
							current_FLAME_output2->flag = 1;
						}
					}
					
					FLAME_write_xml(current_FLAME_output->location, iteration_number, output_types, output_type_size);
				}
			}
		}
	}
	/* Set flags back to 0 */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		current_FLAME_output->flag = 0;
	}
}
