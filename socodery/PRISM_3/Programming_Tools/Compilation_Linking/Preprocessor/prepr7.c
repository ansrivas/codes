#define TRUE 0


int main()
{
#ifdef TRUE
   printf("TRUE");
#else
   printf ("FALSE");
#endif

#undef TRUE

#ifndef TRUE 
   printf ("FALSE");
#endif

   return 0;

}

