#include <iostream>
using namespace std;

// Class to represent a box
class Box
{
  public:
    double length;
    double breadth;
    double height;

    // Constructor
    Box(double lengthValue, double breadthValue, double heightValue)
    {
      cout << "Box constructor called" << endl;
      length = lengthValue;
      breadth = breadthValue;
      height = heightValue;
    }

    // Function to calculate the volume of a box
    double volume()
    {
      return length * breadth * height;
    }
};

int main()
{
   Box box1(10.00, 20.00, 30.00);
   double boxVol = box1.volume();
   cout << "volume of box = " << boxVol << endl;
   return 0;
}
