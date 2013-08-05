/*******************************************************************************
*
*  FILE NAME    : change_position.c
*
*  DESCRIPTION: It takes in an array of size N and N integer parameters which 
*  specify the new positions of the elements in the array which are passed to 
*  the function which in turn return the new array.
*
*  DATE    NAME    REFERENCE    REASON
*
*   8-MAR-08  Sibu    C FG 1.0           Initial creation
*  
*   2007,  Technologies (Holdings) Ltd
*
*******************************************************************************/
#include<stdio.h>
/*******************************************************************************
*
* FUNCTION NAME: change_position
*
* DESCRIPTION: Changes the positions of the array elements.
*
* RETURNS: Returns a pointer of the changed array
*******************************************************************************/

int* change_position(int *array_ptr,int *pos_array,int array_num)
{
        int *temp_array;
        temp_array=(int *)malloc(array_num*sizeof(int*));
        int j;
        int k=0;
        for(j=0;j<array_num;j++)
        {
                k=*(pos_array+j);
                *(temp_array+k)=*(array_ptr+j);
        }
        return temp_array;
}
/*******************************************************************************
*
* FUNCTION NAME: main
*
* DESCRIPTION: Takes an array of size N and N integer parameters which specify the new positions of the elements.
*
* RETURNS: Returns 0
*******************************************************************************/

int main()
{
        int i;
        int array_num;
        int array_elements[5];
        int new_position[5];
        int *ptr_array;
	printf("Enter the number of elements in the array");
        scanf("%d",&array_num);
        printf("Enter the elements of the array\n");
        for(i=0;i<array_num;i++)
        {
                scanf("%d",&array_elements[i]);
        }
        printf("\n Enter the new positions of the array elements ");
        for(i=0;i<array_num;i++)
        {
              scanf("%d",&new_position[i]);
        }
        ptr_array=change_position(array_elements,new_position,array_num);
        printf("\n The array with changed positions is\n");
        for(i=0;i<array_num;i++)
        {
         printf("\n%d\t",*(ptr_array+i));
        }
        printf("\n");
	return 0;
}

