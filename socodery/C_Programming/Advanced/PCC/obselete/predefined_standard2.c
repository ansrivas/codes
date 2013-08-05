int main()
{
#if defined(__STDC__)
# define PREDEF_STANDARD_C_1989
   printf("\nC_89");
# if defined(__STDC_VERSION__)
#  define PREDEF_STANDARD_C_1990
    printf("\nC_90");
#  if (__STDC_VERSION__ >= 199409L)
#   define PREDEF_STANDARD_C_1994
    printf("\nC_94");
#  endif
#  if (__STDC_VERSION__ >= 199901L)
#   define PREDEF_STANDARD_C_1999
    printf("\nC_94");
#  endif
# endif
#endif
}

