/*************************************************************************
*
*  FILE NAME    : cond_comp.c
*
*  DESCRIPTION  : Program to demonstrate conditional compilation
*
*  DATE    NAME    REFERENCE          REASON
*
*  8-MAR-08  Sibu    C FG 1.0           Initial creation
*
*   2008,  Technologies (Holdings) Ltd
*
**************************************************************************/

#define TEST 10
 
int main(void)
{
   static int array[ ] = { 1, 2, 3, 4, 5 };
   int i=6;
 
   for (i = 0; i <= 4; i++)
   {
      array[i] *= 2;
 
#if TEST >= 1
   printf("i = %d\n", i);
   printf("array[i] = %d\n",array[i]);
#endif
 
   }
   return(0);
}











