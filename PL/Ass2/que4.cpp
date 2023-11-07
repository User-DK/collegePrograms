#include <iostream>
#include <string>
using namespace std;

class Operations{
    public:
    int operate(int a,int b){
        return a+b;
    }

    double operate(double a,double b){
        return a*b;
    }

    string operate(string a, string b){
        return a+b;
    }
};

int main(){
    cout<<"Welcome!\n";
    char choice;
    Operations toOperate;
    while(true){
        cout<<"\nEnter the Operation to be performed:\na.Add Two Numbers\nb.Product of Two Numbers\nc.Concatenate Two String\nd.Exit\n";
        cin>>choice;
    switch(choice){
        case 'a':{int a,b;
        cout<<"\nEnter two Numbers:\na=";
        cin>>a;
        cout<<"\nb=";cin>>b;
        cout<<"\na+b="<<toOperate.operate(a,b);
        break;}

        case 'b':{double c,d;
        cout<<"\nEnter two Numbers:\na=";
        cin>>c;
        cout<<"\nb=";cin>>d;
        cout<<"\na*b="<<toOperate.operate(c,d);
        break;}

        case 'c':{
        string e,f;
        cout<<"\nEnter two Strings:\na=";
        cin>>e;
        cout<<"\nb=";cin>>f;
        cout<<"\nThe concatenated String is:"<<toOperate.operate(e,f);
        break;}

        case 'd':{return false;
        break;}

        default:{cout<<"Wrong Option";
        break;}
    }
       
    }return 0;
    
    
}