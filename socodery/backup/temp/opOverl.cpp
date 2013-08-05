#include <iostream>
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

      void operator=(myclass);
      void operator-();
    };

   /* myclass myclass::operator=()
    {
      myclass t;
t.a=a;
t.b=b;
      return t;
    }*/

    void myclass::operator=(myclass t)
    {
       a=t.a;
       b=t.b;
    }

    void myclass::operator-()
    {
       a=-a;
       b=-b;
    }

    int main()
    {
      myclass a(10,20);
      myclass b,c;

      //c=b=a;
      b=a;
      b.show();
      -b;
      c=b;
      c.show();
       return 0;
    }
