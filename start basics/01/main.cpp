#include <iostream>

using namespace std;

class Rectangle
{
private: //using private means these variables/functions are private which is default behaviour of class in c++
      int length = 0;
      int breadth = 0;

public: //using public means all the variables/functions under this is public to outside
      //Constructor Function
      Rectangle(int l, int b)
      {
            length = l;
            breadth = b;
      };
      //mutator function (setter function)
      void setLength(int l)
      {
            length = l;
      }
      void setBreadth(int b)
      {
            breadth = b;
      }

      //Accessor function (getter function)
      int getlength()
      {
            return length;
      }

      //facilitator functions
      int area()
      {
            return length * breadth;
      }
      int perimeter()
      {
            return 2 * (length + breadth);
      }

      // destructor function
      ~Rectangle()
      {
            //code to deallocation if heap memory is used
            //this function runs at the end of program execution
      }
};

int main()
{
      Rectangle r(10, 3);
      int l = 0, b = 0;
      cout << "area =" << r.area() << endl;
      cout << "perimeter =" << r.perimeter() << endl;
      cout << "Input the length: ";
      cin >> l;
      r.setLength(l);
      cout << "new area = " << r.area() << endl;
      cout << "new perimeter =" << r.perimeter() << endl;
      return 0;
}
