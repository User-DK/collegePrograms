#include <stdio.h>
#include <string.h>

struct student{
    char name[50];
    int roll;
    float cgpa;
};

int main(){
    int n;
    printf("Welcome\nEnter the number of students: ");
    scanf("%d", &n);  // Added '&' before 'n'
    struct student s[n];
    float smallest = 10;
    int flags = 0;
    float largest = 0;
    int flagl = 0;

    for(int i = 0; i < n; i++){
        printf("\nEnter the Following details for student %d", i+1);
        printf("\nName: ");
        scanf("%s", s[i].name);
        printf("Roll: ");
        scanf("%d", &s[i].roll);  // Added '&' before 's[i].roll'
        printf("CGPA: ");
        scanf("%f", &s[i].cgpa);  // Added '&' before 's[i].cgpa'
        if(largest < s[i].cgpa){
            largest = s[i].cgpa;
            flagl = i;
        }
        if(smallest > s[i].cgpa){
            smallest = s[i].cgpa;
            flags = i;
        }
    }

    printf("\nThe student with the Highest Marks is:\nName: %s\nRoll: %d\nCGPA: %.2f",
           s[flagl].name, s[flagl].roll, s[flagl].cgpa);
    printf("\nThe student with the Lowest Marks is:\nName: %s\nRoll: %d\nCGPA: %.2f",
           s[flags].name, s[flags].roll, s[flags].cgpa);

    return 0;  
}
