//You have to design a basic system where different animals make sounds. The base class Animal will have a function makeSound(), which should be overridden by derived classes to make specific sounds.

#include<iostream>
using namespace std;
class Animal
{
public:
    virtual void makeSound(){
      cout<<"WE ARE ABLE TO CREATE VARIOUS SOUND OF ANIMAL"<<endl;
    }
};

class CAT:public Animal{
  public:
   void makeSound() override{
      cout<<"CAT SOUND IS MEOW"<<endl;
   }
};
class HORSE:public Animal{
  public:
   void makeSound() override{
     cout<<"HORSE SOUND IS KNEE"<<endl;
   }
};
class GORILLA:public Animal{
  public:
   void makeSound() override{
     cout<<"GORILLA SOUND IS GRUNT"<<endl;
   }
};

int main(){
 Animal* gorilla_s=new GORILLA();
 gorilla_s->makeSound();
 delete gorilla_s;
 Animal x;
 x.makeSound();
 return 0;

}
