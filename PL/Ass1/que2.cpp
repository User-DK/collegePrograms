#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    string EmpID;
    string Name;
    string Address;
    string Designation;
    vector<int> Salary; 

    int average() {
        int sum = 0;
        for (auto i : this->Salary) {
            sum += i;
        }
        return sum / 5; 
    }
};

int main() {
    Employee e;
    cout << "Hello, Employee.. Please ENTER your details:" << endl;
    cout << "EmpID: ";
    cin >> e.EmpID;
    cout << "\nName: ";
    cin >> e.Name;
    cout << "\nAddress: ";
    cin >> e.Address;
    cout << "\nDesignation: ";
    cin >> e.Designation;

    cout << "\nEnter Last Five years Salary: ";
    for (int i = 0; i < 5; ++i) {  
        int salary;
        cin >> salary;
        e.Salary.push_back(salary);
    }
    
    cout << "\nYour average Salary for the Five years is: " << e.average();

    return 0;
}
