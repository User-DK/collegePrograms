//You are provided with two libraries. Both libraries have a class called LibraryClass and both have a function called show(). Your task is to utilize both of these classes in a main program without any naming conflicts.

#include <iostream>
using namespace std;
namespace libraryX
{
  class LibraryClass
  {
  public:
    void show()
   {
     cout<< "show() FNX : LIBRARY X" <<endl;
    }
  };

};

namespace libraryY
{
  class LibraryClass
  {
  public:
   void show()
   {
      cout<< "show() FNX : LIBRARY Y" <<endl;
    }
  };

};
int main()
{
  libraryX::LibraryClass X;
  libraryY::LibraryClass Y;
  X.show();
  Y.show();
        return 0;
}
