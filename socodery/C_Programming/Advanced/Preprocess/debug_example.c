/*************************************************************************
*
*  FILE NAME    : debug_example.c
*
*  DESCRIPTION  : Demonstration of -D option of GCC
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#ifdef C_EXPERT
 #define C_LANG    'C'
#else
 #define C_LANG     0
#endif

#ifdef JAVA_EXPERT
 #define J_LANG    'J'
#else
 #define J_LANG     0
#endif

#define NO_ERROR 1

int main(void)
{
   #if C_LANG == 'C' && J_LANG == 'J'
     printf("I know both C and JAVA.\n");
   #elif C_LANG == 'C'
     printf("I only know C language.\n");
   #elif J_LANG == 'J'
     printf("I only know JAVA.\n");
   #else
     printf("I don't know C or JAVA.\n");
   #endif

   return NO_ERROR; 
}

