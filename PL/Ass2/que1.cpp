#include <iostream>
#include <string>
using namespace std;

class Date{
    private:
        int date,month,year;
    public:
        Date(){
            date=1;
            month=1;
            year=1970;
            Display();
        }
        Date(int x, int y, int z){
            date=x;
            month=y;
            year=z;
            Display();
        }
        void Display(){
            cout<<"\nDate is:  ";
            string a=date/10==0?"0"+to_string(date):to_string(date);
            string b=month/10==0?"0"+to_string(month):to_string(month);
            cout<<a<<"/"<<b<<"/"<<year;
        }
};

int main(){
    cout<<"Select any one option:\na.Display a Default date\nb.Enter a Date(day month year)\n";
    char A;
    cin>>A;
    switch(A){
        case 'a':Date();cout<<"\nThankYou";
        break;
        case 'b':int x,y,z;
        cout<<"\nDate:";
        cin>>x;cout<<"\nMonth:";cin>>y;cout<<"\nYear:";cin>>z;Date(x,y,z);
        break;
        default:cout<<"Wrong Option";
        
    }return 0;
}
