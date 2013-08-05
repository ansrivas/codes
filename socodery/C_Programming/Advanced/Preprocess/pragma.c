//#pragma directory...
//#include <stdio.h>
#if _M_IX86 != 500
#pragma message("Non Pentium processor build")
#endif
#if _M_IX86 == 600
#pragma message("but Pentium II above processor build")
#endif
#pragma message("Compiling " __FILE__)
#pragma message("Last modified on " __TIMESTAMP__)
int main()
{
return 0;
}

