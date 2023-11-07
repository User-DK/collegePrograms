#include <iostream>

using namespace std;

class Student{
    private:
    int rollNumber;
    string name;
    double marks[3];
    double average;
    
    public:
    void Setstudent(){
        getRollNumber();
        getName();
        getMarks();
        calculateAverage(marks);
        calculateGrade(average);
        }

    int getRollNumber(){
        cout<<"\nEnter Roll Number: ";
        cin>>rollNumber;
    }

    string getName(){
        cout<<"\nEnter Name: ";
        cin>>name;
    }

    double getMarks(){
        for(int i=0;i<3;i++){
            cout<<"\nEnter Marks for "<<i+1<<" subjects: ";
            cin>>marks[i];
            }
        }

    double calculateAverage(double *marks1){
        double sum=0;
        for(int i=0;i<3;i++){
            sum+=marks1[i];
            }
        average=sum/3;
        cout<<"\nYour Average Marks for the three subjects is: "<<average;
    }

    double calculateGrade(double avg){
        if(avg>=90){
            cout<<"\nCongratulations,You have got Grade  A";
        }
        else if(avg>=80 && avg<=89){
            cout<<"\nCongratulations,You have got Grade  B";
        }
        else if(avg>=70 && avg<=79){
            cout<<"\nCongratulations,You have got Grade  C";
        }
        else if(avg>=60 && avg<=59){
            cout<<"\nCongratulations,You have got Grade  D";
        }
        else if(avg>=40 && avg<=49){
            cout<<"\nCongratulations,You have got Grade  E";
        }
        else{
            cout<<"\nSorry, You have failed"; 
        }
    }

};

int main(){
    cout<<"Welcome to the Result Generation System";
    cout<<"\nPlease enter the number of students who want to see the result: ";
    int number;
    cin>>number;
    Student* students = new Student[number];

    for (int i = 0; i < number; i++) {
        students[i].Setstudent();
        cout<<"\n Thank you";
    }

    return 0;
}