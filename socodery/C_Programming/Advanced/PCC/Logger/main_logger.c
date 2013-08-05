/**********************GLOBAL VARIABLES************************************
* FILE NAME	: main_logger.c
*
* DESCRIPTION   : Main for logger side
*
*
*  @ 2008  Inc. All Rights Reserved.
**********************************************************************/

/**************HEADER FILE DECALARATIONS************/

#include "logger.h"


/**********************************************************************
*
* FUNCTION NAME : main
*
* DESCRIPTION   : It calls the functions
*
*
* RETURN TYPE   : int
*
* PARAMETERS    : int argc, char *argv[]
*
**********************************************************************/



int main(int argc, char** argv)
{
	int err_no;


	log_level = LOG_LEVEL;
	log_max = LOG_MAX;
	strcpy(log_file,"log.txt");

	LOGGER(LOG_CRITICAL, "Start of first loop"); 	
	
	loop_function();

	LOGGER(LOG_CRITICAL, "End of first loop");
 	
	LOGGER(LOG_CRITICAL, "Start of second loop"); 	
	
	loop_function();

	LOGGER(LOG_CRITICAL, "End of second loop");
       
	return SUCCESS;
}
