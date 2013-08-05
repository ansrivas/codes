#define forever for(;;)
#define N 10

int main()
{
     int i = 0;
     forever
     {
        i++;
        if (N == i)
           break;
     }
}

