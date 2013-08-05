/*******************************************************************************
*
*     FILENAME       :    header.h
*
*     DESCRIPTION    :    This file defines the macros and the array for the
*                       stack for array implementation.
*
*     Revision History    :
*     DATE        NAME                  REFERENCE            REASON
*     ----------------------------------------------------------
*     26 May 2010  Rashi Arora                          New code for the stack
*
*      @ 2010  Inc  All Rights Reserved
*
*******************************************************************************/

/********************** Header File Inclusions ********************************/
#include <stdio.h>

/********************** Macro definitions *************************************/
# define SUCCESS 1
# define FAILURE 0
# define STACKSIZE 5

/********************** Global Variables **********************************/
int items[STACKSIZE];
int top;

/********************** Function Declaration **********************************/
int isempty();
int overflow();
void push(int value);
int pop();
void display();
