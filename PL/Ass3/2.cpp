#include <iostream>
using namespace std;

class Counter{
    private:
    int value;
    public:
    Counter(int val):value(val){}

    Counter operator --(){
        return --value;

    }
    Counter operator ++(){
        return ++value;
    }
    

    Counter operator --(int){
        return value--;
    }
    Counter operator ++(int){
        return value++;
    }
    
    void display(){
        cout<<value<<endl;
    }
};

int main(){
    Counter vall1(10);
    // Counter
    Counter vall3=--vall1;
    vall3.display();
    vall3=++vall1;
    vall3.display();
    vall3=vall1--;
    vall3.display();
    vall3=vall1++;
    vall3.display();
}