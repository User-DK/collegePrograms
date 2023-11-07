#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Point{
    float x;
    float y;
    float result;
}p;

int main(){
    printf("Welcome");
    p p1[2];
    for(int i = 0; i <=1; i++){
        printf("\nEnter the Following details for Point %d", i+1);
        printf("\nX= ");
        scanf("%f",&p1[i].x);
        printf("\nY= ");
        scanf("%f",&p1[i].y);
    }
    
    for(int i = 0; i <=1; i++){
        printf("\nPoint%d (%.4f , %.4f)",i+1,p1[i].x,p1[i].y);
    }
    printf("\nThe Distance between points is: %.4f",(pow((pow(p1[1].x-p1[0].x,2)+pow(p1[1].y-p1[0].y,2)),0.5)));
    
    
    return 0;
}