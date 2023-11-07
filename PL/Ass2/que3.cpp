#include <iostream>
#include <string>
using namespace std;

class Box{
    public:
    int height, width, length;
    Box():height(0), width(0), length(0){}
    
    Box(int x, int y, int z):height(x), width(y), length(z){}
    
    Box(const Box& x):height(x.height),width(x.width),length(x.length) {}
    
    ~Box(){std::cout << "Destructor called for Box(" << height << ", " << width << ", " << length << ")" << std::endl;}
    
    void display() {
        std::cout << "Box dimensions: " << height << " x " << width << " x " << length << std::endl;
    }

};

int main(){
    Box box1;
    Box box2(1,2,3);
    Box box3=box2;
     box1.display();
    box2.display();
    box3.display();
    return 0;
}