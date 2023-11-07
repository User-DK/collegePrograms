#include <iostream>
#include <string>
using namespace std;

class Film{
    public:
    string Name,Language,Type,Duration;
    Film(string a, string b){
        Language="Hindi";
        Duration="3hrs";
        Name=a;
        Type=b;
        display();
    }
    
    void display(){
        cout<<"\nName of the Film is: "<<Name;
        cout<<"\nLanguage of the Film is: "<<Language;
        cout<<"\nType of the Film is: " <<Type;
        cout<<"\nDuration of the Film is: "<<Duration;
}
    ~Film(){
        cout<<"\nFilm Record Deleted";
    }
};

int main(){
    cout<<"Welcome\nEnter the details as follows: \nName: ";
    string name,type;
    cin>>name;
    cout<<"\nType: ";
    cin>>type;
    Film(name,type);
    return 0;
}
    
    
