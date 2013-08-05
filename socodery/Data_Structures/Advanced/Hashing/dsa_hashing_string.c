/******************************************************************************
keywords                :       dsa, hashing, collision

File Name               :       dsa_hashing_collision.c

Date of Creation        :       23/07/2007

Owner                   :       Sibu Cyriac

Date of Modification    :

Reason for modification :

Modifier                :

*******************************************************************************/

#include<stdio.h>
int hash(char *str, int table_size)
{
	int sum=0;

	/* Make sure a valid string passed in */
	if (str==NULL) return -1;


	/* Sum up all the characters in the string */
	for( ; *str; str++) sum += *str;
	printf("%d\n",sum);
	/* Return the sum mod the table size */
	return sum % table_size;
}

int main()
{
	int temp = hash("I hate you",10);
	
	printf("%d\n",temp);
}
