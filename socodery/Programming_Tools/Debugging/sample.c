   #include<stdio.h>
   static void display(int i, int *ptr);


   typedef struct struct_n {
	int list[5];
        char arr[4][10];
	struct struct_n *next;
   }llist;
   
   int main(void) {
      int x = 5;
      int *xptr = &x;



      printf("In main():\n");
      printf("   x is %d and is stored at %p.\n", x, &x);
      printf("   xptr points to %p which holds %d.\n", xptr, *xptr);
      display(x, xptr);


      list_data();
      return 0;
   }
   
    void display(int z, int *zptr) {
      
       *zptr = 2500;
    	printf("In display():\n");
       printf("   z is %d and is stored at %p.\n", z, &z);
       printf("   zptr points to %p which holds %d.\n", zptr, *zptr);
   }


list_data()
{
  	llist node ={
	{1,1234,43,23},
  	{"hello","new","world","123"},
	0
	};
  
	llist *nptr=&node;

     printf("\n[%d], [%s] \n\n",node.list[2],node , nptr->arr[3]);
};

