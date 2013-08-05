
int g_trace_level;

#define DETAILED_TRACE 2
#define BRIEF_TRACE    1
#define NO_TRACE       0

#define TRACE(level, x) if (level <= g_trace_level) printf x



TRACE(DEAILED_TRACE, ("value of head is %p\n", head))
TRACE(BRIEF_TRACE, ("value of head is %p\n", head))
