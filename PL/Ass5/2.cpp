//You are developing software for a robotic company. The company manufactures ground robots and drones. Each type of robot has different components. Your task is to define nested namespaces that categorize these robots and their components.

#include <iostream>
using namespace std;

namespace ground_robots
{
       void fnx()
  {
    cout<< "Inside  robots" <<endl;
  }
  namespace robots_components
  {
    class part
    {
    public:
      void fnx()
      {
        cout<< "Inside the parts of robots" <<endl;
      }
          };

  }
}

namespace drones
{

  void fnx()
  {
    cout<< "Inside drones" <<endl;
  }

  namespace drones_components
  {
    class part
          {
    public:
      void fnx()
      {
        cout<< "Inside the parts of drones" <<endl;
      }
    };
  }
}

int main()
{
  ground_robots::robots_components::part obj;
  obj.fnx();
  drones::drones_components::part obj1;
  obj1.fnx();
  return 0;
}

