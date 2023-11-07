//. You are to design a system where different shapes calculate their areas. The base class Shape will have a function area(), which should be overridden by derived classes to calculate specific areas.

#include <iostream>
#include <cmath>
using namespace std;
class shape
{
public:
    virtual void area(int data)
    {
        cout<< "We can calculate Area of any shape" <<endl;
    }
};
class circle : public shape
{
public:
     void area(int data) override
    {   
        cout<<endl;
        cout<< "CIRCLE AREA : pi*radius*radius = " <<round(data*data*M_PI)<<endl;
        cout<<endl;

    }
};

class square : public shape
{
public:
     void area(int data) override
    {   
        cout<<endl;
        cout<< "SQUARE AREA : side * side = "<<round(data*data)<<endl;
        cout<<endl;
    }
};



int main()
{ 
  shape*circle_a=new circle();
  circle_a->area(5);
  delete circle_a;

  shape *square1=new square();
  square1->area(5);
  delete square1;

    return 0;
}

