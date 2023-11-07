#include <stdio.h>
#include <string.h>
#include <math.h>

void byIterative(int n,int *arr,int max){
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }printf("\nBy Iterative method Max is: %d",max);
    return;
}

void byRecursion(int n,int arr[],int max){
    if(n<0){
        printf("\nBy recursive method Max is: %d",max);
        return;
    }
    if(max<arr[n]){
        max=arr[n];
    }
    byRecursion(n-1,arr,max);
}

int main(){
    printf("\nEnter the numbers of elements: ");
    int n;
    scanf("%d",&n);
    int narr[n];
    printf("\nEnter the Elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&narr[i]);
    }int max=narr[0];
    byIterative(n,narr,max);
    
    byRecursion(n-1,narr,max);
    return 0;
}