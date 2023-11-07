#include <iostream>
#include <cmath>
using namespace std;

class Polar {
private:
  float x;
  float y;

public:
  Polar(float r, float a) : x(r * cos(a)), y(r * sin(a)) {}

  Polar operator+(Polar coor2) {
    x = x + coor2.x;
    y = y + coor2.y;
    reconversion();
  }

  void reconversion() {
    float a = atan2(y, x); // arc tangent
    float r = sqrt(x * x + y * y);
    cout<<"r="<<r<<" , a="<<a;
  }

};

int main() {
  Polar coor1(6,10), coor2(7, 20);
  Polar coor3 = coor1 + coor2;
  return 0;
}
