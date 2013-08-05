/*************************************************************************
*
*  FILE NAME    : name_det_header.h
*
*  DESCRIPTION  : Contains header files, function prototypes and user
*		  defined variables for name details program
*
*  DATE      NAME    REFERENCE          REASON
*
*  1-JUN-10  Sibu    PRISM-3 C FG       Initial Creation.
*
*   2010,  Technologies (Holdings) Ltd
*
**************************************************************************/

/* Avoiding multiple inclusions of header file */
#ifndef NAME_DET__HEADER_H
  #define NAME_DET_HEADER_H

/*******************************************************************************
*                       HEADER FILES
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************************************************
*                      MACROS 
*******************************************************************************/
#define MAX 32
#define name_ret int
#define FAILURE 0
#define SUCCESS 1

/*******************************************************************************
*                      USER DEFINED TYPES
*******************************************************************************/
typedef struct
{
 char *first_name;
 char *second_name;
}person_name_et;

/*******************************************************************************
*                      FUCNTION PROTOTYPES
*******************************************************************************/
extern name_ret update_person(person_name_et **, char *, char *);
extern name_ret display_person(person_name_et *[], int);
extern name_ret free_person(person_name_et *[],int);

#endif


