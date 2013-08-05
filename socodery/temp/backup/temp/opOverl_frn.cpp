#include <iostream.h>
using namespace std;

     class myclass
     {
       int a;
       int b;

    public:
      myclass(){}
      myclass(int x,int y){a=x;b=y;}
      void show()
      {
        cout<<a<<endl<<b<<endl;
      }

     friend myclass operator=(myclass);
    };

   /* myclass myclass::operator=()
    {
      myclass t;
t.a=a;
t.b=b;
      return t;
    }*/

    myclass operator=( myclass t)
    {
        myclass x;
        x.a=t.a;
        x.b=t.b;
        return x;
    }


    int main()
    {
      myclass a(10,20);
      myclass b,c;

      //c=b=a;
      b=a;
      c=b;
      c.show();
       return 0;
    }
